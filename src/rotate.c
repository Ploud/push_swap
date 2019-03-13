/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 18:13:46 by jsobel            #+#    #+#             */
/*   Updated: 2019/03/13 18:13:48 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ra(t_push **a)
{
	ft_rotate(a);
	if (*a && (*a)->next)
	{
		(*a)->count++;
		if ((*a)->display)
			ft_putendl("ra");
	}
	return (1);
}

int		rb(t_push **b)
{
	ft_rotate(b);
	if (*b && (*b)->next)
	{
		(*b)->count++;
		if ((*b)->display)
			ft_putendl("rb");
	}
	return (1);
}

int		rr(t_push **a, t_push **b)
{
	ft_rotate(a);
	ft_rotate(b);
	if (*a && *b && (*a)->next && (*b)->next)
	{
		(*a)->count++;
		if ((*a)->display)
			ft_putendl("rr");
	}
	else if (*a && (*a)->next)
	{
		(*a)->count++;
		if ((*a)->display)
			ft_putendl("ra");
	}
	else if (*b && (*b)->next)
	{
		(*b)->count++;
		if ((*b)->display)
			ft_putendl("rb");
	}
	return (1);
}
