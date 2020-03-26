all: parser test

parser: main.cpp helper.o
	g++ -O2 -Wall -I . -o parser main.cpp helper.o -lpthread

test: Test.cpp helper.o
	g++ -O2 -Wall -I . -o test Test.cpp helper.o -lpthread

helper.o:
	g++ -O2 -Wall -I . -c helper.cpp

clean:
	rm -f *.o parser test