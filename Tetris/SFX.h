#ifndef SFX_H
#define SFX_H
#include "def.h"
/**
* \file SFX.h
* \brief Fichier regroupant les fonctions de lecture audio.
*
*  Fichier regroupant les fonctions de lecture audio.
*
*/

void music(FMOD_SYSTEM **system, FMOD_SOUND **musique,param *settings); 
/**\fn music(FMOD_SYSTEM **system, FMOD_SOUND **musique,param *settings)
*\brief Lance la musique indiquer dans la structure settings
*\param[in] settings pointeur vers une structure param, stock entre autre le morceau a jouer
*\param[in] systeme pointeur vers pointeur de FMOD_SYSTEM
*\param[in] musique pointeur vers pointeur de SOUND
**/

void stop_music(FMOD_SYSTEM *system, FMOD_SOUND *musique); 
/**\fn music(FMOD_SYSTEM **system, FMOD_SOUND **musique,param *settings)
*\brief Arrete la musique 
*\param[in] systeme pointeur vers pointeur de FMOD_SYSTEM
*\param[in] musique pointeur vers pointeur de SOUND
**/
#endif