#ifndef GAME_H
#define GAME_H
#include "def.h"


int is_collison(int *play_tab, tetri* tet); //Retourne 1 si il y a collisison
int reached_top(int*play_tab, tetri* tet);  //Retourne 1 si la piece a depassé l'ecrans
void rotate_tet(tetri* tet); //Rotation d'un tetrino
int is_complete_line(int* play_tab, int *result_tab); /* Fonction permettant de detecter les lignes entiere, prend en entré le plateau de jeu, et un tableau resultat de taille 
													  egale au nombre de lignes du plateau de jeu, et met a un les case correspondate à des ligne plein, retourne le nombre de ligne pleine*/

void clear_line(int *play_tab, int ln_num); // Prend en entrée le plateau de jeu, et un numero de ligne et vide la ligne corrspondante en decalant les cases corrspondante
tetri * make_tet(int shape, int posx, int posy);// Prend en entré une forme (int), posx,posy(int) et retourne un pointeur sur un tetrino
void  initialiseTab(int* tab);// Initialise un tableau avec de 0
int  legalPosition(Game *play, int posx, int posy,int rot); // Verifie qu'une position est legale
int is_ground(int *play_tab, tetri *tet);// Verifie si il y a contacte
void print_tet(tetri *tet, int* tab); //Enregistre le tetrino mouvant dans le tableau
void randomBag(Game* play); // Genere les pieces, bool indique la partie du tableau à generer
void levelUp(Game *game); //Effectue les operations necessaire au LevelUp: Augmentation difficulté et level en plus
void hold(Game *game); // Echange la piece courante avec la piece en reserve
void nextTetri(Game *game); //Appel le tetrino suivant
void initialiseGame(Game *current_play); //Initialise le jeu


#endif // GAME_H_INCLUDED
