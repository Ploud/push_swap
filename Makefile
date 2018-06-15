# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucien <lucien@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/06 11:25:50 by lucien            #+#    #+#              #
#    Updated: 2018/06/15 20:20:58 by jsobel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1	= push_swap
NAME2	= checker

SRC1	=	push_swap.c			\
			list.c				\
			swap.c				\
			push.c				\
			rotate.c			\
			reverse.c			\
			process.c			\
			get_data.c			\
			sort.c				\
			quick_sort.c		\
			exception.c

SRC2	=	checker.c 			\
			list.c 				\
			exception.c 		\
			get_data.c 			\
			get_next_line.c 	\
			operator.c 			\
			sort.c 				\
			push.c 				\
			reverse.c 			\
			rotate.c 			\
			shaker.c 			\
			swap.c

OBJ1		= $(addprefix ./obj/,$(SRC1:.c=.o))
OBJ2		= $(addprefix ./obj/,$(SRC2:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

LIBFTA	= ./libft/libft.a
LIBINCL = -I./libft/includes
LIBLINK	= -L./libft -lft

all: obj libft $(NAME1) $(NAME2)

obj:
	mkdir -p ./obj/

./obj/%.o:./src/%.c
	$(CC) $(CFLAGS) $(LIBINCL) -Iincludes -o $@ -c $<

libft: $(LIBFTA)

$(LIBFTA):
	make -C ./libft

$(NAME2): $(OBJ2)
	$(CC) -o $(NAME2) $(OBJ2) $(LIBLINK)

$(NAME1): $(OBJ1)
	$(CC) -o $(NAME1) $(OBJ1) $(LIBLINK)

clean:
	rm -rf ./obj/
	make -C ./libft clean

fclean: clean
	rm -rf $(NAME1)
	rm -rf $(NAME2)
	make -C ./libft fclean

re: fclean all
