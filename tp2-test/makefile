all: object.o point.o sort.o tp.o
	@gcc object.o point.o sort.o tp.o -o exe -g -Wall -lm
	@rm -r *.o
object.o: object.c 
	@gcc object.c -c -g -lm -Wall
point.o: point.c
	@gcc point.c -c -g -lm -Wall
sort.o: sort.c
	@gcc sort.c -c -g -lm -Wall
tp.o: tp.c
	@gcc tp.c -c -g -lm
run:
	@./exe
