/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_case.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 14:23:52 by jsobel            #+#    #+#             */
/*   Updated: 2018/06/25 17:20:37 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	end_reverse(t_push **a, t_push **b)
{
	int len;
	int flag;

	len = get_len(*a);
	flag = 1;
	(void)b;
	rra(a);
	rra(a);
	len *= 2;
	while (*a && (*a)->next && len)
	{
		if ((*a)->value > (*a)->next->value && flag)
		{
			sa(a);
			flag = 0;
		}
		if (ft_is_sort_increasing(*a))
			return ;
		else if (flag)
			rra(a);
		else
			ra(a);
		len--;
	}
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
}
