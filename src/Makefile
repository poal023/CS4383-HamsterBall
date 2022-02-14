CXX = g++

OBJFILES = Vector3.o main.o
CXXFLAGS = -Wall
LIBFLAGS = -lm
BINNAME = vecExec

all: vecExec

vecExec : main.o Vector3.o
	$(CXX) $(CXXFLAGS) $(LIBFLAGS) $(OBJFILES) -o $(BINNAME)

main.o : main.cpp
	$(CXX) -c main.cpp -o main.o

Vector3.o : Vector3.cpp Vector3.h
	$(CXX) -c Vector3.cpp -o Vector3.o
clean:
	rm -rf $(OBJFILES) $(BINNAME)
