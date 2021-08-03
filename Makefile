# Makefile for Markdown Generator by Cevat Sonmez Yucel
all: MD clean
CXX=clang++

OBJECTS = MD.cpp main.cpp

MD: $(OBJECTS)
		$(CXX) $(OBJECTS)

.PHONY: clean
clean:
	-rm -f *.o *~ MD