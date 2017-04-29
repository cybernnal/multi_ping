make -C libft/ ; gcc -o mping ping_ip.c -I./libft/ libft/libft.a -Ofast -march=native
