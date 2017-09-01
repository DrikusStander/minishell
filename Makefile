NAME = minishell

SRC = 	minishell.c	getdir.c builtin.c init.c loop.c env.c extras.c ch.c\

LIBS = -L./libft/ -lft

FLAGS = -Wall -Werror -Wextra $(LIBS)

HEADERS = libft.h minishell.h

all : $(NAME)

$(NAME) :
	make -C ./libft/
	gcc -o $(NAME) $(FLAGS) $(SRC)

clean:
	make clean -C ./libft/
	rm -f $(NAME)

fclean: clean
	make fclean -C ./libft/
	rm -f $(NAME)

re: fclean all
	make re -C ./libft/
