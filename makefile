 CLIENT = client
 SERVER = server

 SRC_C = C/client.c C/client_utils.c
 SRC_S = S/server.c S/server_utils.c

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
	rm -rf $(OBJ_C) $(OBJ_S)

fclean : clean
	rm -rf $(SERVER) $(CLIENT)

re : fclean all
