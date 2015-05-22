#ifndef VISUAL_H
#define VISUAL_H
#include "def.h"


void pause(); //Met le jeu en pause
void blit_tab(SDL_Surface** tet, SDL_Surface* screen, int * tab); //Prend en entré les differents tetrino, un ecran, le tableau, et affiche le tableau
SDL_Surface* write_text(char * text, int color_R, int color_G, int color_B,int size); //Genere une surface a partir de texte
void blit_tet(tetri* tetr, SDL_Surface** tet, SDL_Surface* screen, int pos_x, int pos_y); //Prend en entré un tetrino, les differents tetrino, un ecran, et affiche le tetrino




#endif // VISUAL_H_INCLUDED
