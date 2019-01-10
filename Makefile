#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikoloshy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/11 15:27:53 by azaporoz          #+#    #+#              #
#    Updated: 2019/01/04 18:35:57 by ikoloshy         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = RTv1
FLG = -Wall -Wextra -Werror
FRM = -framework AppKit -framework OpenGL
SRC = src/main.c \
	  src/validation_config.c \
	  src/point_from_screen_to_viewport.c \
	  src/init_mlx.c \
	  src/start_loop_mlx.c \
	  src/vector_writer.c \
	  src/val_camera.c \

HDR = includes/RTv1.h
OFL = $(SRC:.c=.o)
LIB = libft/libft.a
MLX = -lmlx -I minilibx_macos -L minilibx_macos

.NOTPARALLEL: all clean fclean re

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIB) $(OFL) 
	@gcc $(FLG) -o $@ $(OFL) -I $(HDR) -L libft/ -lft $(MLX) $(FRM)
	@echo "\033[1;32mRTv1 is ready to work\033[0m"

%.o: %.c $(HDR) $(LIB)
	@gcc -c $< -o $@ $(FLG) 
$(LIB):
	@make -C ./libft

clean:
	@/bin/rm -f $(OFL)
	@make fclean -C ./libft
	@echo "\033[1;32mObjects files RTv1 were deleted\033[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\033[1;32mRTv1 was deleted\033[0m"

re: fclean all
