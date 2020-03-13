#pragma once
#include "board.h"
#include "Container.h"
#include "Location.h"
#include "TetrominoPatterns.h"
#include <random>
#include <unordered_map>

class Shape {

public:

	Shape(const Board& board);	//construct shape object
	void initShape();			//iniitalizethe shape type
	void lockShape(Board& board, const Container& container, sf::RenderWindow& createwindow);	//lock th shpae into position
	void CollisionMapVectorStatus(Board& board, const Container& container);		//updates the colision map vector
	void removeRow(Board& board, const Container& container);		//removes the row
	void drawShape(Board& board, const Container &container, sf::RenderWindow &createwindow);		//draw the shape of the tetromino
	bool CollisionCheck(Location delta_loc, const Container& container, Board& board);
	void moveShape(Location delta_loc);			//move shape by delta_loc
	void rotateShape();			//rotate shape
	bool GameOverCheck(const Container& container, const Board& board);
	Location GetShapeLoc() const;
	


private:
	TetrominoPatterns tetrominos;		//get the tetrominos

	std::unordered_map<int, sf::Color> LockShapeMap;	//this mpa is used to determine the colout to be filled when a shape is locked

	Location ShapeLoc;			//initialzie the array location for the top left corner
	std::mt19937 rng;			//rng 
	std::uniform_int_distribution<int> ShapeType;	//distrubition int for shape type needed.
	int ShapeNumber;				//shape number for rotated piece purposes.
	int initShapeNumber;		//initializes the rotation number for a shape
	int rotationCounter = 0;			//stores the current rotation postion for th tetris block
	

	std::vector<std::vector<std::vector<int>>> Tetrominos;			//tetrominos shape (3D vector to store initial shapes)
	std::vector<int> CollisionMapVector;							//maps the collisino vector. Marks one for collided, zero if not collided
	std::vector <sf::Color> colorVector;		//stores a vector of colours.

};