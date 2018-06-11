/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 15:00:30 by lucien            #+#    #+#             */
/*   Updated: 2018/06/10 20:20:29 by lucien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		rra(t_push **a)
{
	t_push	*tmp;

	tmp = (*a);
	while (tmp->next && tmp->next->next)
	{
		tmp = tmp->next;
	}
	tmp->next->next = *a;
	*a = tmp->next;
	tmp->next = NULL;
	ft_putendl("rra");
	return (1);
}

int		rrb(t_push **b)
{
	t_push	*tmp;

	tmp = (*b);
	while (tmp->next && tmp->next->next)
	{
		tmp = tmp->next;
	}
	tmp->next->next = *b;
	*b = tmp->next;
	tmp->next = NULL;
	ft_putendl("rrb");
	return (1);
}

int		rrr(t_push **a, t_push **b)
{
	t_push	*tmp;
	t_push	*tmp2;

	tmp = (*a);
	tmp2 = (*b);
	while (tmp->next && tmp->next->next)
	{
		tmp = tmp->next;
	}
	tmp->next->next = *a;
	*a = tmp->next;
	tmp->next = NULL;
	while (tmp2->next && tmp2->next->next)
	{
		tmp2 = tmp2->next;
	}
	tmp2->next->next = *b;
	*b = tmp2->next;
	tmp2->next = NULL;
	ft_putendl("rrr");
	return (1);
}
