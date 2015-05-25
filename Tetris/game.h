#ifndef GAME_H
#define GAME_H
#include "def.h"

/**
* \file game.c
* \brief  Fichier regroupant les fonctions du jeu
*
*    Fichier regroupant les fonctions du jeu
*
*/


int is_collison(int *play_tab, tetri* tet); 
/**\fn int is_collision(int *play_tab, tetri* tet)
*\brief verifie si il y eu une collision avec un autre pieces
*\param[in] play_tab Pointeur sur un objet de type tableau d'entier à deux dimension.
*\param[in] tet Pointeur sur un objet de type tetrino
*\return  1 si il y a eu une colision 0 sinon
**/

int reached_top(int*play_tab, tetri* tet);  
/**\fn int reached_top(int*play_tab, tetri* tet)
*\brief Verifdie si une piece a atteint le sommet de l'ecran
*\param[in] play_tab Pointeur sur un objet de type tableau d'entier à deux dimension.
*\param[in] tet Pointeur sur un objet de type tetrino
*\return  1 si il y a eu une colision 0 sinon
**/

void rotate_tet(tetri* tet);
/**\fn void rotate_tet(tetri* tet)
*\brief Rotation dans le sens horraire du tetrino tet
*\param[in] tet Pointeur sur un objet de type tetrino
**/

int is_complete_line(int* play_tab, int *result_tab); 
/**\fn int is_complete_line(int* play_tab, int *result_tab)
*\brief Verifie si des ligne sont pleines, si c'est le cas ecrit 1 dans la case correspondante de result_tab et retourne le nombre de lignes completes
*\param[in] play_tab Pointeur sur un objet de type tableau d'entier à deux dimension.
*\param[out] result_tab Pointeur sur un objet de type tableau à une dimension de taille egale à la hauteur du plateau
*\return  retourne le nombre de ligne pleine
**/

void clear_line(int *play_tab, int ln_num); 
/**\fn void clear_line(int *play_tab, int ln_num);
*\brief Vide la ligne correspondate à ln_num
*\param[in] play_tab Pointeur sur un objet de type tableau d'entier à deux dimension.
*\param[in] ln_num Numero de la ligne a vide
**/

tetri * make_tet(int shape, int posx, int posy);
/**\fn tetri * make_tet(int shape, int posx, int posy)
*\brief Genere un tetrino de forme shape à la position posx posy
*\param[in] shape forme du tetrino
*\param[in] posx position horizontale d'origine du tetrino
*\param[in] posy position verticale d'origine du tetrino
*\return  retourne un pointeur vers un objet de type tetrino du tertino generer
**/
void  initialiseTab(int* tab);// Initialise un tableau avec de 0
/**\fn void  initialiseTab(int* tab)
*\brief Initialise un tableau à deux dimension de la taille du plateau avec des 0
*\param[in] tab pointeur vers le tableau
**/

int  legalPosition(Game *play, int posx, int posy,int rot); 
/**\fn int  legalPosition(Game *play, int posx, int posy,int rot)
*\brief Verifie qu'une position est legale
*\param[in] play pointeur vers une structure Game du jeu en cours
*\param[in] posx position horizontale desire
*\param[in] posy position verticale desire
*\param[in] rot rotation desire
*\return Retourn 1 si la position est legale 0 sinon
**/

int is_ground(int *play_tab, tetri *tet);// Verifie si il y a contacte
/**\fn int is_ground(int *play_tab, tetri *tet)
*\brief Verifie si il y eu contacte avec le bas du tablea
*\param[in] play_tab pointeur vers le tableau du jeu en cours
*\param[in] tet pointeur vers le tetrino sur lequel effectué le teste
*\return Retourn 1 si il y a contact avec le bas du tableau 0 sinon
**/

void print_tet(tetri *tet, int* tab); 
/**\fn void print_tet(tetri *tet, int* tab)
*\brief Incruste le tetrino dans le plateau de jeu
*\param[in] tab pointeur vers le tableau du jeu en cours
*\param[in] tet pointeur vers le tetrino a incruste
**/

void randomBag(Game* play);
/**\fn void randomBag(Game* play)
*\brief Genere aleatoirement suivant le SRS systeme le sac de piece de jeu
*\param[in] play pointeur vers le jeu en cours
**/

void levelUp(Game *game); 
/**\fn void levelUp(Game *game)
*\brief Effectue les operations lie au changement de niveau 
*\param[in] Game pointeur vers le jeu en cours
**/

void hold(Game *game); 
/**\fn void hold(Game *game)
*\brief Effectue les operations lie au hold d'une piece
*\param[in] Game pointeur vers le  jeu en cours
**/

void nextTetri(Game *game);
/**\fn void nextTetri(Game *game)
*\brief Passe à la piece suivante
*\param[in] Game pointeur vers le jeu en cours
**/

void initialiseGame(Game *current_play); 
/**\fn void initialiseGame(Game *game)
*\brief Initialise le jeu
*\param[in] current_play pointeur vers le tableau du jeu en cours
**/


#endif // GAME_H_INCLUDED
