 CLIENT = client

 SERVER = server

 SRC_C = client.c client_utils.c

 SRC_S = server.c 

 SRC_SERVICE = sys_func.c sys_func_plus.c 

 OBJ_C = $(SRC_C:.c=.o)

 OBJ_S = $(SRC_s:.c=.o)

 OBJ_SERVICE = $(SRC_SERVICE:.c=.o)


	