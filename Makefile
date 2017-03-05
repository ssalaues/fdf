# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssalaues <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/05 15:05:07 by ssalaues          #+#    #+#              #
#    Updated: 2017/03/05 15:41:18 by ssalaues         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = \
		main.c		\
		readin.c

all: $(NAME)

$(NAME): lib mlx
	@cd srcs && clang -Wall -Wextra -Werror -c $(SRCS) -g
	cd srcs && clang $(SRCS:.c=.o) -L../minilibx -lmlx -framework OpenGL -framework Appkit -L../libft -lft -o $(NAME)
	mv srcs/mlx .

lib:
	@cd libft && make

mlx:
	@cd minilibx && make

clean:
	@cd libft && make clean
	@cd srcs

fclean:
	@cd libft && make fclean
	@cd minilibx && make clean
