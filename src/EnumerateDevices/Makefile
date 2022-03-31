CFLAGS = -std=c++17 -O2 

LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi

all: main

main: main.cpp
	g++ main.cpp $(CFLAGS) $(LDFLAGS) -o main
clean:
	rm -rf main
