#include "Container.h"

void Container::DrawContainer(Board& board,sf::RenderWindow &createwindow)
{
	xPosLeftLimit = ((board.GetXTilesNum() - ContainerWidth) / 2);	//start position of container in x acoordinates
	xPosRightLimit = xPosLeftLimit + ContainerWidth;
	yPosBottomLimit = yPosTopLimit + ContainerHeight;
	
	for (int x = xPosLeftLimit; x <= xPosRightLimit; ++x) {
		board.DrawTiles(x, yPosBottomLimit,createwindow,sf::Color::Red);
	}

	for (int y = yPosTopLimit; y < yPosBottomLimit; ++y) {		//draw container
		board.DrawTiles(xPosLeftLimit, y, createwindow, sf::Color::Red);
	}

	for (int y = yPosTopLimit; y < yPosBottomLimit; ++y) {		//draw container
		board.DrawTiles(xPosRightLimit, y, createwindow, sf::Color::Red);
	}
}

int Container::GetxPosLeftLimit() const
{
	
	return xPosLeftLimit;
}

int Container::GetxPosRightLimit() const
{
	return xPosRightLimit;
}

int Container::GetyPosTopLimit() const
{
	return yPosTopLimit;
}

int Container::GetyPosBottomLimit() const
{
	return yPosBottomLimit;
}

int Container::GetContainerHeight() const
{
	return ContainerHeight;
}

int Container::GetContainerWidth() const
{
	return ContainerWidth;
}
