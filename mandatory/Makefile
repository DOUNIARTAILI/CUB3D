# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/29 21:01:57 by drtaili           #+#    #+#              #
#    Updated: 2023/09/11 08:15:03 by mmaqbour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = draw.c draw_1.c main.c utils.c init.c \
		dda.c move_shape.c check_map.c check_map_1.c free_all.c \
		pars_map.c pars_map_1.c parsing.c pars_textures1.c \
		pars_textures1_1.c pars_textures2.c minimap.c minimap_1.c
OBJS = $(SRC:.c=.o)
NAME = cube3d
LIBFT = libft/libft.a
HEADER = cube3d.h

CC = cc

RM = rm -rf

FLAGS = -Wall -Wextra -Werror

FLAGS_mlx = -lm -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) $(FLAGS) $(LIBFT) $(FLAGS_mlx) $(OBJS) -o $(NAME)

$(LIBFT) :
	@make -C libft

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@make clean -C libft
	$(RM) $(OBJS)

fclean: clean
	@make fclean -C libft
	$(RM) $(NAME) 

re: fclean $(NAME)

.PHONY = all clean fclean re
