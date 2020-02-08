#include "Board.h"

Board::Board(const int& screenwidth, const int& screenheight)
	:screenheight(screenheight),
	screenwidth(screenwidth)
{
	xTilesNum = screenwidth / CellDimension;
	yTilesNum = screenheight / CellDimension;

	for (int i = 0; i < xTilesNum * yTilesNum; ++i) {	
		grid.emplace_back(std::make_unique<sf::RectangleShape>(sf::Vector2f(CellDimension, CellDimension)));	//construct the grids with the dimensions
	}
}

void Board::DrawTiles(int x,int y,sf::RenderWindow& createwindow, const sf::Color &color)
{	

	/* draws the container*/
	grid[x * xTilesNum + y]->setPosition(sf::Vector2f(x * CellDimension, y * CellDimension));
	grid[x * xTilesNum + y]->setFillColor(color);
	grid[x * xTilesNum + y]->setOutlineThickness(-outlinethickness);
	grid[x * xTilesNum + y]->setOutlineColor(sf::Color::Black);
	createwindow.draw(*(grid[x * xTilesNum + y]).get());
}



int Board::GetXTilesNum() const
{
	return xTilesNum;
}

int Board::GetYTilesNum() const
{
	return yTilesNum;
}
