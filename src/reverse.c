/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 18:13:27 by jsobel            #+#    #+#             */
/*   Updated: 2019/03/13 18:13:28 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		rra(t_push **a)
{
	ft_reverse_rotate(a);
	if (*a && (*a)->next)
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
	if (*b && (*b)->next)
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
	if (*a && *b && (*a)->next && (*b)->next)
	{
		(*a)->count++;
		if ((*a)->display)
			ft_putendl("rrr");
	}
	else if (*a && (*a)->next)
	{
		(*a)->count++;
		if ((*a)->display)
			ft_putendl("rra");
	}
	else if (*b && (*b)->next)
	{
		(*b)->count++;
		if ((*b)->display)
			ft_putendl("rrb");
	}
	return (1);
}
