PROG=lab7
F1=Trie
FLAGS = -Wall -g -std=c++14

all: $(F1).o $(PROG).o
	g++ $(FLAGS) $(F1).o $(PROG).o -o $(PROG)

$(PROG).o: $(PROG).cpp
	g++ -c $(FLAGS) $(PROG).cpp -o $(PROG).o 

$(F1).o: $(F1).cpp $(F1).h
	g++ -c $(FLAGS) $(F1).cpp -o $(F1).o

run: all
	./$(PROG)

memcheck: all
	valgrind --leak-check=full ./$(PROG)

clean:
	rm -rf $(PROG) $(F1) *.o
