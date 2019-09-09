CFLAGS=-Wall -Wextra -DDEBUG -g -std=c++14 -c
CFLAGS2=-Wall -Wextra -DDEBUG -g -std=c++14
P=lab6
T=BSTree

all: $(P).o
	g++ $(CFLAGS2) $(P).o -o $(P)
$(P).o: $(T).h $(P).cpp
	g++ $(CFLAGS) $(P).cpp
run: all
	./$(P)
clean:
	rm -rf $(P) *.o
memcheck:
	valgrind --track-origins=yes --leak-check=full ./$(P)
