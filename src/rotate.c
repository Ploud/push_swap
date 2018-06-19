/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:27:58 by lucien            #+#    #+#             */
/*   Updated: 2018/06/19 20:31:33 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ra(t_push **a)
{
	ft_rotate(a);
	if (*a)
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
	if (*b)
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
	if (*a)
	{
		(*a)->count++;
		if ((*a)->display)
			ft_putendl("rr");
	}
	else if (*b)
	{
		(*b)->count++;
		if ((*b)->display)
			ft_putendl("rr");
	}
	return (1);
}
