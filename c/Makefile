# compiler:
CC = gcc

# compiler flags: 
CFLAGS = -g -Wall

# the build target executable:
TARGET = host

# object files to build:
OBJ = host.o node.o _kbhit.o simulation.o cell.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

clean:
	rm $(OBJ)

reset:
	rm $(OBJ) $(TARGET)
