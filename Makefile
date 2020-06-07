.PHONY: all clean
clean: 
	del .\\*.o
	del .\\*.exe

all: main

Point.o: Point.h Point.c
	gcc -c Point.c

gamePrinter.o: gamePrinter.h gamePrinter.c tetris.h Point.h
	gcc -c gamePrinter.c

userControl.o: userControl.h userControl.c gameControler.h
	gcc -c userControl.c

gameControler.o: gameControler.h gameControler.c tetris.h gamePrinter.h
	gcc -c gameControler.c

tetris.o: tetris.h tetris.c Point.h
	gcc -c tetris.c

main.o: gamePrinter.h userControl.h gameControler.h tetris.h Point.h main.c
	gcc -c main.c

main: gamePrinter.o  userControl.o gameControler.o tetris.o Point.o main.o 
	gcc gamePrinter.o userControl.o gameControler.o tetris.o Point.o  main.o -o main
