CC=g++
CFLAGS=-c
EXECUTABLE=map
OBJECTS=battlemap.o square.o
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABLE)

battlemap.o: battlemap.cpp battlemap.h landmark.h square.h terrain.h
	$(CC) $(CFLAGS) battlemap.cpp

square.o: square.cpp square.h landmark.h terrain.h
	$(CC) $(CFLAGS) square.cpp

clean:
	rm -rf *o $(EXECUTABLE)
