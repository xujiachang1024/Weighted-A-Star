// #ifndef PUZZLE_8_STATE_EXTENDED_H
// #define PUZZLE_8_STATE_EXTENDED_H

// #include <vector>

// class Puzzle8StateExtended : public Puzzle8State {

// private:

// 	int cost;
// 	double w;

// 	static bool costComparator(Puzzle8StateExtended state_1, Puzzle8StateExtended state_2) {
// 		double cost_1 = state_1.GetTotalCost();
// 		double cost_2 = state_2.GetTotalCost();
// 		return (cost_1 > cost_2);
// 	}

// public:

// 	Puzzle8StateExtended(std::string s, int cost, double w) : Puzzle8State(s) {
// 		this->cost = cost;
// 		this->w = w;
// 	}

// 	int GetCost() {
// 		return cost;
// 	}

// 	double GetTotalCost() {
// 		double totalCost = this->cost + w * this->GetHeuristicDistance();
// 		return totalCost;
// 	}

// 	// Generate successors
// 	std::vector<Puzzle8StateExtended> GenerateSuccessors() {

// 		std::vector<Puzzle8StateExtended> successors;

// 		// blank ('0') tile's possible neighbors
// 		int dx[] = {1, -1, 0, 0};
// 		int dy[] = {0, 0, 1, -1};

// 		// blank ('0') tile's location[row][col]
// 		int zeroLocation = this->GetLinearizedForm().find('0', 0);
// 		int zeroRow = zeroLocation / 3;
// 		int zeroCol = zeroLocation % 3;

// 		// find blank ('0') tile's valid neighbors
// 		for (int i = 0; i < 4; i++) {

// 			// find possible neighbor's location[row][col]
// 			int adjRow = zeroRow + dx[i];
// 			int adjCol = zeroCol + dy[i];

// 			// validate possible neightbor's location[row][col]
// 			if (adjRow >= 0 && adjRow < 3 && adjCol >= 0 && adjCol < 3) {

// 				// deep copy of the tiles matrix
// 				char copy[3][3];
// 				for (int r = 0; r < 3; r++) {
// 					for (int c = 0; c < 3; c++) {
// 						copy[r][c] = tiles[r][c];
// 					}
// 				}

// 				// swap zero and its neighbor
// 				copy[zeroRow][zeroCol] = copy[adjRow][adjCol];
// 				copy[adjRow][adjCol] = '0';

// 				// convert the copy matrix to a std::string
// 				std::string s = "";
// 				for (int r = 0; r < 3; r++) {
// 					for (int c = 0; c < 3; c++) {
// 						s += copy[r][c];
// 					}
// 				}

// 				// add a new successor
// 				Puzzle8StateExtended successor(s, this->cost + 1, this->w);
// 				successors.push_back(successor);
// 			}
// 		}

// 		// sort successors from least possible option to most possible option
// 		std::sort(successors.begin(), successors.end(), costComparator);

// 		return successors;
// 	}
// };

// #endif
