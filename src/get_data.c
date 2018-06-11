/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 01:13:24 by lucien            #+#    #+#             */
/*   Updated: 2018/06/10 15:14:12 by lucien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			get_min(t_push **a)
{
	t_push	*tmp;
	int		int_min;

	tmp = (*a);
	int_min = 2147483647;
	while (tmp != NULL)
	{
		if (int_min > tmp->value)
			int_min = tmp->value;
		tmp = tmp->next;
	}
	return (int_min);
}

int			get_max(t_push **a)
{
	t_push	*tmp;
	int		int_max;

	int_max = 0;
	tmp = (*a);
	while (tmp != NULL)
	{
		if (int_max < tmp->value)
			int_max = tmp->value;
		tmp = tmp->next;
	}
	return (int_max);
}

int			get_len(t_push **a)
{
	t_push	*tmp;
	int		len;

	len = 0;
	tmp = (*a);
	while (tmp != NULL)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

int			get_position_int(t_push **a, int nb)
{
	t_push	*tmp;
	int		position;

	position = 0;
	tmp = (*a);
	while (tmp != NULL && tmp->value != (nb))
	{
		tmp = tmp->next;
		position++;
	}
	return (position);
}

int			get_mediane(t_push **a, int len)
{
	t_push	*tmp;
	int		int_min;
	int		mediane;

	mediane = 0;
	tmp = (*a);
	while (len > 0)
	{
		tmp = (*a);
		int_min = 2147483647;
		while (tmp != NULL)
		{
			if (int_min > tmp->value && tmp->value > mediane)
				int_min = tmp->value;
			tmp = tmp->next;
		}
		mediane = int_min;
		len--;
	}
	return (mediane);
}
