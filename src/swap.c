/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 18:14:05 by jsobel            #+#    #+#             */
/*   Updated: 2019/03/13 18:14:07 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sa(t_push **a)
{
	ft_swap(a);
	if (*a && (*a)->next)
	{
		(*a)->count++;
		if ((*a)->display)
			ft_putendl("sa");
	}
	return (1);
}

int		sb(t_push **b)
{
	ft_swap(b);
	if (*b && (*b)->next)
	{
		(*b)->count++;
		if ((*b)->display)
			ft_putendl("sb");
	}
	return (1);
}

int		ss(t_push **a, t_push **b)
{
	ft_swap(a);
	ft_swap(b);
	if (*a && *b && (*a)->next && (*b)->next)
	{
		(*a)->count++;
		if ((*a)->display)
			ft_putendl("ss");
	}
	else if (*a && (*a)->next)
	{
		(*a)->count++;
		if ((*a)->display)
			ft_putendl("sa");
	}
	else if (*b && (*b)->next)
	{
		(*b)->count++;
		if ((*b)->display)
			ft_putendl("sb");
	}
	return (1);
}
