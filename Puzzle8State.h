#ifndef PUZZLE_8_STATE_H
#define PUZZLE_8_STATE_H

#include <string>
#include <cassert>
#include <iostream>
#include <vector>
#include <cmath>

// Represents an 8-puzzle state as a 3x3 array of chars. Each char can take values in range '0'-'9' (chars, not integers).
// '0' represents the blank tile.
// Provides GetKey to uniquely represent the puzzle as an integer (for hashing).
// You can extend this class to generate successors and get heuristic distance to '012345678', which is always the goal state.

class Puzzle8State {
public:

	Puzzle8State(std::string s = "012345678") {
		assert(s.length() == 9);
		for (int r = 0; r < 3; r++)
			for (int c = 0; c < 3; c++)
				tiles[r][c] = s[r*3 + c];
	}

	// Key generated as an integer for the hash function in Puzzle8StateManager.
	int GetKey() {
		int key = 0;
		for (int r = 0; r < 3; r++)
			for (int c = 0; c < 3; c++)
				key = key*10 + int(tiles[r][c] - '0');
		return key;
	}

	// Return the linearized form as a string. (You don't need to use this.)
	std::string GetLinearizedForm () {
		std::string s = "";
		for (int r = 0; r < 3; r++)
			for (int c = 0; c < 3; c++)
				s += tiles[r][c];
		return s;
	}

	// Print the puzzle in a 3x3 layout. (You don't need to use this.)
	void Print(std::ostream & out = std::cout) {
		for (int r = 0; r < 3; r++) {
			for (int c = 0; c < 3; c++) {
				out << tiles[r][c] << " ";
			}
			out<<std::endl;
		}
		out << GetKey() << std::endl;
	}

	// Generate successors
	std::vector<Puzzle8State> GenerateSuccessors() {
		std::vector<Puzzle8State> successors;
		// blank ('0') tile's possible neighbors
		int dx[] = {1, -1, 0, 0};
		int dy[] = {0, 0, 1, -1};
		// blank ('0') tile's location[row][col]
		int zeroLocation = this->GetLinearizedForm().find('0', 0);
		int zeroRow = zeroLocation / 3;
		int zeroCol = zeroLocation % 3;
		// find blank ('0') tile's valid neighbors
		for (int i = 0; i < 4; i++) {
			// find possible neighbor's location[row][col]
			int adjRow = zeroRow + dx[i];
			int adjCol = zeroCol + dy[i];
			// validate possible neightbor's location[row][col]
			if (adjRow >= 0 && adjRow < 3 && adjCol >= 0 && adjCol < 3) {
				// deep copy of the tiles matrix
				char copy[3][3];
				for (int r = 0; r < 3; r++) {
					for (int c = 0; c < 3; c++) {
						copy[r][c] = tiles[r][c];
					}
				}
				// swap zero and its neighbor
				copy[zeroRow][zeroCol] = copy[adjRow][adjCol];
				copy[adjRow][adjCol] = '0';
				// convert the copy matrix to a std::string
				std::string s = "";
				for (int r = 0; r < 3; r++) {
					for (int c = 0; c < 3; c++) {
						s += copy[r][c];
					}
				}
				// add a new successor
				Puzzle8State successor(s);
				successors.push_back(successor);
			}
		}
		return successors;
	}

	// Get heuristic distance to goal state '012345678'
	int GetHeuristicDistance() {
		int totalHeuristicDistance = 0;
		for (int i = 0; i < 9; i++) {
			// goal state
			int goalLocation = i;
			int goalRow = goalLocation / 3;
			int goalCol = goalLocation % 3;
			// current state
			char currChar = '0' + i;
			int currLocation = this->GetLinearizedForm().find(currChar, 0);
			int currRow = currLocation / 3;
			int currCol = currLocation % 3;
			// calculate heuristic (manhattan) distance
			int heuristicDistance = abs(goalRow - currRow) + abs(goalCol - currCol);
			totalHeuristicDistance += heuristicDistance;
		}
		return totalHeuristicDistance;
	}

	bool IsEmpty() {
		bool empty = true;
		for (int r = 0; r < 3; r++) {
			for (int c = 0; c < 3; c++) {
				if (tiles[r][c] != '0') {
					empty = false;
					break;
				}
			}
		}
		return empty;
	}

private:

	// tiles[r][c] is the tile (or blank) at row r (0-2) and column c (0-2)
	// 0th row is the top row, and 0th column is the leftmost column.
	char tiles[3][3];

};

#endif
