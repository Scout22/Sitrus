#ifndef SFX_H
#define SFX_H
#include "def.h"
void music(FMOD_SYSTEM **system, FMOD_SOUND **musique,param *settings); // Lance la musique
void stop_music(FMOD_SYSTEM *system, FMOD_SOUND *musique); //Arrete la musique en cours
#endif