clean: 
	rm -rf *.exe

all: 
	g++ linked-list.cpp -o linked-list
	./linked-list