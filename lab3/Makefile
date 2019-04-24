CXX=g++
CXXFLAGS=-Wall -g -std=c++11 -Wdeprecated

Program : *.cpp 
	$(CXX) $(CXXFLAGS) *.cpp 

.PHONY: clean

clean:
	rm -f *.o a.out *.h.gch
	rm -r a.out.dSYM/