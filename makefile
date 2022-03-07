 NAME = minitalk

 SRC = client.c server.c sys_func.c sys_func_plus.c client_utils.c

 OBJ = $(SRC:.c=.o)

 all: $(NAME)

 $(NAME): $(OBJ)
	gcc -Wall -Werror -Wextra -fsanitize=address $(OBJ) -o $(NAME)

%.o : %.c
	