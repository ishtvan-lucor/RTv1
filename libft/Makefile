# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikoloshy <ikoloshy@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/24 17:36:13 by ikoloshy          #+#    #+#              #
#    Updated: 2019/02/07 20:30:57 by ikoloshy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_putchar.c ft_putstr.c ft_bzero.c ft_memalloc.c ft_memdel.c ft_strnew.c \
	  ft_strdel.c ft_strclr.c ft_strequ.c ft_strnequ.c ft_memset.c ft_memcpy.c \
	  ft_memccpy.c ft_strlen.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c \
	  ft_strchr.c ft_strrchr.c ft_strcmp.c ft_strncmp.c ft_strstr.c ft_strnstr.c \
	  ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	  ft_toupper.c ft_tolower.c ft_strdup.c ft_memmove.c ft_memchr.c ft_memcmp.c \
	  ft_strlcat.c ft_putendl.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_itoa.c \
	  ft_wordssplit.c ft_strclen.c ft_strsplit.c ft_intlen.c ft_putchar_fd.c \
	  ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putnbr.c ft_striter.c \
	  ft_striteri.c ft_strmap.c ft_strmapi.c ft_lstnew.c ft_lstdelone.c \
	  ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_lstswap.c ft_realloc.c \
	  get_next_line.c ft_iscolor_rgb.c ft_atoi_base.c ft_free_after_split.c \
	  ft_string_to_double.c ft_set_vector.c ft_isdouble_or_int.c \
	  ft_operation_on_vector.c ft_arithmetic_oper_vector.c ft_vect_oper_nbr.c \

OFL = $(SRC:.c=.o)
HDR = libft.h
FLG = -Wall -Wextra -Werror

.PHONY: all clean fclean re

.NOTPARALLEL: all clean fclean re

all: $(NAME)

$(NAME): $(OFL)
	@ar rc $(NAME) $(OFL)
	@echo "\033[1;32mlibft was compiled\033[0m"

%.o: %.c $(HDR)
	@gcc -c $< -o $@ $(FLG)

clean:
	@/bin/rm -f $(OFL)
	@echo "\033[1;32mObjcts from libft were deleted\033[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@ echo "\033[1;32mlibft was deleted\033[0m"

re: fclean all
