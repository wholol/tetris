#pragma once
#include "Board.h"

//draws the container for tetris

class Container {

public:
	void DrawContainer(Board& board, sf::RenderWindow &createwindow);		//draw container of board

	int GetxPosLeftLimit() const;				//x coordinates of the container to the left
	int GetxPosRightLimit() const;				//x coordinate of the container to the right
	int GetyPosTopLimit() const;				//y coordinate of the container to the top
	int GetyPosBottomLimit() const;				//y coordinate of the container to th bottom
	int GetContainerHeight() const;				//gets the height of the container
	int GetContainerWidth() const;				//gets the width of the container


private:

	static constexpr int ContainerWidth = 10;		//sets the width of the container
	static constexpr int ContainerHeight = 23;		//sets the height of the container
	static constexpr int yPosTopLimit = 5;			//top location/coordiante for the container


	int xPosLeftLimit;		//limit for x position fr the right side of the container
	int xPosRightLimit;		//limit for x position for the left side of the container
	int yPosBottomLimit;	//limit for y position for the bottom of the container
	
};
