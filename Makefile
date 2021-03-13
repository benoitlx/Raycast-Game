# Raycast Game
# Created by benoitlx

CC = g++
EXEC_NAME = RaycastGame
CFLAGS = -Wall
SRC_DIR = src/
OBJ_FILES = main.o Game.o Player.o Map.o
INSTALL_DIR = /usr/bin


# Libraries
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

all: $(EXEC_NAME)
	

clean:
	rm $(EXEC_NAME)

cleanObj:
	rm $(OBJ_FILES)




$(EXEC_NAME) : $(OBJ_FILES)
	$(CC) -o $(EXEC_NAME) $(OBJ_FILES) $(LIBS)

%.o: $(SRC_DIR)%.cpp 
	$(CC) $(CFLAGS) -o $@ -c $<





install:
	cp $(EXEC_NAME) $(INSTALL_DIR)

uninstall:
	rm $(INSTALL_DIR)/$(EXEC_NAME)
