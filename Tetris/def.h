#ifndef DEF_H
#define DEF_H
#include <SDL/SDL.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
/**
* \file def.h
* \brief Fichier effectuants les differentes definitions
*
*  Fichier effectuants les differentes definitions
*
*/



//Definition pour le preprocesseur pour compilation crossplatforme
#ifdef WIN32
#include <fmod/fmod.h>
#include <SDL_ttf.h>
#elif __unix__
#include <fmod.h>
#include <SDL/SDL_ttf.h>
#endif



#define WINDOW_SIZE_X 600
/**
* \def WINDOW_SIZE_X
*Position X des boutons
*/
#define WINDOW_SIZE_Y 600 //!Position Y du premier bouton
/**
* \def WINDOW_SIZE_Y
*Position Y des boutons
*/


#define BUTTON_X_ALIGN 100//!Position X des boutons
#define BUTTON_Y_ALIGN 30//!Position Y du premier bouton
#define BUTTON_Y_TEXT 50 //!Position Y du premier bouton
#define BUTTON_X_TEXT 0 //!Position X des boutons
#define BUTTON_Y_GAP 150 //!Espacement entre deux bouton
#define BUTTON_X_SIZE 450//!Taille X du bouton
#define BUTTON_Y_SIZE 100 //!Taille Y du bouton

#define COEF_DIFFUCLTY 0.9 //!Coefficient gerant la progression de la difficulté, compris entre 0 et 1, 




#define GAME_SIZE_X 10 //!Largeur du plateau en case
#define GAME_SIZE_Y 21 //!Hauteur du plateau en case
#define TET_SIZE 20 //!Taille d'un carré en pixel
#define HIDEN_Y_CASE 2 //!Nombre de case caché


#define POS_X_PLA 200//!Position de l'origine du plateau en pixel
#define POS_Y_PLA 50//!Position de l'origine du plateau en pixel

#define POS_X_SCO 200 //!Position de l'origine du score en pixel
#define POS_Y_SCO 50//!Position de l'origine du score en pixel

#define POS_X_NEXT 200 //!Position de la prochaine piece en pixel
#define POS_Y_NEXT 50//!Position de la prochaine piece  en pixel

#define KEY_LAG 100 //!Durée en ms avant la repetition d'une touche

//Definition de la structure d'un tetrino

/**
*\struct tetri
*\brief Structure stockant un tetrino

*/
typedef struct tetri {
	//! Tableau d'entien stokant le visuel du tetrino
  int visual[4][4];
  //! entier stockant l'identifiant du tetrino
  int shape;
  //! entier stockant l'angle de rotation du tetrino
  int rotation;
  //! entier stickant la postition en x du tetrino
  int x_pos;
  //! entier stickant la postition en y du tetrino
  int y_pos;
  //!boolean indiquant la possibilite ou non de hold la piece
  int hold_possible; 
} tetri;

/**
*\struct Game
*\brief Structure associé à une partie en cours
*/
typedef struct Game{
	//!Plateau de jeu
	int tab[GAME_SIZE_X*GAME_SIZE_Y]; 
	//!Tetrino en mouvement
	tetri *current; 
	//!Tetrino suivant
	tetri *next; 
	//!Tetrino retenu
	tetri *hold;
	//!Vitesse actuelle du jeu
	float game_speed; 
	//! Vitesse de base du jeu
	float game_speed_base;
	//!Niveau
	int level; 
	//!Ligne detruite au niveau en cours
	int lineCleared;
	//!pieces suivant
	int bag[14]; 
	//! Partie du sac de pieces suivantes en cours de parcours
    int bool;
	//!Score
    int score;
	//!N° Du tour de jeu
	int turn;
} Game;


/**
*\struct Bouton
*\brief Structure associé au bouton
*/
typedef struct Bouton{
	//!Boolean indiquant si le bonton en surbrillance 
	int brille; 
	//! Texte
	char text[30]; 
	//! On ou off
	int on_off;
}Bouton;


/**
*\struct param
*\brief Structure definissant les paramtres l du Jeu
*/
typedef struct param{
	//!Definis la vitesse de base du jeu
	float game_speed;
	//!Autorise le hold
	int hold; 
	//! Autorise la mise en pause
	int pause;
	//! Selection du niveau initial
	int level;
	//!Autorise la previsualisation de la piece suivante
	int next; 
	//!Fond sonor
	int music_n;
	//!Fond ecran
	int theme;
}param;
#endif
