/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:23:26 by lucien            #+#    #+#             */
/*   Updated: 2018/06/10 20:20:11 by lucien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_push **a, t_push **b)
{
	t_push	*tmp;

	if (*b)
	{
		tmp = (*b)->next;
		(*b)->next = *a;
		*a = *b;
		*b = tmp;
	}
	ft_putendl("pa");
}

void	pb(t_push **b, t_push **a)
{
	t_push	*tmp;

	if (*b)
	{
		tmp = (*b)->next;
		(*b)->next = *a;
		*a = *b;
		*b = tmp;
	}
	ft_putendl("pb");
}
