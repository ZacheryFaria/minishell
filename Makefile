CC=gcc
CFLAGS=-Werror -Wextra -Wall -g -I libft/ -I includes -ofast -ggdb3 -funroll-loops
LIBFLAGS=-L libft/ -lft
NAME=minishell
SRC=$(wildcard src/*)
OBJ=$(SRC:src/%.c=%.o)
SHELL := /bin/bash

.PHONY: clean fclean all re norm norme debug test

VPATH = src obj libft/includes include

$(NAME): update $(OBJ)
	@make -C libft
	@$(CC) -o $(NAME) obj/* $(LIBFLAGS)
	@echo "minishell build complete!"

all: $(NAME)

%.o: %.c
	@mkdir -p obj
	@$(CC) $(CFLAGS) -o obj/$@ -c $<

clean:
	@make -C libft/ clean
	@rm -rf obj/

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all

norm:
	norminette src/. includes/.

update:
	@./update.sh

norme: norm

norman: norm
	make -C libft/ norm
