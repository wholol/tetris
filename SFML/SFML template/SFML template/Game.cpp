#include "Game.h"
#include <iostream>

Game::Game(int screenwidth, int screenheight, const std::string& title, int framerate)
	:createwindow(sf::VideoMode(screenwidth, screenheight), title),
	board(screenwidth,screenheight),
	shape(board)
	
{}


void Game::render() {		//rendering

	

		container.DrawContainer(board, createwindow);
		shape.drawShape(board, container, createwindow);
		shape.lockShape(board, container, createwindow);
		

	
	createwindow.display();
	
}

void Game::main_menu()
{
	
}

void Game::update() {		//update game 

	++FrameCounter;
	
	
	
if (FrameCounter >= FrameTimer) {			//process logic here

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {		//rotate shape is enter is pressed
		shape.rotateShape();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {		//if the left key is pressed.
		if (!shape.CollisionCheck({ -1 , 0 }, container,board)) {		//checks for collision for the next pos
			shape.moveShape({ -1 , 0 });
		}
	}
			
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		if (!shape.CollisionCheck({ 1 , 0 }, container,board)) {
			shape.moveShape({ 1 , 0 });
		}
	}

	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::))

	if (!shape.CollisionCheck({ 0 , 1 }, container,board)) {		//check for downward collision
		shape.moveShape({ 0 , 1});			
	}
	else {		//is collision occured
		
		shape.CollisionMapVectorStatus(board, container);		//update the collsiino map vector as it is not falling downwards anymore.
		shape.removeRow(board, container);
		shape.initShape();		//initialize the shape

		
	}
			
		FrameCounter = 0;
	}
	createwindow.clear();
	//shape.undrawShape(board, container, createwindow);		//undraw the previous tetris shape	

	
}


bool Game::quit()			//call quit game

//DO NOT DELETE CONTENTS OF THIS FUNCTION TO PREVENT AN UNRESPONSIV SCREEN//
{
	while (createwindow.pollEvent(event)) {		//NON BLOCKING FUNCTION, WILL NOT GET STUCK IN WHILE LOOP.
		if (event.type == sf::Event::Closed) {
			createwindow.close();
			quitgame = true;
		}
	}
	return quitgame;
	
}

Game::~Game()	{
	std::cout << " Game destructor called" << std::endl;
}