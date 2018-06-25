/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julienso <julienso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 18:18:00 by julienso          #+#    #+#             */
/*   Updated: 2018/06/25 17:51:29 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					global_count(t_push *a)
{
	int	nb;

	nb = 0;
	if (a && a->count == -1)
		return (-1);
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

static void select_method(void (*tab[5])(t_push **, t_push **), int result[5], int argc, char **argv)
{
	int min;
	int index;
	t_push	*a;
	t_push	*b;
	int	i;

	b = NULL;
	min = 2147483647;
	i = 0;
	while (i <= 4)
	{
		if (result[i] >= 0 && result[i] <= min)
		{
			min = result[i];
			index = i;
		}
		i++;
	}
	if (!(a = ft_creat_list(argc, argv, 1)))
		ft_exception("failed to creat list");
	if (!ft_valid_list(a))
		ft_exception("Error");
	tab[index](&a, &b);
	ft_free_list(&a);
}

static void	fill_result(void (*tab[5])(t_push **, t_push **), int result[5], int argc, char **argv)
{
	t_push	*a;
	t_push	*b;
	int	i;

	b = NULL;
	i = 0;
	while (i <= 4)
	{
		if (!(a = ft_creat_list(argc, argv, 0)))
			ft_exception("failed to creat list");
		if (!ft_valid_list(a))
			ft_exception("Error");
		tab[i](&a, &b);
		if (ft_is_sort_increasing(a) && !b)
			result[i] = global_count(a);
		else
			result[i] = -1;
		ft_free_list(&a);
		i++;
	}
}

static void	ft_init_tab(void (*tab[5])(t_push **, t_push **))
{
	tab[0] = &ft_process;
	tab[1] = &ft_shaker;
	tab[2] = &simple_case;
	tab[3] = &end_reverse;
	tab[4] = &shake_it_all;
}

int					main(int argc, char **argv)
{
	void 		(*tab[5])(t_push **, t_push **);
	int			result[5];

	if (argc < 2)
		ft_exception("");
	ft_init_tab(tab);
	fill_result(tab, result, argc - 1, &argv[1]);
	printf("total process = %d\ntotal shaker = %d\ntotal simple case = %d\ntotal end_reverse = %d\ntotal shake_it_all = %d\n",
	result[0], result[1], result[2], result[3], result[4]);
	select_method(tab, result, argc - 1, &argv[1]);
	/*t_push	*tmp, *tmp2;
	tmp = a;
	tmp2 = b;
	if (ft_is_sort_increasing(tmp) && !tmp2)
		ft_putendl("OK");
	else
		ft_putendl("KO");
	ft_free_list(&a);*/
	return (0);
}
