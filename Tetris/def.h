#ifndef DEF_H
#define DEF_H
#include <SDL/SDL.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>





#ifdef WIN32
#include <fmod/fmod.h>
#include <SDL_ttf.h>
#elif __unix__
#include <fmod.h>
#include <SDL/SDL_ttf.h>
#endif



#define WINDOW_SIZE_X 600 //Position X des boutons
#define WINDOW_SIZE_Y 600 //Position Y du premier bouton



#define BUTTON_X_ALIGN 100//300 //Position X des boutons
#define BUTTON_Y_ALIGN 30//175 //Position Y du premier bouton
#define BUTTON_Y_TEXT 50 //Position Y du premier bouton
#define BUTTON_X_TEXT 0 //Position X des boutons
#define BUTTON_Y_GAP 150 //Espacement entre deux bouton
#define BUTTON_X_SIZE 450//600 //Taille X du bouton
#define BUTTON_Y_SIZE 100 //Taille Y du bouton

#define COEF_DIFFUCLTY 0.9 //Coefficient gerant la progression de la difficulté, compris entre 0 et 1, 




#define GAME_SIZE_X 10 //Largeur du plateau en case
#define GAME_SIZE_Y 21 //Hauteur du plateau en case
#define TET_SIZE 20 //Taille d'un carré en pixel
#define HIDEN_Y_CASE 2 //Nombre de case caché


#define POS_X_PLA 200//Position de l'origine du plateau en pixel
#define POS_Y_PLA 50//Position de l'origine du plateau en pixel

#define POS_X_SCO 200 //Position de l'origine du score en pixel
#define POS_Y_SCO 50//Position de l'origine du score en pixel

#define POS_X_NEXT 200 //Position de la prochaine piece en pixel
#define POS_Y_NEXT 50//Position de la prochaine piece  en pixel

#define KEY_LAG 100 //Durée en ms avant la repetition d'une touche

//Definition de la structure d'un tetrino
typedef struct tetri {
  int visual[4][4];
  int shape;
  int rotation;
  int x_pos;
  int y_pos;
  int hold_possible;
} tetri;

//Structure associé à une partie en cours
typedef struct Game{
	int tab[GAME_SIZE_X*GAME_SIZE_Y]; //Plateau de jeu
	tetri *current; //Tetrino en mouvement
	tetri *next; //Tetrino suivant
	tetri *hold; //Tetrino retenu
	float game_speed; //Vitesse actuelle du jeu
	float game_speed_base; // Vitesse de base du jeu
	int level; //Niveau
	int lineCleared;//Ligne detruite au niveau en cours
	int bag[14]; //pieces suivant
    int bool;// Partie du sac de pieces suivantes en cours de parcours
    int score;//Score
	int turn; //N° Du tour de jeu
} Game;

//Structure associé au bouton
typedef struct Bouton{
	int brille; //Bonton en surbrillance 
	char text[30]; // Text
	int on_off; // On ou off
}Bouton;


//Structure definissant les paramtres initial du Jeu
typedef struct param{
	float game_speed; //Definis la vitesse de base du jeu
	int hold; //Autorise le hold
	int pause; // Autorise la mise en pause
	int level; // Selection du niveau initial
	int next; //Autorise la previsualisation de la piece suivante
	int music_n;
	int theme;
}param;
#endif
