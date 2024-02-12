CC=gcc
SRC_DIR=./src
BIN_DIR=./bin
SRC=./src/server_start.c ./src/client_start.c ./src/utils.c ./src/sock.c
OBJ=./bin/server_start.o ./bin/client_start.o ./bin/utils.o ./bin/sock.o
EXE_SERV=serv
EXE_CLI=cli
NAME=TimeServer
FLAGS=-g

$(NAME): ./bin/client_start.o ./bin/server_start.o ./bin/utils.o ./bin/sock.o
	$(CC) $(FLAGS) -o $(EXE_SERV) ./bin/server_start.o ./bin/utils.o ./bin/sock.o
	$(CC) $(FLAGS) -o $(EXE_CLI) ./bin/client_start.o ./bin/utils.o ./bin/sock.o

$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXE_CLI) $(EXE_SERV)