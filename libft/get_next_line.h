/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 15:54:14 by tbillard          #+#    #+#             */
/*   Updated: 2016/03/12 16:28:03 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 4096
# define EOF (-1)

# include "libft.h"
# include <unistd.h>
# include <fcntl.h>

/*
** For change color, change the define.
** Diferent color
** white:	\x1b[0m
** green:	\x1b[32m
** red:		\x1b[31m
** purple: 	\x1b[35m
*/

# define ACTIV_COLOR 0
# define COLOR "\x1b[0m"

int		get_next_line(int const fd, char **line);
#endif
