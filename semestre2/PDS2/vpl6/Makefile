CC=g++
CFLAGS=-std=c++11 -Wall -g
SRC_DIR=src
INCLUDE_DIR=include
OBJ_DIR=build

all: $(OBJ_DIR) main

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/aluno.o: $(INCLUDE_DIR)/aluno.hpp $(SRC_DIR)/aluno.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/aluno.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/aluno.o

$(OBJ_DIR)/main.o: $(INCLUDE_DIR)/aluno.hpp $(SRC_DIR)/main.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/main.o

main: $(OBJ_DIR)/main.o $(OBJ_DIR)/aluno.o
	$(CC) $(CFLAGS) $(OBJ_DIR)/main.o $(OBJ_DIR)/aluno.o -o vpl_execution

clean:
	rm -rf $(OBJ_DIR) vpl_execution