/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 14:55:15 by tbillard          #+#    #+#             */
/*   Updated: 2016/02/06 15:38:58 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include "../fillit.h"

void		ft_printlst(t_list *list)
{
	if (list)
	{
		while (list)
		{
			ft_putstr(list->content);
			list = list->next;
			if (list)
				write(1, "\n", 1);
		}
	}
}
