/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 18:21:09 by jsobel            #+#    #+#             */
/*   Updated: 2019/03/13 18:46:45 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_reverse_rotate(t_push **p)
{
	t_push *tmp;

	if (*p)
	{
		tmp = (*p);
		while (tmp->next && tmp->next->next)
		{
			tmp = tmp->next;
		}
		if (tmp->next)
		{
			tmp->next->next = *p;
			*p = tmp->next;
			tmp->next = NULL;
		}
	}
	return (1);
}

int		ft_rotate(t_push **p)
{
	t_push *tmp;

	if (*p)
	{
		tmp = (*p);
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = *p;
		*p = (*p)->next;
		tmp->next->next = NULL;
	}
	return (1);
}

void	ft_push(t_push **p1, t_push **p2)
{
	t_push *tmp;

	if (*p2)
	{
		tmp = (*p2)->next;
		(*p2)->next = *p1;
		*p1 = *p2;
		*p2 = tmp;
	}
}

int		ft_swap(t_push **p)
{
	t_push *tmp;

	if (*p && (*p)->next)
	{
		tmp = (*p)->next;
		(*p)->next = (*p)->next->next;
		tmp->next = (*p);
		(*p) = tmp;
	}
	return (1);
}

int		ft_check_op(char *op, t_push **a, t_push **b)
{
	if (!ft_strcmp(op, "sa"))
		ft_swap(a);
	else if (!ft_strcmp(op, "sb"))
		ft_swap(b);
	else if (!ft_strcmp(op, "ss") && ft_swap(a))
		ft_swap(b);
	else if (!ft_strcmp(op, "pa"))
		ft_push(a, b);
	else if (!ft_strcmp(op, "pb"))
		ft_push(b, a);
	else if (!ft_strcmp(op, "ra"))
		ft_rotate(a);
	else if (!ft_strcmp(op, "rb"))
		ft_rotate(b);
	else if (!ft_strcmp(op, "rr") && ft_rotate(a))
		ft_rotate(b);
	else if (!ft_strcmp(op, "rra"))
		ft_reverse_rotate(a);
	else if (!ft_strcmp(op, "rrb"))
		ft_reverse_rotate(b);
	else if (!ft_strcmp(op, "rrr") && ft_reverse_rotate(a))
		ft_reverse_rotate(b);
	else
		return (0);
	return (1);
}
