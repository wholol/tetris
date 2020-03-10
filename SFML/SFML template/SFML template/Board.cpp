#include "Board.h"

Board::Board(const int& screenwidth, const int& screenheight)			//construct the board
	:screenheight(screenheight),
	screenwidth(screenwidth)
{
	xTilesNum = screenwidth / CellDimension;		
	yTilesNum = screenheight / CellDimension;

	for (int i = 0; i < xTilesNum * yTilesNum; ++i) {		//for each array	
		grid.emplace_back(sf::Vector2f(CellDimension, CellDimension));	//construct the grids with the dimensions
	}
}

void Board::DrawTiles(int x,int y,sf::RenderWindow& createwindow, const sf::Color &color)
{	

	/* draws the container*/
	grid[x * xTilesNum + y].setPosition(sf::Vector2f(x * CellDimension, y * CellDimension));	//sets the position of the based on the vector 2f struct 
	grid[x * xTilesNum + y].setFillColor(color);			//sets the colour of the rectangle
	grid[x * xTilesNum + y].setOutlineThickness(-outlinethickness);	//negative thickness( outline goes inwards)
	grid[x * xTilesNum + y].setOutlineColor(sf::Color::Black);			
	createwindow.draw((grid[x * xTilesNum + y]));			//gts the pointer for the grid and draw it basd on their coordinates
}


int Board::GetXTilesNum() const
{
	return xTilesNum;
}

int Board::GetYTilesNum() const
{
	return yTilesNum;
}
