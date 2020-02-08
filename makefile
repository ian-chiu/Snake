all: main.cpp
	g++ *.cpp -lcurses 

clean:
	rm -f main.exe
