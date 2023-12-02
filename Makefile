# -*- Makefile -*-

NAME	= minishell

CC		= cc
CFLAGS	= -Werror -Wall -Wextra
LIBFT	= ./libft/libft.a

INC		= -I minishell.h -lreadline

SRC		= minishell.c

OBJ		= $(SRC:%.c=%.o)

BLUE 		= \033[1;36m
WHITE 		= \033[0;39m
T_LIB		= $(shell test -f ./libft/get_next_line_utils.o && echo "yes" 2>&1)


all: libft $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $< $(INC) $(LIBFT) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

libft:
	@if ! [ $(T_LIB) ]; then echo "$(BLUE)-*- Creating libft library. -*-$(WHITE)";fi
	@make -C libft/ --no-print-directory

clean:
	@make clean -C ./libft --no-print-directory
	rm -f $(OBJ)

fclean: clean
	rm -f $(LIBFT) $(NAME)

re: fclean all

.PHONY: all libft clean fclean re