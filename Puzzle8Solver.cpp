#include "Puzzle8Solver.h"
#include "Puzzle8PQ.h"
#include "Puzzle8State.h"
#include "Puzzle8StateManager.h"

#include <limits>
#include <cstddef>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <iostream>

using namespace std;

const std::string GOAL_STATE = "012345678";

/*
 * @para puzzle: input puzzle represented in linearized form as a string
 * @para w: weight assigned to the Manhattan function
 * @para cost: solution cost (a.k.a. length of the path) of Weighted A*
 * @para expansions: number of expansions made by Weighted A*
 */
void WeightedAStar(std::string puzzle, double w, int & cost, int & expansions) {
	cost = 0;
	expansions = 0;

	// TODO

	// Create the Puzzle8StateManager
	Puzzle8StateManager manager;

	// Create the open list Puzzle8PQ
	Puzzle8PQ openList;

	// create the initial Puzzle8State
	Puzzle8State currState(puzzle);

	// loop until reach goal state
	while (currState.GetLinearizedForm() != GOAL_STATE) {

		// generate successors
		std::vector<Puzzle8State> successors = currState.GenerateSuccessors();

		// iterate through each successor
		for (int i = 0; i < successors.size(); i++) {

			// the i-th successor & its weighted heuristic cost
			Puzzle8State successor = successors[i];
			double weightedHeuristic = w * successor.GetManhattanDistance();

			// if the i-th successor state hasn't been visited
			if (manager.IsGenerated(successor) == false) {

				// update the i-th successor's uniform cost
				// successor.cost = currState.cost + 1;
				// calculate the i-th successor's total cost (uniform cost + weighted heuristic cost)
				double totalCost = cost + weightedHeuristic;
				// hash a state ID for the i-th successor
				int stateID = manager.GenerateState(successor);
				// create a PQElement for the i-th successor
				PQElement currElement(stateID, totalCost);
				// store the i-th successor into this PQElement
				currElement.state = successor;
				// push this PQElement into the open list
				openList.push(currElement);
			}
		}

		// increment the count of expansions
		expansions++;
		// read the top PQElement from the open list
		PQElement nextElement = openList.top();
		// remove the top PQElement from the open list
		openList.pop();
		// update the current Puzzle8State
		currState = nextElement.state;
		// update the cost
		cost = currState.cost;
	}


	/*
	// Create a stack of Puzzle8State
	std::stack<Puzzle8State> stack;
	Puzzle8State initState(puzzle, 0, w);
	stack.push(initState);

	// Start depth-first search...
	while (stack.empty() == false) {
		Puzzle8State state = stack.top();
		stack.pop();
		cost = state.GetCost();

		// reach goal state
		if (state.GetLinearizedForm() == GOAL_STATE) {
			break;
		}

		// this state is not discovered yet
		if (manager.IsGenerated(state) == false) {

			// label this state as discovered
			manager.GenerateState(state);

			// generate successors
			std::vector<Puzzle8State> successors = state.GenerateSuccessors();
			expansions += successors.size();

			for (int i = 0; i < successors.size(); i++) {
				stack.push(successors[i]);
			}
		}
	}
	*/

	/*
	// Start Manhattan search...
	while (currState.GetLinearizedForm() != GOAL_STATE) {

		// generate successors
		std::vector<Puzzle8State> successors = currState.GenerateSuccessors();
		expansions += successors.size();

		// find the optimal successor
		double minimumCost = std::numeric_limits<double>::max();
		Puzzle8State optimalSuccessor("000000000");
		for (int i = 0; i < successors.size(); i++) {

			// calculate the total cost of one successor
			Puzzle8State successor = successors[i];
			double totalCost = cost + w * successor.GetManhattanDistance();

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
			//currState.Print();
			manager.GenerateState(optimalSuccessor);
			cost++;
		}
	}
	*/
}

/*
int dfs(double w, Puzzle8StateManager & manager, Puzzle8State state, double & bound, int cost, int & expansions) {

	std::cout << state.GetLinearizedForm() << " | " << cost << " | " << expansions << std::endl;

	if (state.is_goal()) {
		return cost;
	}

	if (cost + w * state.GetManhattanDistance() > bound) {
		// bound = cost + w * state.GetManhattanDistance();
		return -1;
	}

	std::vector<Puzzle8State> successors = state.GenerateSuccessors();
	expansions += successors.size();

	for (int i = 0; i < successors.size(); ++i) {
		Puzzle8State successor = successors[i];
		if (manager.IsGenerated(successor) == false) {
			manager.GenerateState(successor);
			return dfs(w, manager, successor, bound, cost + 1, expansions);
		}
	}
}
*/


/*
double search(Puzzle8StateManager & manager, std::stack<Puzzle8State> & path, int cost, int & expansions, double bound) {

	Puzzle8State node = path.top();
	double f = node.GetTotalCost();

	if (f > bound) return f;
	if (node.is_goal()) return -1.0;

	double min = std::numeric_limits<double>::max();
	std::vector<Puzzle8State> successors = node.GenerateSuccessors();
	expansions += successors.size();

	for (int i = 0; i < successors.size(); ++i) {
		if (manager.IsGenerated(successors[i]) == false) {
			manager.GenerateState(successors[i]);
			path.push(successors[i]);
			double t = search(manager, path, cost + 1, expansions, bound);
			if (t < 0) return -1.0;
			if (t < min && t >= 0) min = t;
			path.pop();
		}
	}

	return min;
}
*/