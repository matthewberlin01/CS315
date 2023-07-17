
game.x:  main.o getChar.o worm.o screen.o freePool.o food.o
	g++ -ggdb -o game.x main.o getChar.o worm.o screen.o freePool.o food.o -lcurses -ltermcap

main.o: main.cpp Worm.hpp Screen.hpp Food.hpp freePool.hpp
	g++ -c -ggdb main.cpp -o main.o

getChar.o: getChar.cpp 
	gcc -c -ggdb getChar.cpp -o getChar.o
	
worm.o: Worm.cpp Worm.hpp
	g++ -ggdb Worm.cpp -o worm.o -c

screen.o: Screen.cpp Screen.hpp
	g++ -ggdb Screen.cpp -o screen.o -c

freePool.o: freePool.cpp freePool.hpp
	g++ -c -ggdb freePool.cpp -o freePool.o -c

food.o: Food.cpp Food.hpp
	g++ -ggdb Food.cpp -o food.o -c

clean:
	/bin/rm -f game.x main.o getChar.o worm.o screen.o freePool.o food.o
