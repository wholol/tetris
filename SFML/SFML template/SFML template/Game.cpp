#include "Game.h"
#include <iostream>


Game::Game(int screenwidth, int screenheight, const std::string& title, int framerate)
	:createwindow(sf::VideoMode(screenwidth, screenheight), title),
	board(screenwidth,screenheight),
	shape(board)
	
{}


void Game::render() {		//rendering

	if (!GameOver) {
		container.DrawContainer(board, createwindow);
		shape.drawShape(board, container, createwindow);
		shape.lockShape(board, container, createwindow);
		createwindow.display();
	}

		if (shape.GameOverCheck(container, board)) {
			GameOver = true;
		}
	
}

void Game::main_menu()
{
	
}

void Game::update() {		//update game 

	++FrameCounter;
	
	

if (FrameCounter >= FrameTimer) {			//process logic here


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


	if (!shape.CollisionCheck({ 0 , 0.45 }, container,board)) {		//check for downward collision. if no collision occurs
		shape.moveShape({ 0 , 0.45});								//move shape down
	
	}

	else {		//is collision occured
		
		shape.CollisionMapVectorStatus(board, container);		//update the collsiino map vector as it is not falling downwards anymore.
		shape.removeRow(board, container);
		shape.initShape();		//initialize the shape	
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {		//rotate shape is enter is pressed
		Location disable_delta = { -1000 , -1000 };			//disable delta_loc. check shapeloc itself instead
		shape.rotateShape();		//rotate shape first
		if (shape.CollisionCheck(disable_delta, container, board)) {	//if collision occurs
			if (shape.GetShapeLoc().x <= (container.GetContainerWidth() / 2)) {
				std::cout << "wall kick" << std::endl;
				shape.moveShape({ 1 , 0 });		//wall kick
			}

			else {
				shape.moveShape({ -1 , 0 });		//wall kick

			}
		}
	}


	FrameCounter = 0;
	}

	createwindow.clear();
	

	
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