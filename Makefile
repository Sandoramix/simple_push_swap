NAME=push_swap

CC=cc
CFLAGS=-g -Wall -Wextra -Werror -I.
RM=rm -f

SRC=base_utils.c lst_utils.c parsing_utils.c ps_moves.c ft_atoi.c ft_split.c main.c

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re $(NAME)
.SILENT: