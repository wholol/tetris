#include "TetrominoPatterns.h"

TetrominoPatterns::TetrominoPatterns() {
	Tetrominos = {

		//0 degrees

		{{0,0,0,1},			//L shape				
		{0,1,1,1},
		{0,0,0,0},
		{0,0,0,0}},

		{{0,0,0,0},			//S Shape tetromino ////initialize ypos to -1		 
		{0,0,1,1},
		{0,1,1,0},
		{0,0,0,0}},

		{{0,0,0,0},			//T Shape tetromino //initialize ypos to -1		
		{0,0,1,0},
		{0,1,1,1},
		{0,0,0,0}},

		{{0,0,0,0},			//I shape ////initialize ypos to -1				
		{0,1,1,1},
		{0,0,0,0},
		{0,0,0,0}},

		{{1,0,0,0},			//J shape									
		{1,1,1,0},
		{0,0,0,0},
		{0,0,0,0}},

		{{0,0,0,0},			//Z Shape tetromino		
		{0,1,1,0},
		{0,0,1,1},
		{0,0,0,0}},

		{{0,0,0,0},			//O shape		
		{0,1,1,0},
		{0,1,1,0},
		{0,0,0,0}},

		//90 degrees//


		{{0,0,1,0},			//L shape				
		{0,0,1,0},
		{0,0,1,1},
		{0,0,0,0}},

		{{0,0,0,0},			//S Shape tetromino 
		{0,0,1,0},
		{0,0,1,1},
		{0,0,0,1}},

		{{0,0,0,0},			//T Shape tetromino 
		{0,0,1,0},
		{0,0,1,1},
		{0,0,1,0}},

		{{0,0,1,0},			//I shape 			
		{0,0,1,0},
		{0,0,1,0},
		{0,0,0,0}},

		{{0,1,1,0},			//J shape									
		{0,1,0,0},
		{0,1,0,0},
		{0,0,0,0}},

		{{0,0,0,0},			//Z Shape tetromino		
		{0,0,0,1},
		{0,0,1,1},
		{0,0,1,0}},

		{{0,0,0,0},			//O shape		
		{0,1,1,0},
		{0,1,1,0},
		{0,0,0,0}},

		// 180 degrees

		{{0,0,0,0},			//L shape				
		{0,1,1,1},
		{0,1,0,0},
		{0,0,0,0}},

		{{0,0,0,0},			//S Shape tetromino ////initialize ypos to -1		 
		{0,0,0,0},
		{0,0,1,1},
		{0,1,1,0}},

		{{0,0,0,0},			//T Shape tetromino //initialize ypos to -1		
		{0,0,0,0},
		{0,1,1,1},
		{0,0,1,0}},

		{{0,0,0,0},			//I shape ////initialize ypos to -1				
		{0,1,1,1},
		{0,0,0,0},
		{0,0,0,0}},

		{{0,0,0,0},			//J shape									
		{1,1,1,0},
		{0,0,1,0},
		{0,0,0,0}},

		{{0,0,0,0},			//Z Shape tetromino		
		{0,0,0,0},
		{0,1,1,0},
		{0,0,1,1}},

		{{0,0,0,0},			//O shape		
		{0,1,1,0},
		{0,1,1,0},
		{0,0,0,0}},
		
		
		//270 degrees
		
		
		{{0,1,1,0},			//L shape				
		{0,0,1,0},
		{0,0,1,0},
		{0,0,0,0}},

		{{0,0,0,0},			//S Shape tetromino 		 
		{0,1,0,0},
		{0,1,1,0},
		{0,0,1,0}},

		{{0,0,0,0},			//T Shape tetromino 	
		{0,0,1,0},
		{0,1,1,0},
		{0,0,1,0}},

		{{0,0,1,0},			//I shape 		
		{0,0,1,0},
		{0,0,1,0},
		{0,0,0,0}},

		{{0,1,0,0},			//J shape									
		{0,1,0,0},
		{1,1,0,0},
		{0,0,0,0}},

		{{0,0,0,0},			//Z Shape tetromino		
		{0,0,1,0},
		{0,1,1,0},
		{0,1,0,0}},

		{{0,0,0,0},			//O shape		
		{0,1,1,0},
		{0,1,1,0},
		{0,0,0,0}}
	
	};
	
}

std::vector<std::vector<std::vector<int>>> TetrominoPatterns::getTetrominoPatterns() const {		//gt the tetrominos
	return Tetrominos;
}