CXX = g++

BINNAME = vktest

CFLAGS = -std=c++17 -O2 

LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi

all: exec

exec: main.cpp
	$(CXX) $(CFLAGS) $(LDFLAGS) main.cpp  -o $(BINNAME)

clean:
	rm -rf main.o $(BINNAME)
