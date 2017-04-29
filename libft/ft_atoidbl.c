/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoidbl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 23:56:41 by tbillard          #+#    #+#             */
/*   Updated: 2016/06/19 20:12:01 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_char(const char *str)
{
	int		i;

	i = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\r' ||
	str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
	{
		i++;
	}
	if (str[i] == '+' && ft_isdigit(str[i + 1]) != 0)
		i++;
	return (i);
}

float			ft_atoidbl(const char *str)
{
	int		i;
	float	ret;
	int		neg;

	i = ft_char(str);
	neg = 0;
	ret = 0;
	if (str[i] == '-' && ft_isdigit(str[i + 1]) != 0)
	{
		neg++;
		i++;
	}
	while (ft_isdigit(str[i]) != 0)
	{
		ret = ret * 10;
		ret = ret + (str[i] - 48);
		i++;
	}
	return (neg == 1 ? -ret : ret);
}
