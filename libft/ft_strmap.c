/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <tbillard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 11:45:41 by tbillard          #+#    #+#             */
/*   Updated: 2016/01/04 14:54:06 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*dest;
	int		i;

	i = 0;
	if (s && f)
	{
		dest = ft_strnew(ft_strlen(s));
		if (!dest)
			return (0);
		while (s[i])
		{
			dest[i] = f(s[i]);
			i++;
		}
		return (dest);
	}
	return (0);
}
