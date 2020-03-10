#include "Shape.h"
#include <iostream>

Shape::Shape(const Board& board)
	:ShapeType(0, 6),	//7 shape types.	//L,S,J,I,T,Z,O
	rng(std::random_device()())		//rng for generating shape.
{		

	for (int i = 0; i < board.GetXTilesNum() * board.GetYTilesNum(); ++i) {
		CollisionMapVector.emplace_back(0);		//initialzie map to 0
	}
	/*COLOR VECTORS FOR EACH SHAPE*/
	colorVector.emplace_back(sf::Color::Yellow);	//L shape color
	colorVector.emplace_back(sf::Color::Cyan);		//S shape color
	colorVector.emplace_back(sf::Color::Green);		//T shape color
	colorVector.emplace_back(sf::Color::Magenta);	//I shape color
	colorVector.emplace_back(sf::Color::Blue);		//J shape color
	colorVector.emplace_back(sf::Color::Red);		//Z shape color
	colorVector.emplace_back(sf::Color::White);		//O shap color

	/*Map insertion construction*/
	int MapShapeNumber = 1;
	int ColorVectorElement = 0;
	
	while (MapShapeNumber < 29) {
		if (ColorVectorElement == 7) {
			ColorVectorElement = 0;
		}

		LockShapeMap.insert(std::make_pair(MapShapeNumber, colorVector[ColorVectorElement]));
		MapShapeNumber += 1;
		ColorVectorElement += 1;
	}


	Tetrominos = tetrominos.getTetrominoPatterns();	//assign Ttrominos vector to the patterns

	ShapeNumber = ShapeType(rng);

	ShapeLoc = { 4 , -4 };		//location of the TOP left array corner
		
}

void Shape::initShape() {
	ShapeLoc = { 4 , -4 };		//restsart the shape 
	ShapeNumber = ShapeType(rng);		//rng the shape number between 5 and 6.
	ShapeRotationNumber = ShapeNumber;
}

void Shape::lockShape(Board& board, const Container& container,sf::RenderWindow& createwindow)
{

	for (int i = 0; i < board.GetXTilesNum(); ++i) {				//draw the tiles onto the board
		for (int j = 0; j < board.GetYTilesNum(); ++j) {
			
			int CollisionVectorNumber = CollisionMapVector[i * board.GetXTilesNum() + j];			//get the number for collistion vector
			auto GetShapeNumber = LockShapeMap.find(CollisionVectorNumber);		//find the number in th map
			
			if (GetShapeNumber == LockShapeMap.end()) {
				//do nothing if the there is no locking
			}

			else {
				board.DrawTiles(i, j, createwindow, GetShapeNumber->second);		//draw the color based on the ShapeNumber
			}
		}
	}
}


void Shape::CollisionMapVectorStatus(Board& board, const Container& container)		//checks the vector for collision possibilities, ( only gets called if the piece cannot move down)
{	
	for (int row = 0; row < Tetrominos[ShapeNumber].size(); ++row) {		
		for (int col = 0; col < Tetrominos[ShapeNumber][row].size(); ++col) {
			if (Tetrominos[ShapeNumber][row][col] == 1) {			//if there is a piece present
				CollisionMapVector[(container.GetxPosLeftLimit() + ShapeLoc.x + col) * (board.GetXTilesNum()) + container.GetyPosTopLimit() + ShapeLoc.y + row] = ShapeNumber + 1;
			}
		}
	}
}



void Shape::removeRow(Board& board, const Container& container)
{
	
	for (int row = container.GetyPosTopLimit(); row <= container.GetyPosBottomLimit(); ++row) {	//each row
		bool RowDetected = true;			//assume that there is a row already
		for (int col = container.GetxPosLeftLimit() + 1; col <= container.GetxPosRightLimit() - 1; ++col) {	//each column
			RowDetected = RowDetected && (CollisionMapVector[col * board.GetXTilesNum() + row] != 0);		//if no space in the particuar line
		}
	
		if (RowDetected)		//if row detected is still true after looping through the columns
		{
			for (int y = row; y >= container.GetyPosTopLimit(); --y) {			//for the current row
				for (int x = container.GetxPosLeftLimit() + 1; x <= container.GetxPosRightLimit() - 1; ++x) {
					CollisionMapVector[x * board.GetXTilesNum() + y] = CollisionMapVector[x * board.GetXTilesNum() + (y - 1)];
				}
			}
			
		}
	}	
}


void Shape::drawShape(Board& board,const Container &container,sf::RenderWindow &createwindow)		//draw shape onto board
{
	for (int row = 0; row < Tetrominos[ShapeNumber].size(); ++row) {
		for (int col = 0; col < Tetrominos[ShapeNumber][row].size(); ++col) {
			if (Tetrominos[ShapeNumber][row][col] == 1) {			// if the tetrominos vector has a one to it
			board.DrawTiles(container.GetxPosLeftLimit() + ShapeLoc.x + col , container.GetyPosTopLimit() + ShapeLoc.y + row , createwindow,colorVector[ShapeNumber]);	//draw it to the screen for movement
			}
		}
	}	
}

bool Shape::CollisionCheck(Location delta_loc,const Container& container,Board& board)
{
	Location CollisionCheck = ShapeLoc;
	CollisionCheck += delta_loc;		//add delta loc = checks th future position for collisions
	for (int row = 0; row < Tetrominos[ShapeNumber].size(); ++row) {
		for (int col = 0; col < Tetrominos[ShapeNumber][row].size(); ++col) {
			if (Tetrominos[ShapeNumber][row][col] == 1) {

				//case 1: hits the conainer walls
				if (container.GetxPosLeftLimit() + CollisionCheck.x + col <= container.GetxPosLeftLimit()
					|| container.GetxPosLeftLimit() + CollisionCheck.x + col >= container.GetxPosRightLimit()
					|| container.GetyPosTopLimit() + CollisionCheck.y + row >= container.GetyPosBottomLimit()) {
					return true;

				}

				//case 2: collision map vector is not zero /i.e. there is a piece where it is trying to go to.
				if (CollisionMapVector[(container.GetxPosLeftLimit() + CollisionCheck.x + col) * (board.GetXTilesNum()) + container.GetyPosTopLimit() + CollisionCheck.y + row] != 0) {
					return true;
				}


			}

		}

	}
	return false;
}

void Shape::moveShape(Location delta_loc)
{
	ShapeLoc += delta_loc;
}

void Shape::rotateShape()
{

	ShapeNumber += 1;
	rotationCounter += 1;

	if (rotationCounter == 4) {		//if the shape goes back to zero degrees
		rotationCounter = 0;
		ShapeNumber = ShapeRotationNumber;		//reset the shape position to zero
	}

}



