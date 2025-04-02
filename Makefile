NAME = minishell
LIBFT= ./libft/libft.a

CC = gcc
CFLAGS = -Werror -Wall -Wextra -g
LFLAGS= -lreadline -L/usr/local/opt/readline/Lib -I/usr/local/opt/readline/include

SRC =   src/parser/parser.c \
		src/parser/remove_quotes.c \
		src/parser/expand.c \
		src/parser/utils.c \
		src/parser/tokenize.c \
		src/parser/get_env.c \
		src/main.c\
		src/structures/free_structures.c \
		src/structures/linked_list_utils.c\
		src/structures/stack_utils.c\
        src/structures/linked_list_utils2.c\
		src/shunting_yard.c\
        src/structures/tree_utils.c\
		src/structures/redirections.c\

		
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(LFLAGS)

$(LIBFT):
	make -C ./libft


%.o: %.c
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
		rm -f $(OBJ)
		make -C ./libft clean

fclean: clean
		rm -f $(NAME)
		make -C ./libft fclean

re: fclean all
.PHONY: all clean fclean re