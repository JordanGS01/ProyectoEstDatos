#ifndef Game_hpp
#define Game_hpp

#include <SDL.h>
#include <stdio.h>

//This is the Game class, used to simplify the functions that we're going to use in our project

class Game {

	//Methods
public:
	void init(const char* title, int xpos, int ypos, int width, int height);

	void handleEvents();
	void update();
	void render();
	void clean();

	bool running() { return isRunning; };

private:
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;

};
#endif 
