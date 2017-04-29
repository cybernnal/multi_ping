/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrevchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 17:54:29 by tbillard          #+#    #+#             */
/*   Updated: 2016/01/20 18:07:10 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrevchr(char *s, int c)
{
	int		i;
	char	*str;

	str = NULL;
	i = 0;
	if (!s || !*s)
		return (NULL);
	str = (char*)malloc(sizeof(char) * ((ft_strlen(s) + 1)));
	if (!str)
		return (NULL);
	ft_bzero(str, ft_strlen(s));
	while (s[i] != '\0' && s[i] != (char)c)
	{
		str[i] = s[i];
		i++;
	}
	str[i + 1] = '\0';
	return (str);
}
