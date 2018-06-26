/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 00:12:58 by lucien            #+#    #+#             */
/*   Updated: 2018/06/26 17:46:26 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_distri_pyramid(t_push **a, t_push **b)
{
	int		div_mediane;
	int		len;

	len = get_len(*a);
	div_mediane = len / 100 + 3;
	while (len >= div_mediane)
	{
		if ((*a)->value <= get_mediane(*a, len / div_mediane / 2))
		{
			pb(a, b);
			rb(b);
		}
		else if ((*a)->value <= get_mediane(*a, len / div_mediane))
			pb(a, b);
		else
			ra(a);
		len = get_len(*a);
	}
	if (len < SMALL_SIZE)
		sort_3less_int(a, len, get_min(*a), get_max(*a));
	else if (len < MEDIUM_SIZE)
		basic_selective_sort(a, b, len);
	else if (!ft_sort(a, b))
		process_distri_pyramid(a, b);
}

void	process_selec_sort_opti(t_push **a, t_push **b)
{
	int		max;
	int		max2;
	int		p_intmax;
	int		ret;

	ret = 0;
	while ((*b) != NULL)
	{
		max = get_max(*b);
		if ((*b)->value == (max2 = opti_get_max_moins_un(b, max)))
		{
			pa(a, b);
			ret++;
		}
		else if ((*b)->value == max)
		{
			opti_place_ints_max(a, b, ret);
			ret = 0;
		}
		else if ((p_intmax = get_position_int(*b, max)) > get_len(*b) / 2)
			rrb(b);
		else
			rb(b);
	}
}

int		where_is_next(t_push *a, int mediane)
{
	t_push	*tmp;
	t_push	*start;
	int		len;
	int		i;

	len = get_len(a);
	tmp = a;
	start = a;
	while (a->value > mediane && tmp->value > mediane)
	{
		i = 1;
		tmp = start;
		a = a->next;
		while (i < len)
		{
			tmp = tmp->next;
			i++;
		}
		len--;
	}
	if (a->value <= mediane)
		return (1);
	return (0);
}

int		opti_get_max_moins_un(t_push **a, int max_b)
{
	t_push	*tmp;
	int		int_max;

	int_max = -2147483648;
	tmp = (*a);
	while (tmp != NULL)
	{
		if (int_max < tmp->value && tmp->value < max_b)
			int_max = tmp->value;
		tmp = tmp->next;
	}
	return (int_max);
}

void	opti_place_ints_max(t_push **a, t_push **b, int ret)
{
	int ret2;

	ret2 = ret;
	if (ret == 0)
		pa(a, b);
	else if (ret == 1)
	{
		pa(a, b);
		sa(a);
	}
	else if (ret > 1)
	{
		while (ret > 0)
		{
			ra(a);
			ret--;
		}
		pa(a, b);
		while (ret2 > 0)
		{
			rra(a);
			ret2--;
		}
	}
}
