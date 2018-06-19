/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 15:00:30 by lucien            #+#    #+#             */
/*   Updated: 2018/06/19 20:29:44 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		rra(t_push **a)
{
	ft_reverse_rotate(a);
	if (*a)
	{
		(*a)->count++;
		if ((*a)->display)
			ft_putendl("rra");
	}
	return (1);
}

int		rrb(t_push **b)
{
	ft_reverse_rotate(b);
	if (*b)
	{
		(*b)->count++;
		if ((*b)->display)
			ft_putendl("rrb");
	}
	return (1);
}

int		rrr(t_push **a, t_push **b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	if (*a)
	{
		(*a)->count++;
		if ((*a)->display)
			ft_putendl("rrr");
	}
	else if (*b)
	{
		(*b)->count++;
		if ((*b)->display)
			ft_putendl("rrr");
	}
	return (1);
}
