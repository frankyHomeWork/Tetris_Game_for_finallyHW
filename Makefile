gamePrinter.o: gamePrinter.h   gamePrinter.c
	gcc -c gamePrinter.c

userControl.o: userControl.h userControl.c
	gcc -c userControl.c

main.o: gamePrinter.h   main.c
	gcc -c main.c

main: gamePrinter.o  userControl.o  main.o
	gcc gamePrinter.o userControl.o main.o -o main
