CC = gcc
GDB_FLAG = -g 
CFLAGS = -Wall -Wextra -Werror
LIBS = -L ./libft
SERVER = server
OBJ_DIR = obj
MAIN_TARGET = main.c 
MAIN_SRC = $(addprefix ./src/, $(MAIN_TARGET))
SRC = $(addprefix ./src/, $(TARGET))
OBJ = $(addprefix ./$(OBJ_DIR)/, $(TARGET:.c=.o))
HEADERS = headers/server.h
LIBFT = libft.a


all: $(LIBFT) $(SERVER)

$(LIBFT): 
	@echo "compilando libft"
	@make -C libft 
	cp libft/libft.a $(LIBFT)

$(SERVER): $(OBJ_DIR) $(OBJ) $(LIBFT)
	@echo "compilando projeto"
	$(CC) $(MAIN_SRC)  $(LIBS) -o $(SERVER)

$(OBJ_DIR)/%.o:src/%.c $(HEADERS)
	@echo "compilando objetos"
	$(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)/server
	mkdir -p $(OBJ_DIR)/client

clean:
	@make clean -C libft 
	rm -f $(OBJ)
	@echo "files deleted"

fclean: clean 
	@make fclean -C libft
	rm -f $(SERVER)
	@echo "binaries deleted"

re: fclean all
