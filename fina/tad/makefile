all: main.o tad.o
	@gcc main.o tad.o -o exe
	rm -r *.o
tad.o: tad.c
	@gcc tad.c -c -Wall
run:
	@./exe%                                                                 
