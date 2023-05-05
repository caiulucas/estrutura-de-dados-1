all: main.o print.o
	@gcc main.o print.o -o exe
	rm -r *.o
print.o: print.c
	@gcc print.c -c -Wall
run:
	@./exe%                                                                 
