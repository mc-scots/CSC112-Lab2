CC=g++
CXXFLAGS=--std=c++11 -g
WIDGET_LIB=widget.o term.o application.o keystream.o
SHAPE_LIB=point.o line.o rectangle.o square.o circle.o
TARGETS=shapes

all: $(TARGETS)
shapes: shapes.o canvas.o $(WIDGET_LIB) $(SHAPE_LIB)
point.o: point.h point.cpp
line.o: line.cpp line.h
rectangle.o: rectangle.cpp rectangle.h
square.o: square.cpp square.h
circle.o: circle.cpp circle.h
widget.o: widget.h widget.cpp
term.o: term.h termmanip.h term.cpp
application.o: application.h application.cpp
keystream.o: keystream.h keystream.cpp
clean_all:
	rm -f *.o $(TARGETS)
clean:
	rm -f *.o

