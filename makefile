test: *.cpp
	g++ -std=c++20 -o main.out -O2 -Wall *.cpp

make main: test
	./main.out