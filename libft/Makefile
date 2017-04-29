#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/19 18:35:47 by cglavieu          #+#    #+#              #
#    Updated: 2016/06/19 19:58:48 by tbillard         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc

CFLAG = -Wall -Werror -Wextra

NAME = libft.a

SRC = ft_atoi.c\
	ft_atoidbl.c\
	ft_bzero.c\
	ft_isalnum.c\
	ft_isalpha.c\
	ft_isascii.c\
	ft_isdigit.c\
	ft_isprint.c\
	ft_itoa.c\
	ft_memalloc.c\
	ft_memccpy.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_memcpy.c\
	ft_memdel.c\
	ft_memmove.c\
	ft_memset.c\
	ft_putchar.c\
	ft_putchar_fd.c\
	ft_putendl.c\
	ft_putendl_fd.c\
	ft_putnbr.c\
	ft_putnbr_fd.c\
	ft_putstr.c\
	ft_putstr_fd.c\
	ft_strcat.c\
	ft_strchr.c\
	ft_strclr.c\
	ft_strcmp.c\
	ft_strcpy.c\
	ft_strdel.c\
	ft_strdup.c\
	ft_strequ.c\
	ft_striter.c\
	ft_striteri.c\
	ft_strjoin.c\
	ft_strlcat.c\
	ft_strlen.c\
	ft_strmap.c\
	ft_strmapi.c\
	ft_strncat.c\
	ft_strncmp.c\
	ft_strncpy.c\
	ft_strnequ.c\
	ft_strnew.c\
	ft_strnstr.c\
	ft_strrchr.c\
	ft_strsplit.c\
	ft_strstr.c\
	ft_strsub.c\
	ft_strtrim.c\
	ft_tolower.c\
	ft_toupper.c\
	ft_lstadd.c\
	ft_strrevchr.c\
	ft_strdupnfree.c\
	ft_printlst.c\
	ft_print_tab.c\
	ft_countchiffres.c\
	ft_freetab.c\
	ft_nbword.c\
	ft_sqrt.c\
	get_next_line.c\

SRCDIR = ./
SRCFILL = $(addprefix $(SRCDIR),$(SRC))

OBJ = $(SRC:.c=.o)
OBJDIR = ./obj/
OBJFILL = $(addprefix $(OBJDIR),$(OBJ))

INC = ./

all: 		$(NAME)

$(NAME): 	$(OBJFILL)
			@ar rc $@ $^

$(OBJDIR)%.o:	$(SRCDIR)%.c
			@mkdir -p $(OBJDIR)
			@$(CC) $(CFLAG) -I $(INC) -c $< -o $@

clean:
			@rm -rf $(OBJDIR)

fclean:		clean
			@rm -f $(NAME)

re: 		fclean all
