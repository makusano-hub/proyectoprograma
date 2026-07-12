# Variables del compilador y opciones
CC = gcc
CFLAGS = -Wall -g

# Librerías de Allegro
LIBS = -lallegro -lallegro_main -lallegro_image -lallegro_font -lallegro_ttf -lallegro_primitives

# Nombre del ejecutable final
TARGET = juego

# Lista de todos tus archivos de código (.c)
SRCS = main.c jugador.c movimiento.c pantalla.c enemigo.c colision.c mapa.c hud.c

# Convierte la lista de .c en archivos de objeto (.o) automáticamente
OBJS = $(SRCS:.c=.o)

# Regla principal por defecto
all: $(TARGET)

# Regla para crear el ejecutable final uniendo los objetos
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

# Regla general para compilar cualquier archivo .c en un .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para limpiar los archivos generados
clean:
	rm -f $(TARGET) $(OBJS)

