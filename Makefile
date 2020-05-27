gamePrinter.o: gamePrinter.h   gamePrinter.c
	gcc -c gamePrinter.c

main.o: gamePrinter.h   main.c
	gcc -c main.c

main: gamePrinter.o   main.o
	gcc gamePrinter.o main.o -o main
