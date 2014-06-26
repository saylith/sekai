CC=g++
CFLAGS=-c
SFMLFLAGS=-lsfml-graphics -lsfml-window -lsfml-system
EXECUTABLE=sekai

all: $(EXECUTABLE)

$(EXECUTABLE): main.o 
	$(CC) main.o -o $(EXECUTABLE) $(SFMLFLAGS)

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

clean:
	rm -rf *o $(EXECUTABLE)
