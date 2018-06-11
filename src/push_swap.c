/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julienso <julienso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 18:18:00 by julienso          #+#    #+#             */
/*   Updated: 2018/06/10 18:21:08 by juliensobel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ft_valid_list(t_push *p)
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

static t_push	*ft_creat_list(int argc, char **argv)
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

int		main(int argc, char **argv)
{
	t_push	*listA;
	t_push	*listB;

	listB = NULL;
	if (argc < 2)
		ft_exception("incorrect number of arguments");
	if (!(listA = ft_creat_list(argc - 1, &argv[1])))
		ft_exception("failed to creat list");
	if (!ft_valid_list(listA))
		ft_exception("Error");
	while (!(ft_is_sort_increasing(listA) && !listB))
	{
		ft_check_op(op, &listA, &listB);
		printf("command executed\n");
	}
	/*
	** Pour afficher la liste;
	*/
	int i;

	i = 1;
	while (listA != NULL)
	{
		if (listB)
		{
			printf("A%d : %d   B%d : %D\n",i ,listA->value, i, listB->value);
			listB = listB->next;
		}
		else
			printf("A%d : %d\n",i ,listA->value);
		listA = listA->next;
		i++;
	}
	return (0);
}
