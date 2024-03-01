test: main.cpp Player.cpp Referee.cpp Human.cpp Computer.cpp
	g++ main.cpp Player.cpp Referee.cpp Human.cpp Computer.cpp -o test

make main: test
	./test