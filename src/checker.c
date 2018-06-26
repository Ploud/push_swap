/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 18:29:23 by jsobel            #+#    #+#             */
/*   Updated: 2018/06/26 19:22:05 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_push	*split_arg(char *tab)
{
	char 	**copie;
	t_push	*a;
	int		i;

	i = 0;
	if (!(copie = ft_strsplit(tab, ' ')))
		return (NULL);
	while (copie[i])
		i++;
	a = ft_creat_list(i, copie, 0);
	return (a);
}

int				main(int argc, char **argv)
{
	t_push	*a;
	t_push	*b;
	char	*op;

	b = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2 && ft_strchr(argv[1], ' '))
		a = split_arg(argv[1]);
	else if (!(a = ft_creat_list(argc - 1, &argv[1], 0)))
		ft_exception("failed to creat list");
	if (!ft_valid_list(a))
		ft_exception("Error");
	while ((get_next_line(0, &op) > 0))
		ft_check_op(op, &a, &b);
	if (ft_is_sort_increasing(a) && !b)
		ft_putendl("OK");
	else
		ft_putendl("KO");
	ft_free_list(&a);
	ft_free_list(&b);
	return (0);
}
