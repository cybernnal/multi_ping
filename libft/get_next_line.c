	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:41:59 by tbillard          #+#    #+#             */
/*   Updated: 2016/02/02 15:49:45 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_bonus(int i, char *line)
{
	if (ACTIV_COLOR == 1)
		ft_putstr(COLOR);
	if (i < 0)
		return (-1);
	if (i == 0 && !*line)
		return (0);
	return (1);
}

static int	ft_read(char **tmp, char **buff, char **tmpb, int fd)
{
	int i;

	i = 1;
	while ((i > 0) && !ft_strchr(*tmp, '\n'))
	{
		free(*tmp);
		i = (int)((!*buff) ? read(fd, *buff, BUFF_SIZE) :
				   read(fd, *buff, (BUFF_SIZE - ft_strlen(*buff))));
		(*buff)[i] = '\0';
		if (i < 0)
		{
			if (**tmpb)
				free(*tmpb);
			return (i);
		}
		if (i > 0)
		{
			*tmp = *tmpb;
			*tmpb = ft_strjoin(*tmpb, *buff);
			free(*tmp);
			*tmp = ft_strdup(*buff);
			ft_bzero(*buff, BUFF_SIZE);
		}
	}
	return (i);
}

int			ft_read_line(int fd, char **str, char *buff, char **tmpbuf)
{
	int		i;
	char	*tmp;
	char	*tmpb;

	i = 1;
	tmp = ft_strdup(buff);
	tmpb = ft_strdup(buff);
	i = ft_read(&tmp, &buff, &tmpb, fd);
	if (i > 0)
	{
		*tmpbuf = ft_strdup(ft_strchr(tmp, '\n') + 1);
		free(tmp);
	}
	else
		ft_bzero(*tmpbuf, ft_strlen(*tmpbuf));
	tmp = tmpb;
	if (ft_strchr(tmpb, '\n'))
		tmpb = ft_strrevchr(tmpb, '\n');
	*str = ft_strdup(tmpb);
	if (i > 0)
		free(tmpb);
	free(tmp);
	return (i);
}

int			get_next_line(int fd, char **line)
{
	char		*str;
	char		*tmpbuf;
	static char	buff[512][BUFF_SIZE + 1];
	int			i;
	int			j;

	if (fd < 0 || fd > 511 || !line || BUFF_SIZE <= 0)
		return (-1);
	j = 0;
	tmpbuf = NULL;
	str = NULL;
	i = ft_read_line(fd, &str, buff[fd], &tmpbuf);
	ft_bzero(buff[fd], BUFF_SIZE);
	if (i >= 0)
		while (i > 0 && tmpbuf[j])
		{
			buff[fd][j] = tmpbuf[j];
			j++;
		}
	*line = ft_strdup(str);
	free(str);
	free(tmpbuf);
	return (ft_bonus(i, *line));
}
