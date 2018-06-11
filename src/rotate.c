/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:27:58 by lucien            #+#    #+#             */
/*   Updated: 2018/06/10 20:20:44 by lucien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ra(t_push **a)
{
	t_push	*tmp;

	tmp = (*a);
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = *a;
	*a = (*a)->next;
	tmp->next->next = NULL;
	ft_putendl("ra");
	return (1);
}

int		rb(t_push **b)
{
	t_push	*tmp;

	tmp = (*b);
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = *b;
	*b = (*b)->next;
	tmp->next->next = NULL;
	ft_putendl("rb");
	return (1);
}

int		rr(t_push **a, t_push **b)
{
	t_push	*tmp;
	t_push	*tmp2;

	tmp = (*a);
	tmp2 = (*b);
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = *a;
	*a = (*a)->next;
	tmp->next->next = NULL;
	while (tmp2->next)
	{
		tmp2 = tmp2->next;
	}
	tmp2->next = *b;
	*b = (*b)->next;
	tmp2->next->next = NULL;
	ft_putendl("rr");
	return (1);
}
