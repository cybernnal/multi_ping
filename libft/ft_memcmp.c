/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:39:38 by tbillard          #+#    #+#             */
/*   Updated: 2015/11/24 16:58:56 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*s12;
	unsigned char	*s22;

	i = 0;
	s12 = (unsigned char*)s1;
	s22 = (unsigned char*)s2;
	while (i < n)
	{
		if (s12[i] != s22[i])
			return (s12[i] - s22[i]);
		i++;
	}
	return (0);
}
