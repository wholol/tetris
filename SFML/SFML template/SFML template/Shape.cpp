#include "Shape.h"


Shape::Shape(const Board& board)
	:ShapeType(0, 6),	//7 shape types.	//L,S,J,I,T,Z,O
	rng(std::random_device()())
{		//construct tetrominos

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
	colorVector.emplace_back(sf::Color::Black);		//when a row is detected
	
	Tetrominos = {


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

		{{0,0,0,0},			//Z Shape tetromino		//initialize ypos to -1
		{0,1,1,0},
		{0,0,1,1},
		{0,0,0,0}},

		{{0,0,0,0},			//O shape		//initialize y pos to -1
		{0,1,1,0},
		{0,1,1,0},
		{0,0,0,0}},
	};

	ShapeNumber = ShapeType(rng);

	ShapeLoc = { 4 , -4 };		//location of the TOP left array corner
		
}

void Shape::initShape() {
	ShapeLoc = { 4 , -4 };		//restsart the shape 
	ShapeNumber = ShapeType(rng);		//rng the shape number
}

void Shape::lockShape(Board& board, const Container& container,sf::RenderWindow& createwindow)
{

	for (int i = 0; i < board.GetXTilesNum(); ++i) {				//draw the tiles onto the board
		for (int j = 0; j < board.GetYTilesNum(); ++j) {

			if (CollisionMapVector[i * board.GetXTilesNum() + j] == 1) {
				board.DrawTiles(i, j, createwindow, colorVector[0]);
			}
			if (CollisionMapVector[i * board.GetXTilesNum() + j] == 2) {
				board.DrawTiles(i, j, createwindow, colorVector[1]);
			}
			if (CollisionMapVector[i * board.GetXTilesNum() + j] == 3) {
				board.DrawTiles(i, j, createwindow, colorVector[2]);
			}
			if (CollisionMapVector[i * board.GetXTilesNum() + j] == 4) {
				board.DrawTiles(i, j, createwindow, colorVector[3]);
			}
			if (CollisionMapVector[i * board.GetXTilesNum() + j] == 5) {
				board.DrawTiles(i, j, createwindow, colorVector[4]);
			}
			if (CollisionMapVector[i * board.GetXTilesNum() + j] == 6) {
				board.DrawTiles(i, j, createwindow, colorVector[5]);
			}
			if (CollisionMapVector[i * board.GetXTilesNum() + j] == 7) {
				board.DrawTiles(i, j, createwindow, colorVector[6]);
			}
		}
	}
}
void Shape::CollisionMapVectorStatus(Board& board, const Container& container)
{	
	for (int row = 0; row < Tetrominos[ShapeNumber].size(); ++row) {
		for (int col = 0; col < Tetrominos[ShapeNumber][row].size(); ++col) {
			if (Tetrominos[ShapeNumber][row][col] == 1) {
				CollisionMapVector[(container.GetxPosLeftLimit() + ShapeLoc.x + col) * (board.GetXTilesNum()) + container.GetyPosTopLimit() + ShapeLoc.y + row] = ShapeNumber + 1;
			}
		}
	}

}

void Shape::rotateShape()
{
	

	
}

void Shape::removeRow(Board& board, const Container& container)
{
	

	for (int row = container.GetyPosTopLimit(); row <= container.GetyPosBottomLimit(); ++row) {	//each row
		bool RowDetected = true;			//assume that there is a row already
		for (int col = container.GetxPosLeftLimit() + 1; col <= container.GetxPosRightLimit() - 1; ++col) {	//each column
			RowDetected = RowDetected && (CollisionMapVector[col * board.GetXTilesNum() + row] != 0);		//if no space in the particuar line
		}
	
		if (RowDetected)		//if row detected is still true after looping through the columns, i.e.. theres a row
		{
			for (int y = row; y >= container.GetyPosTopLimit(); --y) {			//for the current row
				for (int x = container.GetxPosLeftLimit() + 1; x <= container.GetxPosRightLimit() - 1; ++x) {
					CollisionMapVector[x * board.GetXTilesNum() + y] = CollisionMapVector[x * board.GetXTilesNum() + (y - 1)];
				}
			}
			
		}
	
	}
		
}


void Shape::drawShape(Board & board,const Container &container,sf::RenderWindow &createwindow)		//draw shape onto board
{
	for (int row = 0; row < Tetrominos[ShapeNumber].size(); ++row) {
		for (int col = 0; col < Tetrominos[ShapeNumber][row].size(); ++col) {
			if (Tetrominos[ShapeNumber][row][col] == 1) {
			board.DrawTiles(container.GetxPosLeftLimit() + ShapeLoc.x + col , container.GetyPosTopLimit() + ShapeLoc.y + row , createwindow,colorVector[ShapeNumber]);	
			
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

				//case 2: collision map vector is not zero
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



