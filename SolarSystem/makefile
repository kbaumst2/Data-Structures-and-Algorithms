CFLAGS=-Wall -Wextra -DDEBUG -g -std=c++14 -c
CFLAGS2=-Wall -Wextra -DDEBUG -g -std=c++14
P=program1
V=Vector
L=List
S=Star
T=Planet

all: $(P).o $(T).o $(V).o $(L).o $(S).o
	g++ $(CFLAGS2) $(P).o $(T).o $(V).o $(L).o $(S).o -o $(P)
$(P).o: $(P).cpp 
	g++ $(CFLAGS) $(P).cpp
$(V).o: $(V).cpp $(V).h
	g++ $(CFLAGS) $(V).cpp
$(L).o: $(L).cpp $(L).h
	g++ $(CFLAGS) $(L).cpp
$(S).o: $(S).cpp $(S).h
	g++ $(CFLAGS) $(S).cpp
$(T).o: $(T).cpp $(T).h
	g++ $(CFLAGS) $(T).cpp
run: all
	./$(P)
clean:
	rm -rf $(P) *.o
memcheck:
	valgrind ./$(P)
