all: clean build run
build:
	g++ -o main main.cpp
run:
	clear
	./main
clean:
	rm -f main