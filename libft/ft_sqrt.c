/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:29:43 by tbillard          #+#    #+#             */
/*   Updated: 2016/03/12 16:27:33 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static double	pdix(double i)
{
	double j;

	j = 0;
	while (i != 0)
	{
		i /= 10;
		j++;
	}
	return (j * 100);
}

double			ft_sqrt(double i)
{
	double	sqrt;
	double	sqrtmp;
	double	ibis;

	sqrtmp = 0;
	if (i > 0)
	{
		ibis = i;
		sqrt = pdix(i);
		if (i == 0)
		{
			sqrt = 0;
			sqrtmp = 0;
		}
		while (sqrt != sqrtmp)
		{
			sqrtmp = sqrt;
			sqrt = ((0.5) * (sqrt + (ibis / sqrtmp)));
		}
		return (sqrt);
	}
	return (0);
}
