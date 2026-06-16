# Define variables for the compiler and flags
CC = gcc
CFLAGS = -Wall -g

LIBS = -lallegro -lallegro_main -lallegro_image -lallegro_font -lallegro_ttf -lallegro_primitives

# The default target that runs when you just type 'make'
all: myprogram

# Rule to build the final executable from main.c
myprogram: main.c
	$(CC) $(CFLAGS) -o myprogram main.c $(LIBS)

# Rule to clean up generated files
clean:
	rm -f myprogram
