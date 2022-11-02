CC 				= gcc
GDB_FLAG  = -g 
CFLAGS    = -Wall -Wextra -Werror
LIBS      = -L libft -lft
SERVER    = server
OBJ_DIR   = obj
LIBFT     = libft.a
HEADERS   = ./headers/server.h
TARGET    = server/server.c 
OBJ_DIR   = obj
SRC       = $(addprefix ./src/, $(TARGET))
OBJ       = $(addprefix ./$(OBJ_DIR)/,$(TARGET:.c=.o))

all: $(LIBFT) $(SERVER)

$(LIBFT): 
	@echo "compilando libft"
	@make -C libft 

$(SERVER): $(LIBFT)  
	$(CC) $(SRC) $(CFLAGS) $(LIBS) -o $(SERVER)

clean:
	@make clean -C libft 
	rm -f $(OBJ)
	@echo "files deleted"

fclean: clean 
	@make fclean -C libft
	rm -f	 $(SERVER)
	rm -rf $(OBJ_DIR)
	rm -rf $(LIBFT)
	@echo "binaries deleted"

re: fcl0ean all
