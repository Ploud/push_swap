/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 18:14:53 by jsobel            #+#    #+#             */
/*   Updated: 2018/06/14 17:09:33 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				ft_is_sort_increasing(t_push *p)
{
	while (p && p->next)
	{
		if (p->value > p->next->value)
			return (0);
		p = p->next;
	}
	return (1);
}

int				ft_is_sort_decreasing(t_push *p)
{
	while (p && p->next)
	{
		if (p->value < p->next->value)
			return (0);
		p = p->next;
	}
	return (1);
}

int		check(t_push **a, t_push **b, int *count)
{
	if (ft_is_sort_increasing(*a) && ft_is_sort_decreasing(*b)
	&& (!*a || !*b || (*a)->value > (*b)->value))
	{
		while (*b)
		{
			pa(a, b);
			(*count)++;
		}
		return (1);
	}
	else
		return (0);
}
