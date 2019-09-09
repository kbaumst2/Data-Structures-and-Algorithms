#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <set>
#include <vector>
#include "Heap.h"
#include "Heap.h"
#include "Parser.h"
#include "Parser.h"
#include "Planet.h"
#include "Planet.h"
#include "Scanner.h"
#include "Scanner.h"

using namespace std;

// Returns true if arr[i..n-1] represents a max-heap
template <class T>
bool isHeap(vector<T> arr, unsigned int i){
	if(arr.size() <= 1 || i >= (arr.size() - 2)/2)
       return true;
   if (arr.at(i) >= arr.at((2*i) + 1) && arr.at(i) >= arr.at((2*i) + 2) &&
       	isHeap(arr, 2*i + 1) && isHeap(arr, 2*i + 2))
       return true;

   return false;
}

template <class T>
bool verifyHeap(Heap<T> heap){
    T prev = heap.getPriority();
	while(heap.size() > 0){
		T next = heap.getPriority();
		if(next > prev)
			return false;
		else
			prev = next;
        assert(isHeap(heap.getArray(), 0));
	}
	return true;
}

int main(){
	srand(unsigned(time(0)));

#ifndef TEST0
    {
    	cerr << "\n\tTEST #0: Planet class interface" << endl;
    	Planet p1("Test", 90.0);
        assert(p1.getName() == "Test");
        assert(p1.getProbability() == 90.0);
        assert(p1.refine(10.0) == 100.0);
        assert(p1.refine(10.0) == 100.0);
        assert(p1.refine(-10.0) == 90.0);
        assert(p1.refine(-100.0) == 0.0);
        Planet p2("Test", 100.0);
        assert(p1 < p2);
        assert(p2 > p1);
        assert(p1 <= p2);
        assert(p2 >= p1);
        assert(!(p1 == p2));
        assert(p1 != p2);
    	cerr << "\n\t========================PASS========================\n" << endl;
    }
#endif
#ifndef TEST1
    {
    	cerr << "\n\tTEST #1: Missing file handled" << endl;
    	Parser test1("empty.txt");
    	cerr << "\n\t========================PASS========================\n" << endl;
    }
#endif
#ifndef TEST2
    {
	    cerr << "\n\tTEST #2: Create Planets from the file" << endl;
	    Parser parse("test.dat");
        vector<Planet> p = parse.getPlanets();
        assert(p.size() == 12);
        for(auto i : p){
            assert(i.getName() == "Kepler-1049b" ||
                i.getName() == "HAT-P-27b" ||
                i.getName() == "HD116029b" ||
                i.getName() == "WASP-21b" ||
                i.getName() == "GJ649b" ||
                i.getName() == "BD+144559b" ||
                i.getName() == "XO-3b" ||
                i.getName() == "CoRoT-9b" ||
                i.getName() == "7CMab" ||
                i.getName() == "K2-3b" ||
                i.getName() == "upsilonAndd" ||
                i.getName() == "Kepler-1098b"
            );
        }
        cerr << "\n\t========================PASS========================\n" << endl;
    }
#endif
#ifndef TEST3
    {
    	cerr << "\n\tTEST #3: Heap is empty" << endl;
        Heap<char> test;
    	assert(test.empty());
    	cerr << "\n\t========================PASS========================\n" << endl;

    }
#endif
#ifndef TEST4
    {
    	cerr << "\n\tTEST #4: Elements stored in correct order in the heap" << endl;
        vector<int> v;
        for(int i = 0; i < 10; i++) v.push_back(i);
        Heap<int> test(v);
        verifyHeap(test);
    	cerr << "\n\t========================PASS========================\n" << endl;
    }
#endif
#ifndef TEST5
    {
    	cerr << "\n\tTEST #5: Can add elements to the heap" << endl;

        Heap<char> test;
        for(char i = 'A'; i <= 'Z'; i++) {
            test.addElement(i);
            verifyHeap(test);
        }

	    cerr << "\n\t========================PASS========================\n" << endl;
    }
#endif
#ifndef TEST6
    {
    	cerr << "\n\tTEST #6: Scanner class interface" << endl;
        Parser parse("test.dat");
        vector<Planet> planets = parse.getPlanets();
        Planet test = planets.back();
        Scanner scanner(planets);
        verifyHeap(scanner.getHeap());
        scanner.addPlanet(test);
        verifyHeap(scanner.getHeap());
        int dupes = 0;
        vector<Planet> heap = scanner.getHeap().getArray();
        for(auto i = heap.begin(); i < heap.end(); i++){
            for(auto j = i+1; j < heap.end(); j++){
                if(i->getName() == j->getName()){
                    dupes++;
                }
            }
        }
        assert(dupes == 1);
    	cerr << "\n\t========================PASS========================\n" << endl;
    }
#endif
#ifndef TEST7
    {
    	cerr << "\n\tTEST #7: Scan planets" << endl;
        Parser parse("test.dat");
        vector<Planet> planets = parse.getPlanets();
        Scanner scanner(planets);
        verifyHeap(scanner.getHeap());
        vector<Planet> refined = scanner.scan(planets.size());
        assert(scanner.getHeap().empty());
        assert(refined.size() == planets.size());
        for(auto i : planets){
            for(auto j : refined){
                if(i.getName() == j.getName()){
                    assert(i.getProbability() == j.getProbability() + 1 ||
                            i.getProbability() == j.getProbability() - 1);
                }
            }
        }
    	cerr << "\n\t========================PASS========================\n" << endl;
    }
#endif
#ifndef TEST8
    {
        cerr << "\n\tTEST #8: Scan planets where all have the same probability" << endl;
        Parser parse("test2.dat");
        vector<Planet> planets = parse.getPlanets();
        Scanner scanner(planets);
        verifyHeap(scanner.getHeap());
        while(!scanner.getHeap().empty()){
            vector<Planet> refined = scanner.scan(3);
            for(auto p: refined)
                assert(p.getProbability() == 0.0);
        }
        cerr << "\n\t========================PASS========================\n" << endl;
    }
#endif
#ifndef TEST9
    {
        cerr << "\n\tTEST #9: Scan and refine planets until at least one planet is 100%" << endl;
        Parser parse("test.dat");
        vector<Planet> planets = parse.getPlanets();
        Scanner scanner(planets);
        bool life_found = false;
        while(!life_found){
            vector<Planet> refined = scanner.scan(1);
            if(refined.front().getProbability() == 100.0){
                cerr << "\tLife found on " << refined.front().getName() << "!" << endl;
                life_found = true;
            }else if(refined.front().getProbability() != 0.0){
                scanner.addPlanet(refined.front());
            }else if(scanner.getHeap().empty()){
                cout << "There is a very slight possibility of this happening. If you see this message more than once in a row, there is something wrong with your code." << endl;
                assert(false);
            }
        }
    	cerr << "\n\t========================PASS========================\n" << endl;
    }
#endif
#ifndef TEST10
    {
        cerr << "\n\tTEST #10: Scan a large planet dataset until at least one planet is 100% for 10 simulations (may take up to 30 seconds when running with valgrind)" << endl;
        vector<string> found;
        Parser parse("exoplanets.dat");
        vector<Planet> planets = parse.getPlanets();
        Scanner scanner(planets);
        assert(verifyHeap(scanner.getHeap()));
        for(int i = 0; i < 20; i++){
            bool life_found = false;
            unsigned int iters = 0;
            while(!life_found){
                vector<Planet> refined = scanner.scan(1);
                iters++;
                if(refined.front().getProbability() == 100.0){
                    cerr << "\t After refining probabilities " << iters << " times ";
                    cerr << "life found on " << refined.front().getName() << "!" << endl;
                    life_found = true;
                    found.push_back(refined.front().getName());
                }else if(refined.front().getProbability() != 0.0){
                    scanner.addPlanet(refined.front());
                }else if(scanner.getHeap().empty()){
                    cout << "There is a very slight possibility of this happening. Run your code again. If you see this message more than once in a row, there is probably something wrong with your code." << endl;
                    assert(false);
                }
            }
        }
        set<string> test(found.begin(), found.end());
        cerr << "\tNumber of duplicate results: " << found.size() - test.size() << endl;
        assert(found.size() - test.size() < 3);
    	cerr << "\n\t========================PASS========================\n" << endl;
    }
#endif

//	#################### Your Tests#####################
	cerr << "\n\tTEST #11: Your Test #1" << endl;
	Heap<int> fam;
	for(int i = 0; i <= 5; i++){
		fam.addElement(i);
	}
	vector<int> pirate = fam.getArray();
	assert(fam.left(0, pirate) == 1);
	assert(fam.right(0, pirate) == 2);
	assert(fam.parent(1) == 0);

	cerr << "\n\t========================PASS========================\n" << endl;
    //####################Your Tests#####################//
  cerr << "\n\tTEST #12: Your Test #2" << endl;
	Heap<int> periodicTable;
	int potassium = 'K';
	int oxygen = 'O';
	int hydrogen = 'H';
	periodicTable.addElement(potassium);
	periodicTable.addElement(oxygen);
	periodicTable.addElement(hydrogen);
	vector<int> chemistry = periodicTable.getArray();
	assert(periodicTable.isLeaf(0, chemistry) == false);
	assert(periodicTable.isLeaf(1, chemistry) == true);
	cerr << "\n\t========================PASS========================\n" << endl;
}
