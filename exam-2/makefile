all: main.o  list.o
	@gcc main.o list.o -o exe
	@rm -r *.o
main.o: main.c
	@gcc main.c -c
list.o: list.c
	@gcc list.c -c
run:
	@./exe
