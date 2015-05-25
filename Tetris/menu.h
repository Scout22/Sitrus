#include "def.h"
#ifndef MENU_H
#define MENU_H
/**
* \file menu.h
* \brief  Fichier regroupant les differents menu
*
*  Fichier regroupant les differents menu
*
*/

void option_menu_general(SDL_Surface *ecran, param* settings);
/**\fn void option_menu_general(SDL_Surface *ecran, param* settings)
*\brief Affiche le menu d'option general: Permet de regler les options de jeux
*\param[in] ecran Pointeur sur un objet de type SDL_Surface: Ecran d'affichage principale
*\param[in] settings Reglage du jeu
**/

void highscore_menu(SDL_Surface *ecran);
/**\fn void highscore_menu(SDL_Surface *ecran)
*\brief Affiche les highscore
**/

void print_highscore(char *name, int score); 
/**\fn void print_highscore(char *name, int score)
*\brief Ecris le highscore dans le fichier a highscore
*\param[in] name Pointeur sur un tableau de char de taille 5 representant le nom
*\param[in] score score a inscrire
**/

int read_highscore(char *text, int * score); 
/**\fn int read_highscore(char *text, int * score)
*\brief Lit les highscores du fichier highscore et remplie le tableau text avec les nom, et score avec les score
**/

int reset_highscore(); 
/**\fn int reset_highscore()
*\brief Reinitialise les highscores 
**/
int validate_highscore(char * name, int score); 
/**\fn  validate_highscore(char * name, int score)
*\brief Calcule la cle associé à un couple nom/score
**/
void nameinput_menu(SDL_Surface * ecran, char *name); 
/**\fn  void nameinput_menu(SDL_Surface * ecran, char *name)
*\brief Affiche le menu de saisie du nom du joueur name doit etre un tableau de 10 char, le nom doit faire moins de 5 char
**/
int game(param *settings, SDL_Surface * ecran); 
/**\fn int game(param *settings, SDL_Surface * ecran)
*\brief Lance une partie sur ecran, avec les parametres settings
**/
int main_menu(); 
/**\fn main_menu()
*\brief Gere le menu principal
**/
#endif