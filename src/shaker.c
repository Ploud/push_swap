/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shaker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 17:41:47 by jsobel            #+#    #+#             */
/*   Updated: 2018/06/15 17:02:16 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shake_it_all(t_push **a, t_push **b, int *count)
{
	while (*a && !(ft_is_sort_increasing(*a) && (!*b || (*a)->value > (*b)->value)))
	{
		if ((*a)->next && (*a)->value > (*a)->next->value && *b && (*b)->next && (*b)->value < (*b)->next->value)
			ss(a, b);
		else if ((*a)->next && (*a)->value > (*a)->next->value)
			sa(a);
		else if (*b && (*b)->next && (*b)->value < (*b)->next->value)
			sb(b);
		else
			pb(a, b);
		(*count)++;
	}
	while (*b && !(ft_is_sort_decreasing(*b) && (!*a || (*a)->value > (*b)->value)))
	{
		if (*a && (*a)->next && (*a)->value > (*a)->next->value && (*b)->next && (*b)->value < (*b)->next->value)
			ss(a, b);
		else if (*a && (*a)->next && (*a)->value > (*a)->next->value)
			sa(a);
		else if ((*b)->next && (*b)->value < (*b)->next->value)
			sb(b);
		else
			pa(a, b);
		(*count)++;
	}
	if (!check(a, b, count))
		shake_it_all(a, b, count);
}

int		divide_to_conquer(t_push **a, t_push **b, int med, int *c)
{
	int		flag;
	t_push	*tmp;

	flag = 1;
	while (flag)
	{
		if (check(a, b, c))
			return (1);
		flag = 0;
		if ((*a)->value <= med)
			pb(a, b);
		else
			ra(a);
		tmp = *a;
		while (tmp)
		{
			if (tmp->value <= med)
				flag = 1;
			tmp = tmp->next;
		}
		(*c)++;
	}
	return (0);
}

int		ft_shaker(t_push **a, t_push **b)
{
	int count;
	int i;
	int med;
	int	nb;

	count = 0;
	i = 1;
	nb = get_len(*a);
	while (nb >= 4)
	{
		med = get_mediane(*a, nb / 4);
		if (divide_to_conquer(a, b, med, &count))
			return (count);
		nb = get_len(*a);
	}
	shake_it_all(a, b, &count);
	return (count);
}
