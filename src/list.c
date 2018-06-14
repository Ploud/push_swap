/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julienso <julienso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 17:52:13 by julienso          #+#    #+#             */
/*   Updated: 2018/06/12 17:52:47 by juliensobel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_free_list(t_push **begin_list)
{
	t_push *delete;
	t_push *tmp;

	tmp = *begin_list;
	while (tmp)
	{
		delete = tmp;
		tmp = tmp->next;
		free(delete);
	}
	free(tmp);
	*begin_list = NULL;
}

int		ft_valid_list(t_push *p)
{
	t_push *c;

	c = p;
	while (c->next)
	{
		c = c->next;
		if (c->value == p->value)
			return (0);
	}
	if (!p->next || (p->next && ft_valid_list(p->next)))
		return (1);
	else
		return (0);
}

t_push	*ft_creat_list(int argc, char **argv)
{
	t_push *p;

	p = NULL;
	if (argc > 0)
	{
		if (!(p = malloc(sizeof(t_push))))
			return (NULL);
		p->value = ft_atoi(argv[0]);
		p->next = ft_creat_list(argc - 1, &argv[1]);
	}
	return (p);
}
