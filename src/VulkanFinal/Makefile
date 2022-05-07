CXX = g++

BINNAME = vktest

CFLAGS = -std=c++17 -O3 -I$(STB_INCLUDE_PATH) -I$(TINYOBJ_INCLUDE_PATH)

LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi
STB_INCLUDE_PATH = includes/stb
TINYOBJ_INCLUDE_PATH = includes/tinyobjloader

all: exec

exec: main.cpp
	$(CXX) $(CFLAGS) $(LDFLAGS) main.cpp  -o $(BINNAME)

clean:
	rm -rf main.o $(BINNAME)
