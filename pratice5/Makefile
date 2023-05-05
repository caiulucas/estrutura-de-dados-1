all: pratica.o lista.o pilha.o fila.o
	@gcc pratica.o lista.o pilha.o fila.o -o exe
	@rm -r *.o
pratica.o: pratica.c
	@gcc pratica.c -c
lista.o: lista.c
	@gcc lista.c -c
pilha.o: pilha.c
	@gcc pilha.c -c
fila.o: fila.c
	@gcc fila.c -c
run:
	@./exe
