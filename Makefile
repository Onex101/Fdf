# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xrhoda <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/29 10:28:19 by xrhoda            #+#    #+#              #
#    Updated: 2018/06/29 10:28:21 by xrhoda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = 	main.c \
		draw.c \
		draw_line.c \
		read_map.c \
		vertex.c \
		./vector/vector_* \
		line_list.c \
		matrix_lib.c \
		matrix_util.c \
		input.c \
		

FLAGS = -Wall -Werror -Wextra -I /usr/X11/include -g -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit -L. libft/libft.a -I libft/includes
# FLAGS = -Wl,--no-as-needed -Wall -Werror -Wextra -lm -I /usr/local/include -l mlx -g -lX11 -lXext -I libft/includes/ -L. /usr/local/lib/libmlx_Linux.a 

all: $(NAME)

$(NAME):
	gcc $(FLAGS)  $(SRC) -o $(NAME)

fclean:
	rm -rf $(NAME)

re: fclean all