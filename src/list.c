/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julienso <julienso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 17:52:13 by julienso          #+#    #+#             */
/*   Updated: 2018/06/19 20:33:20 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_list(t_push **begin_list)
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

int		ft_bigger_than_integer(char *p, int value, int i)
{
	if (((value > 0 || i > 11) && p[0] == '-') ||
	(value % 10) != (p[i] - 48) ||
	((value < 0 || i > 10) && p[0] != '-'))
		return (1);
	return (0);
}

t_push	*ft_creat_list(int argc, char **argv, int display)
{
	t_push	*p;
	int		i;

	p = NULL;
	i = 0;
	if (argc > 0)
	{
		while (argv[0][i])
		{
			if (argv[0][0] != '-' && (argv[0][i] < 48 || argv[0][i] > 57))
				ft_exception("Error");
			i++;
		}
		if (!(p = malloc(sizeof(t_push))))
			return (NULL);
		p->value = ft_atoi(argv[0]);
		if (ft_bigger_than_integer(argv[0], p->value, i - 1))
			ft_exception("Error");
		p->count = 0;
		p->display = display;
		p->next = ft_creat_list(argc - 1, &argv[1], display);
	}
	return (p);
}
