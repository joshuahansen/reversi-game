all:
	gcc -ansi -Wall -pedantic reversi.c utility.c gameboard.c scoreboard.c player.c game.c -o reversi.exe

gameboard:
	gcc -ansi -Wall -pedantic reversi.c utility.c gameboard.c -o reversi.exe

scoreboard:
	gcc -ansi -Wall -pedantic reversi.c utility.c scoreboard.c -o reversi.exe

gameandscore:
	gcc -ansi -Wall -pedantic reversi.c utility.c scoreboard.c gameboard.c -o reversi.exe
clean:
	rm reversi.exe

debug:
	gcc -ansi -Wall -pedantic -g *.c -o reversi.exe
