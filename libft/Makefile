NAME=libft.a
CC=gcc
IDIR=include
CFLAGS=-I. -Wall -Werror -Wextra -std=c89 -pedantic-errors $(CFLAGS_SPEED)
CFLAGS_SPEED=-finline-functions -Ofast
DEPS=libft.h

vpath %.c src

OBJ = $(subst .c,.o,$(subst src,obj,$(wildcard src/*.c)))

obj/%.o: %.c
	@mkdir -p obj
	$(CC) -c -o $@ $< $(CFLAGS)

$(NAME): $(OBJ)
	ar rcs $@ $^
	ranlib $(NAME)
	

.PHONY: clean re fclean all
all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME) obj/

re : fclean $(NAME)
