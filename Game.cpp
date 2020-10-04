#include "GameClass.h"
#include <iostream>
using namespace std;
//Here we're going to declarate the functions completely


void Game::init(const char* title, int xpos, int ypos, int width, int height){
	//This fuction initialize the game
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		window = SDL_CreateWindow(title, xpos, ypos, width, height,0);

		renderer = SDL_CreateRenderer(window, -1, 0);

		isRunning = true;
	}
	else {//If there is any problem, the program enters here and the game woulnt open
		isRunning = false;
	}
}

void Game::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT://In case that we press the buttom to end the game.
		isRunning = false;
		break;

	default:
		break;
	}
}

void Game::update() {

}

void Game::render() {
	SDL_RenderClear(renderer);
	//Here we'll add thiks to our render.
	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}


