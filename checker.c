/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 18:29:23 by jsobel            #+#    #+#             */
/*   Updated: 2018/06/06 20:03:25 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exception(char *s)
{
	ft_putendl(s);
	exit(EXIT_FAILURE);
}

static int ft_valid_list(t_data *p)
{
	t_data *c;

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

static t_data	*ft_creat_list(int argc, char **argv)
{
	t_data *p;

	p = NULL;
	if (argc > 0)
	{
		if (!(p = malloc(sizeof(t_data))))
			return (NULL);
		p->value = ft_atoi(argv[0]);
		p->next = ft_creat_list(argc - 1, &argv[1]);
	}
	return (p);
}

int		main(int argc, char **argv)
{
	t_data *start;

	if (argc < 2)
		ft_exception("incorrect number of arguments");
	if (!(start = ft_creat_list(argc - 1, &argv[1])))
		ft_exception("failed to creat list");
	if (!ft_valid_list(start))
		ft_exception("Error");
	/*
	** Juste pour verfier la bonne creation de la liste

	while (start != NULL)
	{
		printf("%d\n", start->value);
		start = start->next;
	}
	*/
	return (0);
}