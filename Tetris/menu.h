#include "def.h"
#ifndef MENU_H
#define MENU_H


void option_menu(SDL_Surface *ecran, param* settings); //Affiche le menu de selection des options, et retourn a travers param les reglages du jeu
void highscore_menu(SDL_Surface *ecran); // Affiche le menu des highscore
void print_highscore(char *name, int score); // Prend en argument un nom et un score et l'insere dans la liste des highscore
int read_highscore(char *text, int * score); //Lit les highscores du fichier highscore et remplie le tableau text avec les nom, et score avec les score
int reset_highscore(); //Reinitialise les highscores 
int validate_highscore(char * name, int score); //Calcule le hashachage associé à un couple nom/score
void nameinput_menu(SDL_Surface * ecran, char *name); //Affiche le menu de saisie du nom du joueur name doit etre un tableau de 10 char, le nom doit faire moins de 5 char
int game(param *settings, SDL_Surface * ecran); // Lance une partie sur ecran, avec les parametres settings
int main_menu(); //Gere le menu principal

#endif