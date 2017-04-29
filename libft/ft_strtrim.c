/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:22:18 by tbillard          #+#    #+#             */
/*   Updated: 2016/01/04 16:14:27 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_none(char c)
{
	if (c == '\n' || c == '\t' || c == ' ')
		return (1);
	return (0);
}

char			*ft_strtrim(const char *s)
{
	char		*str;
	int			i;
	size_t		l;

	l = 0;
	if (s != NULL)
	{
		while (ft_none(*s) != 0)
			s++;
		while (s[l++] != '\0')
		{
			i = 0;
			while (ft_none(s[i + l]) != 0)
				i++;
			if (i > 0 && s[i + l] == '\0')
				break ;
			else if (i > 0)
				l = l + i;
		}
		if (!(str = ft_strnew(l)))
			return (0);
		ft_memcpy(str, s, l);
		return (str);
	}
	return (0);
}
