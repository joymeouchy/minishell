NAME = minishell
LIBFT= ./libft/libft.a

CC = gcc
CFLAGS = -Werror -Wall -Wextra -g
LFLAGS= -lreadline -L/usr/local/opt/readline/Lib -I/usr/local/opt/readline/include

SRC =   $(wildcard *.c)
        
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

fclean: clean
		rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re