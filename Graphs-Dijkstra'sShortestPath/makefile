PROG=program3
P=Planet
G=Galaxy
FLAGS = -Wall -g -std=c++14

all: $(P).o $(G).o $(PROG).o
	g++ $(FLAGS) $(P).o $(G).o $(PROG).o -o $(PROG)

$(PROG).o: $(PROG).cpp
	g++ -c $(FLAGS) $(PROG).cpp -D TEST11 -D TEST12 -D TEST13 -o $(PROG).o 

$(P).o: $(P).cpp $(P).h
	g++ -c $(FLAGS) $(P).cpp -o $(P).o

$(G).o: $(G).cpp $(G).h
	g++ -c $(FLAGS) $(G).cpp -o $(G).o

run: all
	./$(PROG)

memcheck: all
	valgrind --leak-check=full ./$(PROG)

clean:
	rm -rf $(PROG) $(P) $(G) *.o
