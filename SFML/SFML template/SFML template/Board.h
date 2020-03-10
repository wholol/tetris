#pragma once
#include "SFML/Graphics.hpp"
#include <string.h>

class Board {

public:
	Board(const int& screenwidth, const int& screenheight);
	void DrawTiles(int x,int y,sf::RenderWindow& createwindow, const sf::Color &color);
	int GetXTilesNum() const;
	int GetYTilesNum() const;


	
private:

	int xTilesNum;
	int yTilesNum;
	int outlinethickness = 2;

	int screenheight;
	int screenwidth;			
	std::vector<sf::RectangleShape> grid;		//pointer of grids	
	

	static constexpr float CellDimension = 20.0f;


};