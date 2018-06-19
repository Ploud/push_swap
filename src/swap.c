/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:37:48 by lucien            #+#    #+#             */
/*   Updated: 2018/06/19 20:32:46 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sa(t_push **a)
{
	ft_swap(a);
	if (*a)
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
	if (*b)
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
	if (*a)
	{
		(*a)->count++;
		if ((*a)->display)
			ft_putendl("ss");
	}
	else if (*b)
	{
		(*b)->count++;
		if ((*b)->display)
			ft_putendl("ss");
	}
	return (1);
}
