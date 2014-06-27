CC=g++
CFLAGS=-c
LINKERFLAGS=-lsfml-graphics -lsfml-window -lsfml-system -lglut -lGL
EXECUTABLE=sekai

all: $(EXECUTABLE)

$(EXECUTABLE): main.o
	$(CC) main.o -o $(EXECUTABLE) $(LINKERFLAGS)

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

clean:
	rm -rf *o $(EXECUTABLE)
