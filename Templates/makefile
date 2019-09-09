CFLAGS=-Wall -Wextra -DDEBUG -g -std=c++14
P=lab4
V=Vector
Q=Queue


all: $(P).o 
	g++ $(CFLAGS2) $(P).o -o $(P)
$(P).o: $(P).cpp $(V).h $(Q).h
	g++ $(CFLAGS) -c $(P).cpp
run: all
	./$(P)
clean:
	rm -rf $(P) *.o
memcheck:
	valgrind ./$(P)
