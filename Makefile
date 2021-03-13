CC = g++
EXEC_NAME = RaycastGame
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
OBJ_FILES = main.o Game.o Player.o Map.o

all: $(EXEC_NAME)

clean:
	rm $(EXEC_NAME) $(OBJ_FILES)

$(EXEC_NAME) : $(OBJ_FILES)
	$(CC) -o $(EXEC_NAME) $(OBJ_FILES) $(LIBS)

main.o:
	$(CC) -o main.o -c src/main.cpp

Game.o: 
	$(CC) -o Game.o -c src/Game.cpp

Player.o:
	$(CC) -o Player.o -c src/Player.cpp

Map.o:
	$(CC) -o Map.o -c src/Map.cpp
