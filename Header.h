#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <iostream>
bool comprobarRecompensa(int coordenada_pj_x, int coordenada_pj_y, int coordenadasRecompensa[3][2], int matriz_juego[20][25], Mix_Chunk* sonido) {
	for (int x_recompensa = 0; x_recompensa < 3; x_recompensa++) {
		if (coordenada_pj_x + 32 >= coordenadasRecompensa[x_recompensa][0] && coordenada_pj_x + 32 <= coordenadasRecompensa[x_recompensa][0] + 32 && coordenada_pj_y + 32 >= coordenadasRecompensa[x_recompensa][1] && coordenada_pj_y + 32 < coordenadasRecompensa[x_recompensa][1] + 32 || coordenada_pj_x >= coordenadasRecompensa[x_recompensa][0] && coordenada_pj_x <= coordenadasRecompensa[x_recompensa][0] + 32 && coordenada_pj_y >= coordenadasRecompensa[x_recompensa][1] && coordenada_pj_y < coordenadasRecompensa[x_recompensa][1] + 32) {
			int f = coordenadasRecompensa[x_recompensa][0] / 32;
			int q = coordenadasRecompensa[x_recompensa][1] / 32;
			matriz_juego[q][f] = 0;
			Mix_PlayChannel(-1, sonido, 0);
			coordenadasRecompensa[x_recompensa][0] = 0;
			coordenadasRecompensa[x_recompensa][1] = 0;
		}
	}

	return false;
}

