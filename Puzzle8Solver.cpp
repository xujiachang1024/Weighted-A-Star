#include "Puzzle8Solver.h"
#include "Puzzle8State.h"
#include "Puzzle8StateManager.h"

#include <limits>
#include <cstddef>
#include <vector>

using namespace std;

/*
 * @para puzzle: input puzzle represented in linearized form as a string
 * @para w: weight assigned to the heuristic function
 * @para cost: solution cost (a.k.a. length of the path) of Weighted A*
 * @para expansions: number of expansions made by Weighted A*
 */
void WeightedAStar(std::string puzzle, double w, int & cost, int & expansions) {
	cost = 0;
	expansions = 0;

	// TODO

	// Create the Puzzle8StateManager
	Puzzle8StateManager manager;
	manager.Reset();
	
	// Initialize the goal & current Puzzle8State
	const std::string GOAL_STR = "012345678";
	Puzzle8State currState(puzzle);

	// Start heuristic search...
	while (currState.GetLinearizedForm() != GOAL_STR) {

		// generate successors
		std::vector<Puzzle8State> successors = currState.GenerateSuccessors();
		expansions += successors.size();

		// find the optimal successor
		double minimumCost = std::numeric_limits<double>::max();
		Puzzle8State optimalSuccessor("000000000");
		for (int i = 0; i < successors.size(); i++) {

			// calculate the total cost of one successor
			Puzzle8State successor = successors[i];
			double totalCost = cost + w * successor.GetHeuristicDistance();

			// validate minimum cost and unvisited node
			if (totalCost < minimumCost && manager.IsGenerated(successor) == false) {
				minimumCost = totalCost;
				optimalSuccessor = successor;
			}
		}

		// validate dead end
		if (optimalSuccessor.IsEmpty()) {
			cost = -1;
			expansions = -1;
			break;
		}
		else {
			currState = optimalSuccessor;
			manager.GenerateState(optimalSuccessor);
			cost++;
		}
	}
}