/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_case.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 14:23:52 by jsobel            #+#    #+#             */
/*   Updated: 2018/06/22 18:31:51 by juliensobel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	end_reverse(t_push **a, t_push **b)
{
	(void)a;
	(void)b;
}

void	simple_case(t_push **a, t_push **b)
{
	int len;

	len = get_len(*a);
	(void)b;
	while (*a && (*a)->next && len)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a);
		len--;
		if (ft_is_sort_increasing(*a))
			return ;
		else
			ra(a);
	}
	(*a)->count = -1;
}
