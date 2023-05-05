all: pratica.o dtime.o duende.o
	@gcc pratica.o dtime.o duende.o -o exe
	@rm -rf *.o
pratica.o: pratica.c
	@gcc pratica.c -c -Wall
dtime.o: dtime.c
	@gcc dtime.c -c -Wall
duende.o: duende.c
	@gcc duende.c -c -Wall
run:
	@./exe