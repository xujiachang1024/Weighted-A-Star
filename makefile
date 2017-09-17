all:
	g++ -std=c++11 -o 8PuzzleSolver main.cpp Puzzle8Solver.cpp CPUTimer.cpp

tester:
	g++ -std=c++11 -o tester tester.cpp