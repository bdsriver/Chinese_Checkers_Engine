run:
	g++ -std=c++23 src/eval.cpp src/play.cpp src/main.cpp src/transpositionTable.cpp src/board.cpp
	./a.out

build:
	g++ -std=c++23 -g src/eval.cpp src/play.cpp src/main.cpp src/transpositionTable.cpp src/board.cpp

backend-build:
	g++ -std=c++23 src/board.cpp src/eval.cpp src/interface.cpp src/transpositionTable.cpp src/bots.cpp -o engine

backend-run:
	g++ -std=c++23 src/board.cpp src/eval.cpp src/interface.cpp src/transpositionTable.cpp src/bots.cpp -o engine
	./engine