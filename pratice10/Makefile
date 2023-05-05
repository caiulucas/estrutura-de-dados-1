all: pratica.o avl.o
	@gcc pratica.o avl.o -o exe
	@rm *.o
pratica.o: pratica.c
		@gcc pratica.c -c
avl.o: avl.c
	@gcc avl.c -c
run:
	@./exe
