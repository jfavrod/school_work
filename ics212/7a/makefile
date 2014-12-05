CC:=gcc -ansi -Wall

all :
	make test
	make clean

test : paintRoad.o
	$(CC) -o test_paintRoad paintRoad.o test_paintRoad.c

paintRoad.o :
	$(CC) -c paintRoad.c

clean : 
	rm *.o
