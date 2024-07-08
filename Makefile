NAME=push_swap

CC=cc
CFLAGS=-g -Wall -Wextra -Werror -I.
RM=rm -f

SRC= main.c \
	utils_base.c utils_ft_atoi.c utils_ft_split.c utils_lst.c \
	ps_parsing.c ps_moves.c

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re $(NAME)
.SILENT: