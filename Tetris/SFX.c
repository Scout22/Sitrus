#include "def.h"

void music(FMOD_SYSTEM **system, FMOD_SOUND **musique,param *settings)
{

#ifdef linux
	FSOUND_SetOutput(FSOUND_OUTPUT_ALSA);
	FSOUND_Init(44100, 32, 0);
#endif

	FMOD_RESULT resultat;
	FMOD_System_Create(system);
	FMOD_System_Init(*system, 1, FMOD_INIT_NORMAL, NULL);
	char file[10];
	sprintf(file, "%d.mp3", settings->music_n);
	/* On ouvre la musique */
	resultat = FMOD_System_CreateSound(*system, file, FMOD_LOOP_NORMAL | FMOD_2D | FMOD_CREATESTREAM, 0, musique);

	/* On vérifie si elle a bien été ouverte (IMPORTANT) */
	if (resultat != FMOD_OK)
	{
		fprintf(stderr, "Impossible de lire le fichier mp3\n");
		exit(EXIT_FAILURE);
	}

	/* On active la répétition de la musique à l'infini */
	FMOD_Sound_SetLoopCount(*musique, -1);

	/* On joue la musique */
	FMOD_System_PlaySound(*system, *musique, 0, 0, NULL);


}

void stop_music(FMOD_SYSTEM *system, FMOD_SOUND *musique)
{
	FMOD_Sound_Release(musique);
	FMOD_System_Close(system);
	FMOD_System_Release(system);


}