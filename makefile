 CLIENT = client
 SERVER = server

 SRC_C = client.c client_utils.c
 SRC_S = server.c server_utils.c server_utils_plus.c

 OBJ_C = $(SRC_C:.c=.o)
 OBJ_S = $(SRC_S:.c=.o)

FLG = -Wall -Werror -Wextra

all :  $(CLIENT) $(SERVER)

$(CLIENT) : $(OBJ_C)
	gcc $(FLG) -o $(CLIENT) $(OBJ_C)

$(SERVER) :  $(OBJ_S)
	gcc $(FLG) -o $(SERVER) $(OBJ_S)

%.o : %.c
	gcc $(FLG) -c $< -o $@

clean :
	rm -rf *.o

fclean : clean
	rm -rf $(SERVER) $(CLIENT)

re : fclean all
