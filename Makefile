# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xrhoda <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/29 10:28:19 by xrhoda            #+#    #+#              #
#    Updated: 2018/07/18 11:52:25 by xrhoda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FILES = 	main.c \
			transform_map.c \
			draw.c \
			draw_line.c \
			read_map.c \
			vertex.c \
			line_list.c \
			matrix_lib.c \
			matrix_util.c \
			input.c

VECT_FILES1 = vector_add.c vector_delete.c vector_free.c \
				vector_get.c vector_init.c vector_resize.c \
				vector_set.c vector_total.c
VECT_FILES2 = $(patsubst %, ./vector/%, $(VECT_FILES1))

FILES1 = $(FILES) $(VECT_FILES1)

OBJ2	= $(FILES:%.c=./obj/%.o)
O_SWAP = $(patsubst %, ./vector/%, $(OBJ))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g

MLX_INC	= -I /usr/X11/include -g
MLX_LNK	= -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit

FT		= ./libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft/includes
FT_LNK	= -L ./libft -l ft

VECT	= ./vector/
VECT_LIB = $(addprefix $(V_),vector.a)
VECT_INC = -I ./vector/includes
VECT_LINK = -L. ./vector/vector.a

FDF_INC = -I ./includes

INCLUDES = $(FDF_INC) $(FT_INC) $(MLX_INC) $(VECT_INC)

OBJDIR	= ./obj/

all: obj $(OBJ2) $(FT_LIB) $(VECT_LIB) $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(FT_LIB):
	make -C $(FT)

$(VECT_LIB):
	make -C $(VECT)

$(NAME):
	$(CC) $(OBJ2) $(INCLUDES) $(MLX_LNK) $(FT_LNK) $(VECT_LINK) $(VECT_INC) -lm -o $(NAME)

clean:
	rm -rf $(OBJDIR)
	make -C $(FT) clean
	make -C $(VECT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(FT) fclean
	make -C $(VECT) fclean

re: fclean all
