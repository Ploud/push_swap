/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 18:12:47 by jsobel            #+#    #+#             */
/*   Updated: 2019/03/13 18:13:00 by jsobel           ###   ########.fr       */
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
