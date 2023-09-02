CXX=g++

all: build

build:
	$(CXX) -std=c++11 -o main main.cpp barca.cpp individuo.cpp jugador.cpp lugar.cpp orilla.cpp

run:
	@./main