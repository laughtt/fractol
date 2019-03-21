# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcarpio- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/02 13:30:58 by jcarpio-          #+#    #+#              #
#    Updated: 2019/03/21 10:45:18 by jcarpio-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= fractol
DNAME	:= d_$(NAME)
SRC		:= main.c \
			hooks.c \
			julia.c \
			color.c \
			burning_ship.c \
			tricorn.c \
			key_hooks.c
OBJ		:= $(SRC:.c=.o)

CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror
DFLAGS	:= -Wall -Wextra -g
AFLAGS	:= -fsanitize=address
## Libraries
LIBFT = libft/libft.a
LIBMLX = miniLibX/libmlx.a -framework OpenGL -framework AppKit
LIB = -I libft/ -I miniLibX/ $(LIBFT) $(LIBMLX)

.PHONY: all clean fclean re debug dclean libft mlx

all: $(NAME)

libft:
	make -sC libft/

mlx:
	make -sC miniLibX/

$(NAME): 
	$(CC) $(CFLAGS) $(LIB) $(SRC) -o $(NAME)

debug:
	$(CC) $(DFLAGS) $(LIB) $(SRC) -o $(DNAME)

dclean:
	rm -rf $(DNAME) $(DNAME).dSYM/

clean:
	rm -f $(OBJ)

fclean: 
	rm -f $(NAME)

re: fclean all
