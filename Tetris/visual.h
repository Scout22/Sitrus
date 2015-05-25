#ifndef VISUAL_H
#define VISUAL_H
#include "def.h"

/**
* \file visual.h
* \brief  Fichier regroupant les fonctions graphiques
*
*   Fichier regroupant les fonctions graphiques
*
*/

void pause(); 
/**\fn void pause(); 
*\brief Met le jeu en pause
**/
void blit_tab(SDL_Surface** tet, SDL_Surface* screen, int * tab); //Prend en entré les differents tetrino, un ecran, le tableau, et affiche le tableau
/**\fn void blit_tab(SDL_Surface** tet, SDL_Surface* screen, int * tab)
*\brief affiche le tableau de jeu
*\param[in] tab Pointeur sur un objet de type tableau d'entier à deux dimension.
*\param[in] tet Pointeur sur tableau de SDL_Surfaces, representant les textures elementaires des tetrino
*\param[in] screen Poiteur sur une SDL_Surface, ecran princial
**/

SDL_Surface* write_text(char * text, int color_R, int color_G, int color_B,int size); 
/**\fn SDL_Surface* write_text(char * text, int color_R, int color_G, int color_B,int size);
*\brief Genere une surface avec contenant un texte
*\param[in] text Pointeur sur string, reprentant la chaine de caractere
*\param[in] color_R valeur de la couleur rouge
*\param[in] color_V valeur de la couleur vert
*\param[in] color_B valeur de la couleur bleu
*\param[in] size taille du texte
*\return  un pointeur vers la surface generer
**/
void blit_tet(tetri* tetr, SDL_Surface** tet, SDL_Surface* screen, int pos_x, int pos_y); //Prend en entré un tetrino, les differents tetrino, un ecran, et affiche le tetrino
/**\fn SDL_Surface* write_text(char * text, int color_R, int color_G, int color_B,int size);
*\brief affiche a l'ecran un tetrino
*\param[in] tet texture des tetrino
*\param[in] ecran Surface de l'ecran
*\param[in] pos_x decalage selon l'axe x
*\param[in] pos_y decalage selon l'axe y
*\param[in] tetr pointeur vers la structure tetri 
**/



#endif // VISUAL_H_INCLUDED
