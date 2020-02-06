all: main.cpp
	g++ *.cpp -lcurses -o main.exe

clean:
	rm -f main.exe
