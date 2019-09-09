L=lab3
S=Star
P=Planet
CFLAGS=-Wall -Wextra -DDEBUG -g -std=c++14

all: $(P).o $(L).o $(S).o 
	g++ $(CFLAGS) $(S).o $(P).o $(L).o  -o $(L)


$(P).o: $(P).cpp $(S).h $(P).h
	g++ $(CFLAGS) -c $(P).cpp

$(S).o: $(S).cpp $(S).h $(P).h
	g++ $(CFLAGS) -c $(S).cpp


$(L).o: $(L).cpp $(S).h $(P).h
	g++ $(CFLAGS) -c $(L).cpp

clean:
	rm -rf $(L) *.o

run: all
	./$(L)

memcheck: all
	valgrind ./$(L)
