#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include "Board.h"
#include "Container.h"
#include "Shape.h"

class Game {			//game class. should have render, update/events, quit and initialize.

public:
	Game(int screenwidth, int screenheight, const std::string& title, int framerate);	//game constructor
	Game &operator=(Game &other) = delete;				//prevent assigning game object
	Game(const Game& other) = delete;					//no deep copying a game object
	Game(Game &&other) = delete;						//no moving game object
	~Game();

	void main_menu();
	void update();					//update logic
	void render();					//render
	bool quit();					//quit the window


private:
	sf::Event event;					//events class
	sf::RenderWindow createwindow;		//windows class
	Board board;
	Container container;
	Shape shape;

	static constexpr int FrameTimer = 17;
	int FrameCounter = 0;						//frame counter
	bool quitgame = false;			//quit game
	bool MainMenu = true;

	
	
	
	
	bool GameOver = false;				//gameover boolean


};