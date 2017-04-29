#include <libft.h>
#include <stdio.h>
#include <math.h>

/*
 * this function creat real mask from `/b`
 * a mask is build with 4 8 bits numbers
 * 8 full bits (11111111) = 255
 */

static int			*get_mask(int mask)
{
	int *full_mask = (int*)ft_memalloc(sizeof(int) * 4);
	int mask_off = 0;

	while (mask > 0)
	{
		if (mask >= 8)
		{
			full_mask[mask_off] = 255;
			mask -= 8;
		}
		else
		{
			while (mask > 0)
			{
				full_mask[mask_off] = full_mask[mask_off] | (1 << (8 - mask));
				--mask;
			}
		}
		++mask_off;
	}
	return (full_mask);
}

static void		print_ip(char **ip)
{
	int i = 0;

	while (i < 3)
		printf("%s.", ip[i++]);
	printf("%s", ip[i]);
}

static void conc_ip(char **ip, char **ret_ip)
{
	ft_bzero(*ret_ip, 15);
	int  i =0;
	while (i < 3)
	{
		*ret_ip = ft_strcat(*ret_ip, ip[i++]);
		*ret_ip = ft_strcat(*ret_ip, ".");
	}
	*ret_ip = ft_strcat(*ret_ip, ip[i]);
}

static void		get_next_ip(char ***ip)
{
	int i = 3;

	while (i >= 0)
	{
		if (ft_atoi((*ip)[i]) != 255)
		{
			(*ip)[i] = ft_itoa(ft_atoi((*ip)[i]) + 1);
			break ;
		}
		else
			(*ip)[i] = ft_itoa(0);
		--i;
	}
}

static void	print_result(int ret, int i, char **ip, int v)
{
	if (ret == 0)
	{
		printf("\x1b[32m");
		print_ip(ip);
		printf(" respond correctly\n");
	}
	else if (v == 1)
	{
		printf("\x1b[31m");
		print_ip(ip);
		if (i > 0)
			printf(" not responding, let retry!\n");
		else
			printf(" not responding, an error occur, check it!!!\n");
	}
	printf("\x1b[0m");
}

static char 	**cp_ip(char **ip)
{
	char **ip2 = (char**)ft_memalloc(sizeof(char*) * 5);
	int i = 0;

	while (ip[i])
	{
		ip2[i] = ft_strdup(ip[i]);
		i++;
	}
	ip2[i] = NULL;
	return (ip2);
}

static void print_stat(char **ip, char **ip2, int *mask)
{
	printf("Hostmin: ");
	print_ip(ip2);
	printf("\nHostmax: ");
	print_ip(ip);
	printf("\nMask: %d.%d.%d.%d\n", mask[0], mask[1], mask[2], mask[3]);
}

static void		main_loop(int nb_ip, int limit, char **ip, char *prefix, char *ent_ip, int v)
{
    int i = 0;
    char *command;
    int s_nb_ip = nb_ip;

	while (nb_ip > 0)
	{
		int ret = 42;
		int j = 1;
		int pid;

		if (i >= limit) //wait previous fork before fork again
		{
			printf("%d ip pinged, current:", s_nb_ip - nb_ip);
			print_ip(ip);
			printf("\n");
			while (i && limit - i-- <  nb_ip + 2)
				wait(NULL);
			++i;
		}

		pid = fork();

        if (pid < 0) // if fork fail, try again
		{
			perror("_fork: ");
			continue ;
		}

		i++;

        if (!pid) //if it's the child
        {
			conc_ip(ip, &ent_ip); // concat the char** ip into a char*
			command = ft_strjoin(ft_strjoin(prefix, ent_ip), " >/dev/null 2>&1"); // TODO fix leaks

            while (ret != 0 && j-- > 0) // try to ping the same ip `j` times
			{
				ret = system(command);
				print_result(ret, j, ip, v);
			}
			free(command);
			exit(0);
		}

        usleep(10000); // wait a litle for get the result in order

        get_next_ip(&ip);
        nb_ip--;
	}
    while (i--)
        wait(NULL); // wait all fork terminate
}

int main (int argc, char ** argv)
{
	char	        **ip;
    char	        **ip_min;
    int		        mask = ft_atoi(ft_strdup(ft_strchr(argv[1], '/') + 1)); // get the mask (example: `/24`)
	int		        *full_mask = get_mask(mask); //convert to real mask (example: 255.255.255.0)
	int		        nb_ip = (int)pow(2, 32 - mask); // calc number of ip
	char	        *prefix	= "ping -c 1 -w 1 "; // begin of the shell command
	char	        *ent_ip	= (char*)ft_memalloc(sizeof(char) * 16);
	struct rlimit   rlp;
	int		        limit;
    int             v;
    int		        i = 0;

    if (argc > 2)
        v = (!(ft_strcmp(argv[2], "-v")) ? 1 : 2); // check for -v : verbose
	else
        v = 0;
    argv[1] = ft_strrevchr(argv[1], '/'); // delete the mask, keep only the full ip
	ip = ft_strsplit(argv[1], '.'); // split ip into 4 char * into 1 char**

    while (i < 4)
	{
		ip[i] = ft_itoa(ft_atoi(ip[i]) & full_mask[i]); // apply the mask on the ip
		++i;
	}

    ip_min = cp_ip(ip); // keep the first ip

    printf("going to ping %d ip\n", nb_ip);

    // set the fork limit to the max
	getrlimit(RLIMIT_NPROC, &rlp);
	rlp.rlim_cur = rlp.rlim_max;
	setrlimit(RLIMIT_NPROC, &rlp);
	limit = (int)(rlp.rlim_cur < 256 ? rlp.rlim_cur : 256); // set the limit of fork to 256 or to the computer limit

    main_loop(nb_ip, limit, ip, prefix, ent_ip, v); // do all the things

    print_stat(ip, ip_min, full_mask);
    return (0);
}