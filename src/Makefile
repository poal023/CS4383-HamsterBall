CXX = g++

OBJFILES = vec3.o mat4x4.o main.o
CXXFLAGS = -Wall -ggdb

LIBFLAGS = -lm
BINNAME = projectPart1

all: matExec

matExec : main.o vec3.o mat4x4.o
	$(CXX) $(CXXFLAGS) $(LIBFLAGS) $(OBJFILES) -o $(BINNAME)

main.o : main.cpp
	$(CXX) -c -ggdb main.cpp -o main.o

mat4x4.o : Mat4x4/Mat4x4.cpp Mat4x4/Mat4x4.h
	$(CXX) -c Mat4x4/Mat4x4.cpp -o mat4x4.o
vec3.o : Vector3/Vector3.cpp Vector3/Vector3.h
	$(CXX) -c Vector3/Vector3.cpp -o vec3.o
clean:
	rm -rf $(OBJFILES) $(BINNAME)
