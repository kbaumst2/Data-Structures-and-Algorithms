PROG=program2
F1=Planet
F2=Parser
F3=Heap
F4=Scanner
FLAGS = -Wall -g -std=c++14

all: $(F1).o $(F2).o $(F4).o $(PROG).o
	g++ $(FLAGS) $(F1).o $(F2).o $(F4).o $(PROG).o -o $(PROG)

$(PROG).o: $(PROG).cpp $(F1).h $(F2).h $(F3).h
	g++ -c $(FLAGS) $(PROG).cpp -o $(PROG).o

$(F1).o: $(F1).cpp $(F1).h
	g++ -c $(FLAGS) $(F1).cpp -o $(F1).o

$(F2).o: $(F2).cpp $(F2).h $(F1).h
	g++ -c $(FLAGS) $(F2).cpp -o $(F2).o

$(F4).o: $(F4).cpp $(F4).h $(F3).h $(F2).h $(F1).h
	g++ -c $(FLAGS) $(F4).cpp -o $(F4).o

run: all
	./$(PROG)

memcheck: all
	valgrind --leak-check=full ./$(PROG)

clean:
	rm -rf $(PROG) $(F1) $(F2) *.o
