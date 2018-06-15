/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 18:32:07 by jsobel            #+#    #+#             */
/*   Updated: 2018/06/15 20:19:28 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

//# define EXIT_ERROR -1
# define BUFF_SIZE  10
# define SMALL_SIZE 4
# define MEDIUM_SIZE 9

typedef struct		s_push
{
	int				value;
	struct s_push	*next;
}					t_push;

typedef struct		s_data
{
	char			*line;
	char			*tmp;
	int				index;
	struct s_data	*next;
}					t_data;

t_push				*ft_creat_list(int argc, char **argv);
int					ft_valid_list(t_push *p);
void				ft_free_list(t_push **begin_list);

void				ft_exception(char *s);

int					get_next_line(const int fd, char **line);

void				ft_check_op(char *op, t_push **a, t_push **b);
int					ft_swap(t_push **p);
int					ft_rotate(t_push **p);
void				ft_push(t_push **p1, t_push **p2);
int					ft_reverse_rotate(t_push **p);

int					get_min(t_push *a);
int					get_max(t_push *a);
int					get_len(t_push *a);
int					get_position_int(t_push *a, int nb);
int					get_mediane(t_push *a, int len);

void				pa(t_push **a, t_push **b);
void				pb(t_push **b, t_push **a);

int					ra(t_push **a);
int					rb(t_push **b);
int					rr(t_push **a, t_push **b);

int					rra(t_push **a);
int					rrb(t_push **b);
int					rrr(t_push **a, t_push **b);

int					sa(t_push **a);
int					sb(t_push **b);
int					ss(t_push **a, t_push **b);

int					ft_is_sort_increasing(t_push *p);
int					ft_is_sort_decreasing(t_push *p);
int					ft_sort(t_push **a, t_push **b);
int					check(t_push **a, t_push **b, int *count);

void				shake_it_all(t_push **a, t_push **b, int *count);
int					divide_to_conquer(t_push **a, t_push **b, int med, int *c);
int					ft_shaker(t_push **a, t_push **b);

/*
** push_swap -- process
*/

void				ft_process(t_push **a, t_push **b);
void				sort_3less_int(t_push **a, int len, int int_min,
					int int_max);
void				basic_selective_sort(t_push **a, t_push **b, int len);
void				launch_quick_sort(t_push **a, t_push **b);

/*
**push_swap -- quick_sort
*/

void				process_distri_pyramid(t_push **a, t_push **b);
void				process_selec_sort_opti(t_push **a, t_push **b);
int					opti_get_max_moins_un(t_push **a, int max_b);
void				opti_place_ints_max(t_push **a, t_push **b, int ret);
int					where_is_next(t_push *a, int mediane);

#endif
