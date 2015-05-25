#include "visual.h"
/**
* \file visual.c
* \brief  Fichier regroupant les fonctions graphiques
*
*   Fichier regroupant les fonctions graphiques
*
*/

void pause()
{
	int continuer = 1;
	SDL_Event event;

	while (continuer)
	{
		SDL_WaitEvent(&event);
		switch (event.type)
		{
		case SDL_QUIT:
			continuer = 0;
		}
	}
}

void blit_tab(SDL_Surface** tet, SDL_Surface* screen, int * tab){
	int i, j;
	SDL_Rect positiontet;
	for (i = HIDEN_Y_CASE; i<GAME_SIZE_Y; i++){
		for (j = 0; j<GAME_SIZE_X; j++){
			if (tab[i*GAME_SIZE_X + j] > 0){
				positiontet.x =POS_X_PLA + TET_SIZE * j;
				positiontet.y = POS_Y_PLA + TET_SIZE * (i-HIDEN_Y_CASE+1);
				SDL_BlitSurface(tet[tab[i*GAME_SIZE_X + j]-1], NULL, screen, &positiontet);
			}
		}
	}
}

SDL_Surface* write_text(char * text,int color_R,int color_G, int color_B,int size)
{
	SDL_Surface *texte = NULL;
	TTF_Font *police = NULL;
	SDL_Color couleur = { color_R, color_G, color_B };

	TTF_Init();

	/* Chargement de la police */
	police = TTF_OpenFont("arial.ttf", size);
	if (police == NULL){
		texte = SDL_CreateRGBSurface(SDL_HWSURFACE, 10, 10, 32, 0, 0, 0, 0);
		return texte;
	}
	/* Écriture du texte dans la SDL_Surface texte en mode Blended (optimal) */
	texte = TTF_RenderText_Blended(police, text, couleur);


	TTF_CloseFont(police);
	TTF_Quit();


	return texte;
}


void blit_tet(tetri* tetr, SDL_Surface** tet, SDL_Surface* screen, int pos_x, int pos_y){
	int i, j;
	SDL_Rect positiontet;
	for (i = 0; i<4; i++){
		for (j = 0; j<4; j++){
			if (tetr->visual[i][j] > 0){
				positiontet.x =  20 * (tetr->x_pos + j)+pos_x;
				positiontet.y =  20 * (tetr->y_pos + i)+pos_y;
				SDL_BlitSurface(tet[tetr->shape], NULL, screen, &positiontet);
			}
		}
	}
}


/*
void blit_tet(tetri* tetr, SDL_Surface** tet, SDL_Surface* screen, int size_x, int size_y){
	int i, j;
	SDL_Rect positiontet;
	for (i = 0; i<4; i++){
		for (j = 0; j<4; j++){
			if (tetr->visual[(tetr->y_pos + i) * 4 + (tetr->x_pos + j)] >= 0){
				positiontet.x = 4*(tetr->x_pos + j);
				positiontet.y = 4*(tetr->y_pos + i);
				SDL_BlitSurface(tet[tetr->shape], NULL, screen, &positiontet);
			}
		}
	}
}

*/