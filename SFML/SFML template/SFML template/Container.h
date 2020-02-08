#pragma once
#include "Board.h"

//draws the container for tetris

class Container {

public:
	void DrawContainer(Board& board, sf::RenderWindow &createwindow);		//draw container of board

	int GetxPosLeftLimit() const;				//x coordinates of the container to the left
	int GetxPosRightLimit() const;				
	int GetyPosTopLimit() const;
	int GetyPosBottomLimit() const;
	int GetContainerHeight() const;
	int GetContainerWidth() const;


private:

	static constexpr int ContainerWidth = 10;		//sets the width of the container
	static constexpr int ContainerHeight = 23;		//sets the height of the container
	static constexpr int yPosTopLimit = 5;	//top location/coordiante for the container

	int xPosLeftLimit;		//limit for x position fr the right side of the container
	int xPosRightLimit;		//limit for x position for the left side of the container
	int yPosBottomLimit;	//limit for y position for the bottom of the container
	

};
