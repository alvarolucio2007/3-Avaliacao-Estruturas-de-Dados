CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SRC = main.c vetor.c lista.c lista_dupla.c lista_circular.c pilha.c fila.c deque.c hash.c abb.c heap.c grafo.c
OBJ = $(SRC:.c=.o)
TARGET = projeto_ed

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET)

run: all
	./$(TARGET)