/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:41:13 by tbillard          #+#    #+#             */
/*   Updated: 2016/01/04 14:37:38 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	const char		*src1;
	char			*dst1;
	char			tmp[len];

	i = 0;
	src1 = src;
	dst1 = dst;
	while (i < len)
	{
		tmp[i] = src1[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		dst1[i] = tmp[i];
		i++;
	}
	return (dst);
}
