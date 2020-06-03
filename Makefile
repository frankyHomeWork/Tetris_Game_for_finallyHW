.PHONY: all clean
clean: 
	del .\\*.o
	del .\\*.exe

all: main

gamePrinter.o: gamePrinter.h gamePrinter.c tetris.h
	gcc -c gamePrinter.c

userControl.o: userControl.h userControl.c gamePrinter.h
	gcc -c userControl.c

gameControler.o: gameControler.h gameControler.c tetris.h gamePrinter.h
	gcc -c gameControler.c

tetris.o: tetris.h tetris.c
	gcc -c tetris.c

main.o: gamePrinter.h userControl.h gameControler.h tetris.h  main.c
	gcc -c main.c

main: gamePrinter.o  userControl.o gameControler.o tetris.o main.o
	gcc gamePrinter.o userControl.o gameControler.o tetris.o main.o -o main
