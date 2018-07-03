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

NAME 		= fdf.a
CFLAGS		= -Wall -Werror -Wextra /usr/X11/include -g -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit -c
FILES		=	draw.c draw_line.c vertex.c libft/libft.a

OBJ		= $(FILES:%.c=%.o)

all:	$(NAME)

$(NAME): $(OBJ)
	ar ras $(NAME) $(OBJ)

$(OBJ): $(FILES)
	gcc $(CFLAGS) $(FILES)

so: $(NAME)
	gcc $(CFLAGS) -fpic $(FILES)
	gcc -shared -o fdf.so $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all