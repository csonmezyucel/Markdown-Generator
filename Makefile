# Makefile for Markdown Generator by Cevat Sonmez Yucel

all: MD clean
CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall # Enable all warnings
DEBUG=-g

OBJECTS = MD.cpp main.cpp

MD: $(OBJECTS)
		$(CXX) $(DEBUG) $(OBJECTS) $(CXXFLAGS)



.PHONY: clean
clean:
	-rm -f *.o *~ MD
