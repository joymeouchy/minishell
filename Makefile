NAME = minishell
LIBFT= ./libft/libft.a

CC = gcc
CFLAGS = -Werror -Wall -Wextra -g
LFLAGS= -lreadline -L/usr/local/opt/readline/Lib -I/usr/local/opt/readline/include

SRC =   src/main.c \
		src/parser/parser_copy.c \
		src/structures/free_structures.c \
		src/structures/linked_list_utils.c\
        src/structures/linked_list_utils2.c\
		
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