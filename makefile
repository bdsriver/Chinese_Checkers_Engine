run:
	g++ -std=c++23 -fopenmp -g src/*.cpp
	./a.out
	python3 data/graph_plotting.py
	python3 data/old_graph_plotting.py

build:
	g++ -std=c++23 -fopenmp -g src/*.cpp 