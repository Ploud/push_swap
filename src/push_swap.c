/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julienso <julienso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 18:18:00 by julienso          #+#    #+#             */
/*   Updated: 2018/06/12 19:39:30 by juliensobel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_push	*a;
	t_push	*b;
	int			nb;
	int			med;

	b = NULL;
	if (argc < 2)
		ft_exception("incorrect number of arguments");
	if (!(a = ft_creat_list(argc - 1, &argv[1])))
		ft_exception("failed to creat list");
	if (!ft_valid_list(a))
		ft_exception("Error");
	nb = get_len(a);
	med = get_mediane(a, nb / 2);
	nb = ft_shaker(&a, &b, med);
	/*
	** Pour afficher la liste;

	int i;

	i = 1;
	while (a != NULL)
	{
		if (b)
		{
			printf("A%d : %d   B%d : %D\n",i ,a->value, i, b->value);
			b = b->next;
		}
		else
			printf("A%d : %d\n",i ,a->value);
		a = a->next;
		i++;
	}	*/
	//ft_free_list(&a);
	printf("\nresultat : %d\n", nb);
	return (0);
}
