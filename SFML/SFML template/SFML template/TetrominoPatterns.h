#pragma once
#include <vector>

class TetrominoPatterns {

public:
	TetrominoPatterns();						//initialize tetromino patterns
	std::vector<std::vector<std::vector<int>>> getTetrominoPatterns() const;			//gets the tetromino position


private:
	std::vector<std::vector<std::vector<int>>> Tetrominos;			//tetrominos shape (3D vector to store initial shapes)



};