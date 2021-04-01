TARGET=test.cpp

all:
	g++ -pthread $(TARGET)

clean:
	rm a.out
