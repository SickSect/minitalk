 CLIENT = client
 SERVER = server

 SRC_C = mandatory/C/client.c mandatory/C/client_utils.c
 SRC_S = mandatory/S/server.c mandatory/S/server_utils.c
 OBJ_C = $(SRC_C:.c=.o)
 OBJ_S = $(SRC_S:.c=.o)

 B_SRC_C = bonus/C/client_bonus.c bonus/C/client_utils_bonus.c
 B_SRC_S = bonus/S/server_bonus.c bonus/S/server_utils_bonus.c
 B_OBJ_C = $(B_SRC_C:.c=.o)
 B_OBJ_S = $(B_SRC_S:.c=.o)

FLG = -Iinclude -Wall -Werror -Wextra

all :  $(CLIENT) $(SERVER)

bonus : $(B_OBJ_C) $(B_OBJ_S)
	rm -rf $(OBJ_C) $(OBJ_S) 
	gcc $(FLG) -o client $(B_OBJ_C)
	gcc $(FLG) -o server $(B_OBJ_S)

$(CLIENT) : $(OBJ_C)
	gcc $(FLG) -o $(CLIENT) $(OBJ_C)

$(SERVER) :  $(OBJ_S)
	gcc $(FLG) -o $(SERVER) $(OBJ_S)

%.o : %.c
	gcc $(FLG) -o $@ -c $<

clean :
	rm -rf $(OBJ_C) $(OBJ_S) $(B_OBJ_C) $(B_OBJ_S)

fclean : clean
	rm -rf $(SERVER) $(CLIENT)

re : fclean all
