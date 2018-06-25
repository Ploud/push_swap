/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_shaker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 17:46:20 by jsobel            #+#    #+#             */
/*   Updated: 2018/06/25 17:51:31 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shake_it_all(t_push **a, t_push **b)
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
	}
	if (!check(a, b))
		shake_it_all(a, b);
}

int		divide_to_conquer(t_push **a, t_push **b, int med)
{
	int		flag;
	t_push	*tmp;

	flag = 1;
	while (flag)
	{
		if (check(a, b))
			return (1);
		flag = 0;
		/*if ((*a)->value <= med / 2)
		{
			pb(a, b);
			rrb(b);
		}
		else*/ if ((*a)->value <= med)
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
	}
	return (0);
}

void		ft_shaker(t_push **a, t_push **b)
{
	int	i;
	int	med;
	int	nb;
	int	diviseur;

	i = 1;
	nb = get_len(*a);
	diviseur = nb / 100 + 3;
	while (nb >= diviseur)
	{
		med = get_mediane(*a, nb / diviseur);
		if (divide_to_conquer(a, b, med))
			return ;
		nb = get_len(*a);
	}
	shake_it_all(a, b);
}