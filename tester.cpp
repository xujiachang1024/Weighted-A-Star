#include "Puzzle8State.h"

#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {
	std::cout << "Start testing..." << std::endl << std::endl;

	// goal state
	Puzzle8State goalState("012345678");
	std::cout << "**Goal State: 012345678**" << std::endl;
	goalState.Print(std::cout);
	std::cout << "H Distance:" << goalState.GetHeuristicDistance() << std::endl;
	std::vector<Puzzle8State> successors_0 = goalState.GenerateSuccessors();
	for (int i = 0; i < successors_0.size(); i++) {
		std::cout << "Successor #" << i << std::endl;
		successors_0[i].Print(std::cout);
	}
	std::cout << std::endl << "****************" << std::endl << std::endl;

	// current state #1
	Puzzle8State currState_1("102345678");
	std::cout << "**Current State #1: 102345678**" << std::endl;
	currState_1.Print(std::cout);
	std::cout << "H Distance:" << currState_1.GetHeuristicDistance() << std::endl;
	std::vector<Puzzle8State> successors_1 = currState_1.GenerateSuccessors();
	for (int i = 0; i < successors_1.size(); i++) {
		std::cout << "Successor #" << i << std::endl;
		successors_1[i].Print(std::cout);
	}
	std::cout << std::endl << "****************" << std::endl << std::endl;

	return 0;
}