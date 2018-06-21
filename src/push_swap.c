/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julienso <julienso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 18:18:00 by julienso          #+#    #+#             */
/*   Updated: 2018/06/21 18:53:39 by juliensobel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					global_count(t_push *a)
{
	int	nb;

	nb = 0;
	while (a)
	{
		nb += a->count;
		a = a->next;
	}
	return (nb);
}

void				print_list(t_push *a, t_push *b)
{
	int i;

	i = 1;
	while (a != NULL)
	{
		if (b)
		{
			printf("A%d : %d   B%d : %d\n",i ,a->value, i, b->value);
			b = b->next;
		}
		else
			printf("A%d : %d\n",i ,a->value);
		a = a->next;
		i++;
	}
	while (b)
	{
		printf("               B%d : %d\n",i ,b->value);
		b = b->next;
		i++;
	}
}

static void	fill_result(void (*tab[4])(t_push **, t_push **), int result[3])
{
	int	i;

	i = 0;
	while (i <= 3)
	{
		
	}
}

static void	ft_init_tab(void (*tab[4])(t_push **, t_push **))
{
	tab[0] = &ft_process;
	tab[1] = &ft_shaker;
	tab[2] = &simple_case;
	tab[3] = &end_reverse;
}

int					main(int argc, char **argv)
{
	t_push	*a;
	t_push	*b;
	void 		(*tab[4])(t_push **, t_push **);
	int			result[3];

	b = NULL;
	if (argc < 2)
		ft_exception("");
	ft_init_tab(tab);
	fill_result(tab, result);
	if (!(a = ft_creat_list(argc - 1, &argv[1], 0)))
		ft_exception("failed to creat list");
	if (!ft_valid_list(a))
		ft_exception("Error");
	ft_process(&a, &b);
	result[0] = global_count(a);
	ft_free_list(&a);
	if (!(a = ft_creat_list(argc - 1, &argv[1], 0)))
		ft_exception("failed to creat list");
	ft_shaker(&a, &b);
	result[1] = global_count(a);
	if (simple_case(&a, &b))
		result[2] = global_count(a);
	else
		result[2] = -1;
	printf("total process = %d\ntotal shaker = %d\ntotal simple shaker = %d\n", result[0], result[1], result[2]);
	t_push	*tmp, *tmp2;
	tmp = a;
	tmp2 = b;
	if (ft_is_sort_increasing(tmp) && !tmp2)
		ft_putendl("OK");
	else
		ft_putendl("KO");
	ft_free_list(&a);
	return (0);
}
