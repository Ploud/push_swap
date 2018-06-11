/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:37:48 by lucien            #+#    #+#             */
/*   Updated: 2018/06/10 20:21:01 by lucien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sa(t_push **a)
{
	t_push	*tmp;

	if (*a && (*a)->next)
	{
		tmp = (*a)->next;
		(*a)->next = (*a)->next->next;
		tmp->next = (*a);
		(*a) = tmp;
	}
	ft_putendl("sa");
	return (1);
}

int		sb(t_push **b)
{
	t_push	*tmp;

	if (*b && (*b)->next)
	{
		tmp = (*b)->next;
		(*b)->next = (*b)->next->next;
		tmp->next = (*b);
		(*b) = tmp;
	}
	ft_putendl("sb");
	return (1);
}

int		ss(t_push **a, t_push **b)
{
	t_push *tmp;
	t_push *tmp2;

	if (*a && (*a)->next)
	{
		tmp = (*a)->next;
		(*a)->next = (*a)->next->next;
		tmp->next = (*a);
		(*a) = tmp;
	}
	if (*b && (*b)->next)
	{
		tmp2 = (*b)->next;
		(*b)->next = (*b)->next->next;
		tmp2->next = (*b);
		(*b) = tmp2;
	}
	ft_putendl("ss");
	return (1);
}
