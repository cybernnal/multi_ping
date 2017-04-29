/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:25:54 by tbillard          #+#    #+#             */
/*   Updated: 2015/11/27 16:45:06 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	const char		*srcbis;
	char			*dstbis;

	i = 0;
	srcbis = src;
	dstbis = dst;
	while (i < n)
	{
		dstbis[i] = srcbis[i];
		i++;
	}
	return (dst);
}
