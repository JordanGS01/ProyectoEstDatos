#include <iostream>
#include <SDL.h>

#include "GameClass.h"

Game* game = NULL;

using namespace std;


int main(int argc, char* argv[]) {
	//Inicialization of SDL
	game = new Game();
	game->init("GameName",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,800,600);

	//This is the game loop
	while (game->running()) {

		game->handleEvents();
		game->update();
		game->render();
	}

	game->clean();


	return 0;
}