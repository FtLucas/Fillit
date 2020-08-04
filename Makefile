# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luwargni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/17 15:58:01 by luwargni          #+#    #+#              #
#    Updated: 2019/01/18 16:39:03 by dacuvill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

SRCS = main.c \
	   ft_parse_file.c \
	   ft_create_list.c \
	   ft_solve.c \
	   ft_error_map.c \
	   ft_error.c \
	   ft_check_and_fill.c \
	   ft_remove_tetri.c \
	   ft_print_res.c \
	   ft_delmap.c

OBJ = $(SRCS:.c=.o)

CFLAGS += -Werror -Wextra -Wall -I./includes

LIBFT = libft/libft.a

all: $(NAME)

$(OBJ): %.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C libft

clean: 
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
