#ifndef PUZZLE_8_SOLVER_H
#define PUZZLE_8_SOLVER_H

#include "Puzzle8Solver.h"
#include "Puzzle8PQ.h"
#include "Puzzle8State.h"
#include "Puzzle8StateExtended.h"
#include "Puzzle8StateManager.h"
#include <string>
#include <stack>

void WeightedAStar(std::string puzzle, double w, int & cost, int & expansions);

// search function prototype
// int dfs(double w, Puzzle8StateManager & manager, Puzzle8State state, double & bound, int cost, int & expansions);
// double search(Puzzle8StateManager & manager, std::stack<Puzzle8StateExtended> & path, int cost, int & expansions, double bound);

#endif
