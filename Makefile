CC		  	= clang
GDB_FLAG  	= -g 
CFLAGS    	= -Wall -Wextra -Werror
LIBS      	= -L libft -lft
SERVER    	= server
CLIENT    	= client
OBJ_S_DIR   = obj
LIBFT		= libft.a
HEADERS   	= ./headers/server.h
TARGET_S    = server/server.c utils/show_message.c  
TARGET_C    = client/client.c utils/show_message.c
OBJ_S_DIR   = obj
NAME		= minitalk
SRC_S       = $(addprefix ./src/, $(TARGET_S))
SRC_C       = $(addprefix ./src/, $(TARGET_C))
OBJ_S       = $(addprefix ./$(OBJ_DIR)/,$(TARGET_S:.c=.o))
OBJ_C       = $(addprefix ./$(OBJ_DIR)/,$(TARGET_C:.c=.o))

all: $(LIBFT) $(SERVER) $(CLIENT)

$(LIBFT): 
	@echo "compilando libft"
	@make -C libft 

$(SERVER): $(SRC_S)
	$(CC) $(SRC_S) $(CFLAGS) $(GDB_FLAG) $(LIBS) -o $(SERVER)

$(CLIENT): $(SRC_C)
	$(CC) $(SRC_C) $(CFLAGS) $(GDB_FLAG) $(LIBS) -o $(CLIENT)


clean:
	@make clean -C libft 
	rm -f $(OBJ_S)
	rm -f $(OBJ_C)
	@echo "files deleted"

fclean: clean 
	@make fclean -C libft
	rm -f	 $(SERVER)
	rm -f	 $(CLIENT)
	rm -rf $(OBJ_S_DIR)
	rm -rf $(LIBFT)
	@echo "binaries deleted"

re: $(NAME)

$(NAME): all 

