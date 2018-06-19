/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:23:26 by lucien            #+#    #+#             */
/*   Updated: 2018/06/19 20:27:31 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_push **a, t_push **b)
{
	ft_push(a, b);
	if (*a)
	{
		(*a)->count++;
		if ((*a)->display)
			ft_putendl("pa");
	}
}

void	pb(t_push **b, t_push **a)
{
	ft_push(a, b);
	if (*a)
	{
		(*a)->count++;
		if ((*a)->display)
			ft_putendl("pb");
	}
}
