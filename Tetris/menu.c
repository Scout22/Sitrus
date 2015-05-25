#include "game.h"
#include "SFX.h"
#include "menu.h"
#include "visual.h"
/**
* \file menu.c
* \brief  Fichier regroupant les differents menu
*
*  Fichier regroupant les differents menu
*
*/


void option_menu_general(SDL_Surface *ecran,  param* settings){
	
	Bouton content[5];
	content[0].brille = 0;
	
	if (settings->next){
		strcpy(content[0].text, "Display next on \0");
	}
	else{
		strcpy(content[0].text, "Display next off\0");
	}
	content[1].brille = 0;
	sprintf(content[1].text,"Start level  %d",settings->level);
	content[2].brille = 0;
	if (settings->hold){
		strcpy(content[2].text, "Allow hold   on \0");
	}
	else{
		strcpy(content[2].text, "Allow hold   off\0");
	}
	content[3].brille = 0;
	if (settings->pause){
		strcpy(content[3].text, "Allow pause  on \0");
	}
	else{
		strcpy(content[3].text, "Allow pause  off\0");
	}
	
	content[4].brille = 0;

	strcpy(content[4].text, "Save settings   \0");


	//La police d'ecriture qu'on va utiliser
	

	SDL_Event event;


	int quiBrille = -1;

	SDL_Surface *message = NULL;
	SDL_Surface *carre = NULL;
	int op;
	SDL_Rect position;
	SDL_Rect position2;
	int  stop = 0;
	carre = SDL_CreateRGBSurface(SDL_HWSURFACE, BUTTON_X_SIZE,(int) (BUTTON_Y_SIZE/1.4), 32, 0, 0, 0, 0);
	
	while (!stop){


		//fonction d'affichage des boutons
		SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
		for (op = 0; op<5; op++){

			position.x = BUTTON_X_ALIGN;
			position.y = BUTTON_Y_ALIGN + op * (int) (BUTTON_Y_GAP/1.4);

			position2.x = BUTTON_X_ALIGN + BUTTON_X_TEXT;
			position2.y = BUTTON_Y_ALIGN + BUTTON_Y_TEXT + op * (int)(BUTTON_Y_GAP/1.4)-40;

			if (op == quiBrille){
				//surbrillance
				SDL_FillRect(carre, NULL, SDL_MapRGB(ecran->format, 255, 0, 0));
				SDL_BlitSurface(carre, NULL, ecran, &position);
			}
			else{
				SDL_FillRect(carre, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
				SDL_BlitSurface(carre, NULL, ecran, &position);
			}
			message = write_text(content[op].text, 0, 0, 0, 40); 
			SDL_BlitSurface(message, NULL, ecran, &position2);
		}

		SDL_Flip(ecran);

		if (SDL_PollEvent(&event)){
			if (event.type == SDL_QUIT){
				if (carre != NULL){
					stop = 1;
					break;
				}
			}
			if (event.type == SDL_KEYDOWN){
				switch (event.key.keysym.sym){
				case SDLK_UP:{
					quiBrille = (quiBrille - 1) % 5;
					if (quiBrille < 0)
						quiBrille = 4;
					content[quiBrille].brille = 1;
					break;
				}
				case SDLK_DOWN:{
					quiBrille++;
					quiBrille = quiBrille % 5;
					content[quiBrille].brille = 1;
					break;
				}
				case SDLK_RETURN:{
					switch (quiBrille){
					case 0:{
						if (settings->next){
							content[0].text[13] = 'o';
							content[0].text[14] = 'f';
							content[0].text[15] = 'f';
							settings->next = 0;
						}
						else{
							content[0].text[13] = 'o';
							content[0].text[14] = 'n';
							content[0].text[15] = ' ';
							settings->next = 1;
						}
						break;
					}
					case 1:{
						settings->level++;
						sprintf(content[1].text, "Start level %d", settings->level);
						break;

					}
					case 2:{
						if (settings->hold){
							content[2].text[13] = 'o';
							content[2].text[14] = 'f';
							content[2].text[15] = 'f';
							settings->hold = 0;
						}
						else{
							content[2].text[13] = 'o';
							content[2].text[14] = 'n';
							content[2].text[15] = ' ';
							settings->hold = 1;
						}
						break;
					}
					case 3:{
						if (settings->pause){
							content[3].text[13] = 'o';
							content[3].text[14] = 'f';
							content[3].text[15] = 'f';
							settings->pause = 0;
						}
						else{
							content[3].text[13] = 'o';
							content[3].text[14] = 'n';
							content[3].text[15] = ' ';
							settings->pause = 1;
						}
						break;

					}


					case 4:{

						stop = 1;
						break;
					}
					}
					break;
				}

				case SDLK_RIGHT:{
					switch (quiBrille){
					case 0:{
						if (settings->next){
							content[0].text[13] = 'o';
							content[0].text[14] = 'f';
							content[0].text[15] = 'f';
							settings->next = 0;
						}
						else{
							content[0].text[13] = 'o';
							content[0].text[14] = 'n';
							content[0].text[15] = ' ';
							settings->next = 1;
						}
						break;
					}
					case 1:{
						settings->level++;
						sprintf(content[1].text, "Start level %d", settings->level);
						break;

					}
					case 2:{
						if (settings->hold){
							content[2].text[13] = 'o';
							content[2].text[14] = 'f';
							content[2].text[15] = 'f';
							settings->hold = 0;
						}
						else{
							content[2].text[13] = 'o';
							content[2].text[14] = 'n';
							content[2].text[15] = ' ';
							settings->hold = 1;
						}
						break;
					}
					case 3:{
						if (settings->pause){
							content[3].text[13] = 'o';
							content[3].text[14] = 'f';
							content[3].text[15] = 'f';
							settings->pause = 0;
						}
						else{
							content[3].text[13] = 'o';
							content[3].text[14] = 'n';
							content[3].text[15] = ' ';
							settings->pause = 1;
						}
						break;

					}


					}
					break;
				}

				case SDLK_LEFT:{
					switch (quiBrille){
					case 0:{
						if (settings->next){
							content[0].text[13] = 'o';
							content[0].text[14] = 'f';
							content[0].text[15] = 'f';
							settings->next = 0;
						}
						else{
							content[0].text[13] = 'o';
							content[0].text[14] = 'n';
							content[0].text[15] = ' ';
							settings->next = 1;
						}
						break;
					}
					case 1:{
						settings->level--;
						if (settings->level < 1)
							settings->level = 1;
						sprintf(content[1].text, "Start level %d", settings->level);
						break;

					}
					case 2:{
						if (settings->hold){
							content[2].text[13] = 'o';
							content[2].text[14] = 'f';
							content[2].text[15] = 'f';
							settings->hold = 0;
						}
						else{
							content[2].text[13] = 'o';
							content[2].text[14] = 'n';
							content[2].text[15] = ' ';
							settings->hold = 1;
						}
						break;
					}
					case 3:{
						if (settings->pause){
							content[3].text[13] = 'o';
							content[3].text[14] = 'f';
							content[3].text[15] = 'f';
							settings->pause = 0;
						}
						else{
							content[3].text[13] = 'o';
							content[3].text[14] = 'n';
							content[3].text[15] = ' ';
							settings->pause = 1;
						}
						break;
					}
					}

				}
					break;

				default:
					break;
				
				}
				

			}
	
		}

		SDL_Delay(50);

	}
	SDL_FreeSurface(carre);
	SDL_FreeSurface(message);
	
	settings->game_speed =(float)( 100 * pow((COEF_DIFFUCLTY),settings->level-1));

}

void option_menu_vfx_sfx(SDL_Surface *ecran, param* settings){
	Bouton content[3];
	FMOD_SYSTEM *system = NULL;
	FMOD_SOUND *musique = NULL;
	content[0].brille = 0;
	content[0].brille = 1;
	content[2].brille = 0;
	sprintf(content[0].text, "Audio theme  %d", settings->music_n);
	sprintf(content[1].text, "Background theme: %d", settings->theme);
	sprintf(content[2].text, "Save settings");
	


	//La police d'ecriture qu'on va utiliser


	SDL_Event event;


	int quiBrille = -1;

	SDL_Surface *message = NULL;
	SDL_Surface *carre = NULL;
	SDL_Surface *Background=NULL;
	int op;
	SDL_Rect position;
	SDL_Rect position2;
	int  stop = 0;
	char file[10];
	carre = SDL_CreateRGBSurface(SDL_HWSURFACE, BUTTON_X_SIZE, (int) (BUTTON_Y_SIZE / 1.4), 32, 0, 0, 0, 0);
	music(&system, &musique, settings);
	

	while (!stop){


		//fonction d'affichage des boutons
		//SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
		sprintf(file, "%d.bmp", settings->theme);
		Background = SDL_LoadBMP(file);
		position.x = 0;
		position.y = 0;
		SDL_BlitSurface(Background, NULL, ecran, &position);
		for (op = 0; op<3; op++){

			position.x = BUTTON_X_ALIGN;
			position.y = BUTTON_Y_ALIGN + op * (int) (BUTTON_Y_GAP / 1.4);

			position2.x = BUTTON_X_ALIGN + BUTTON_X_TEXT;
			position2.y = BUTTON_Y_ALIGN + BUTTON_Y_TEXT + op * (int) (BUTTON_Y_GAP / 1.4) - 40;

			if (op == quiBrille){
				//surbrillance
				message = write_text(content[op].text, 0, 120, 0, 40);
			}
			else{
				message = write_text(content[op].text, 0, 120, 100, 40);
			}
			
			SDL_BlitSurface(message, NULL, ecran, &position2);
		}

		SDL_Flip(ecran);
		SDL_FreeSurface(Background);
		if (SDL_PollEvent(&event)){
			if (event.type == SDL_QUIT){
				if (carre != NULL){
					stop = 1;
					break;
				}
			}
			if (event.type == SDL_KEYDOWN){
				switch (event.key.keysym.sym){
				case SDLK_UP:{
					quiBrille = (quiBrille - 1) % 3;
					if (quiBrille < 0)
						quiBrille = 2;
					content[quiBrille].brille = 1;
					break;
				}
				case SDLK_DOWN:{
					quiBrille++;
					quiBrille = quiBrille % 3;
					content[quiBrille].brille = 1;
					break;
				}
				case SDLK_RIGHT:
				case SDLK_RETURN:{
					switch (quiBrille){
					case 0:{
						settings->music_n = (settings->music_n +1) % 5;
						sprintf(content[0].text, "Audio theme  %d", settings->music_n);
						stop_music(system, musique);
						music(&system, &musique, settings);
						break;
					}
					case 1:{
						settings->theme = (settings->theme + 1) % 5;
						sprintf(content[1].text, "Background theme: %d", settings->theme);
						break;

					}
					case 2:{

						stop = 1;
						break;
					}
					}
					break;
				}


				case SDLK_LEFT:{
					switch (quiBrille){
					case 0:{
						settings->music_n--;
						if (settings->music_n < 0){
							settings->music_n = 0;
						}
						sprintf(content[0].text, "Audio theme  %d", settings->music_n);
						stop_music(system, musique);
						music(&system, &musique, settings);
						break;
					}
					case 1:{
						settings->theme--;
						if (settings->theme < 0){
							settings->theme = 0;
						}
						sprintf(content[1].text, "Background theme: %d", settings->theme);
						break;

					}
					case 2:{

						stop = 1;
						break;
					}
					}
					break; }

				default:
					break;

				}


			}

		}

		SDL_Delay(50);

	}
	SDL_FreeSurface(carre);
	SDL_FreeSurface(message); 
	stop_music(system, musique);
	




}

void option_menu(SDL_Surface *ecran, param* settings){
	Bouton content[3];
	content[0].brille = 0;

	strcpy(content[0].text, "General \0");
	strcpy(content[1].text, "VFX/SFX \0");
	content[1].brille = 0;
	content[2].brille = 0;
	strcpy(content[2].text, "Return   \0");


	SDL_Event event;
	int quiBrille = -1;

	SDL_Surface *message = NULL;
	SDL_Surface *carre = NULL;
	int op;
	SDL_Rect position;
	SDL_Rect position2;
	int  stop = 0;
	carre = SDL_CreateRGBSurface(SDL_HWSURFACE, BUTTON_X_SIZE, (int) (BUTTON_Y_SIZE / 1.4), 32, 0, 0, 0, 0);

	while (!stop){


		//fonction d'affichage des boutons
		SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
		for (op = 0; op < 3; op++){

			position.x = BUTTON_X_ALIGN;
			position.y = BUTTON_Y_ALIGN + op * (int) (BUTTON_Y_GAP / 1.4);

			position2.x = BUTTON_X_ALIGN + BUTTON_X_TEXT;
			position2.y = BUTTON_Y_ALIGN + BUTTON_Y_TEXT + op * (int) (BUTTON_Y_GAP / 1.4) - 40;

			if (op == quiBrille){
				//surbrillance
				SDL_FillRect(carre, NULL, SDL_MapRGB(ecran->format, 255, 0, 0));
				SDL_BlitSurface(carre, NULL, ecran, &position);
			}
			else{
				SDL_FillRect(carre, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
				SDL_BlitSurface(carre, NULL, ecran, &position);
			}
			message = write_text(content[op].text, 0, 0, 0, 40);
			SDL_BlitSurface(message, NULL, ecran, &position2);
		}

		SDL_Flip(ecran);

		if (SDL_PollEvent(&event)){
			if (event.type == SDL_QUIT){
				if (carre != NULL){
					stop = 1;
					break;
				}
			}
			if (event.type == SDL_KEYDOWN){
				switch (event.key.keysym.sym){
				case SDLK_UP:{
					quiBrille = (quiBrille - 1) % 3;
					if (quiBrille < 0)
						quiBrille = 2;
					content[quiBrille].brille = 1;
					break;
				}
				case SDLK_DOWN:{
					quiBrille++;
					quiBrille = quiBrille % 3;
					content[quiBrille].brille = 1;
					break;
				}
				case SDLK_RETURN:{
					switch (quiBrille){
					case 0:{
						option_menu_general(ecran, settings);

						break;
					}
					case 1:{
						option_menu_vfx_sfx(ecran, settings);

					}

					case 2:{

						stop = 1;
						break;
					}
					}
					break;

				default:
					break;


				}

				}
			}
		}

				SDL_Delay(50);

			}
			SDL_FreeSurface(carre);
			SDL_FreeSurface(message);

}
	


int validate_highscore(char * name, int score){
	if (name == NULL){
		return -1;
	}
	return ((name[1] * score) % 256);
}
	
int reset_highscore(){
	FILE* fichier = fopen("score.txt", "w");
	if (fichier == NULL)
		return 1;
	int i;
	for (i = 0; i < 5; i++){
		fprintf(fichier, "YYY 0 0");
	}
	fclose(fichier);
	return 0;
}

int read_highscore(char *text, int * score){
	FILE* fichier = fopen("score.txt", "r");
	if (fichier == NULL){
		fprintf(stderr, "Erreur lors de la lecture du fichier de highscore");
		
		return 2;
	}
	int validate[5];
	int invalid = 0;
	int i;
	for (i = 0; i < 5; i++){
		if (fscanf(fichier, "%s %d %d", &text[i * 10], &score[i], &validate[i]) != 3){
			invalid = 1;
			break;
		}
		
		if (validate_highscore(&text[i*10], score[i]) != validate[i]){
			invalid = 1;
			break;
		}
	}
	fclose(fichier);
	if (invalid){

		if (reset_highscore() == 0){
			read_highscore(text, score);
			return 1;
		}
		else{

			sprintf(&text[0], "Erreur");
			sprintf(&text[10], "de");
			sprintf(&text[20], "lecture");
			sprintf(&text[30], "des");
			sprintf(&text[40], "Highscore");

			for (i = 0; i < 5; i++){
				score[i] = -1;
				
			}
			return 2;
		}
	}
	return 0;
}

void print_highscore(char *name, int score){
	FILE *fichier;
	char name_file[5][10];
	int score_file[5];
	int max=5;
	if (read_highscore((char *)name_file, score_file) == 2)
		return;
	for (int i = 4; i >= 0; i--){
		if (score > score_file[i]){
			max = i;
		}
		else{
			break;
		}
	}
	if (max == 5){
		return;
	}

	for (int i = 4; i > max; i--){
		score_file[i] = score_file[i - 1];
		sprintf(name_file[i], "%s", name_file[i-1]);
	}
	score_file[max] = score;
	sprintf(name_file[max], "%s", name);
	
	fichier=fopen("score.txt", "w");
	if (fichier==NULL){
		return;
	}
	for (int i = 0; i < 5; i++){
		fprintf(fichier, "%s %d %d\n", name_file[i], score_file[i], validate_highscore(name_file[i], score_file[i]));
	}
	fclose(fichier);
}

void highscore_menu(SDL_Surface *ecran){

	//La police d'ecriture qu'on va utiliser
	TTF_Font *font;
	font = TTF_OpenFont("arial.ttf", 40);

	if (font == NULL){
		fprintf(stderr, "Erreur lors de la lecture du fichier de police");
		return;
	}

	SDL_Event event;
	//La couleur de la police
	SDL_Color textColor = { 0, 0, 0 };
	//Titre de la fenertre


	SDL_Surface *message = NULL;
	SDL_Surface *carre = NULL;
	int op;
	SDL_Rect position;
	SDL_Rect position2;
	int  stop = 0;
	carre = SDL_CreateRGBSurface(SDL_HWSURFACE, BUTTON_X_SIZE,(int)( BUTTON_Y_SIZE / 1.4), 32, 0, 0, 0, 0);
	char text[20];
	char name[5][10];
	int highscore[5];
	read_highscore((char*)name, highscore);


	//fonction d'affichage des boutons
	SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
	for (op = 0; op < 5; op++){
		sprintf(text, "%s   %d", name[op], highscore[op]);
		position.x = BUTTON_X_ALIGN;
		position.y = BUTTON_Y_ALIGN + op * (int)(BUTTON_Y_GAP / 1.4);

		position2.x = BUTTON_X_ALIGN + BUTTON_X_TEXT;
		position2.y = BUTTON_Y_ALIGN + BUTTON_Y_TEXT + (int)(op * BUTTON_Y_GAP / 1.4) - 40;



		SDL_FillRect(carre, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
		SDL_BlitSurface(carre, NULL, ecran, &position);

		message = TTF_RenderText_Solid(font, text, textColor);
		SDL_BlitSurface(message, NULL, ecran, &position2);
	}

	SDL_Flip(ecran);
	while (stop == 0){
		if (SDL_PollEvent(&event)){
			if (event.type == SDL_QUIT){
				stop = 1;
				break;
			}
			if (event.type == SDL_KEYUP){
				switch (event.key.keysym.sym){
				case SDLK_ESCAPE:
					stop = 1;
					break;
				default:
					break;
				}


			}
		}
	}
	SDL_FreeSurface(carre);
	SDL_FreeSurface(message);
	TTF_CloseFont(font);

}

void nameinput_menu(SDL_Surface * ecran, char *name){
	int cursor_pos = 0;
	int is_complete = 0;
	SDL_Surface* imageDeFond = NULL;
	SDL_Event event;
	SDL_Surface *text = NULL;
	SDL_Rect position;
	imageDeFond=SDL_LoadBMP("highscore.bmp");
	if (imageDeFond == NULL){
		fprintf(stderr, "Erreur lors de la lecture du fichier de l'image de fond");
		return;
	}
	
	name[0] = '\0';
	name[1] = ' ';
	SDL_EnableUNICODE(1);

	while (!is_complete){
		position.x = 0;
		position.y = 0;
		SDL_BlitSurface(imageDeFond, NULL, ecran, &position);
		
		if (SDL_PollEvent(&event)){
			if (event.type == SDL_QUIT){
				
					is_complete = 1;
					break;
				
			}
			if (event.type == SDL_KEYDOWN){
				switch (event.key.keysym.sym){
				case SDLK_RETURN:
				case SDLK_ESCAPE:{
					is_complete = 1;
					break; }
				case SDLK_BACKSPACE:{
					cursor_pos--;
					if (cursor_pos < 0){
						cursor_pos = 0;
					}
					name[cursor_pos] = '\0';
					
					break;
				}
				default:{
					if (event.key.keysym.unicode < 0x80 && event.key.keysym.unicode > 0){
						name[cursor_pos] = (char) event.key.keysym.unicode;
						name[cursor_pos + 1] = '\0';
						cursor_pos++;
						if (cursor_pos > 4){
							cursor_pos = 4;
						}
					}
					break;
				}
				}
			}
		}

		text = write_text(name,52,177,216,80);
		position.x = 200;
		position.y = 435;
		SDL_BlitSurface(text, NULL, ecran, &position);
		
		SDL_Flip(ecran);
		SDL_Delay(50);
	}
	SDL_FreeSurface(text);
	SDL_FreeSurface(imageDeFond);
	
}

int game(param *settings, SDL_Surface *ecran)
{
	SDL_Surface* imageDeFond = NULL, *text = NULL;
	SDL_Surface* tetra_col[7];
	SDL_Rect positionFond;
	SDL_Event event;
	FMOD_SYSTEM *system = NULL;
	FMOD_SOUND *musique = NULL;
	srand((int) time(NULL));

	int xvel = 0;
	int pause_game = 0;
	int i;
	int f_line[GAME_SIZE_Y]; //Varible stockant la liste des lignes completes

	char player_name[10];
	char texto[15];

	positionFond.x = 0;
	positionFond.y = 0;
	int stop = 0;

	

	//Charge les elements de texture
	sprintf(texto, "%d.bmp", settings->theme);

	imageDeFond = SDL_LoadBMP(texto);
	if (imageDeFond == NULL){
		fprintf(stderr, "Erreur lors de la lecture du fichier de l'image de fond");
		return 0;
	}
	tetra_col[0] = SDL_LoadBMP("tetra_c.bmp");
	tetra_col[1] = SDL_LoadBMP("tetra_vi.bmp");
	tetra_col[2] = SDL_LoadBMP("tetra_o.bmp");
	tetra_col[3] = SDL_LoadBMP("tetra_b.bmp");
	tetra_col[4] = SDL_LoadBMP("tetra_v.bmp");
	tetra_col[5] = SDL_LoadBMP("tetra_r.bmp");
	tetra_col[6] = SDL_LoadBMP("tetra_j.bmp");

	music(&system, &musique, settings);

	for (i = 0; i < 7; i++){
		if (tetra_col[i] == NULL){
			fprintf(stderr, "Erreur lors de la lecture du fichier des tetrinos");
			return 0;
		}
	}

	//Application de la transparence
	Uint32          colorkey;
	for (i = 0; i < 7; i++){
		colorkey = SDL_MapRGB(tetra_col[i]->format, 0, 0, 0);
		SDL_SetColorKey(tetra_col[i], SDL_SRCCOLORKEY, colorkey);
	}




	Uint32 current_time;
	Uint32 old_time = SDL_GetTicks();

	Uint32 current_time2;
	Uint32 old_time2 = SDL_GetTicks();

	float ftime;
	float ftime2;


	//Cree & initalise la variable de jeu
	Game current_play;
	initialiseGame(&current_play);
	current_play.game_speed = settings->game_speed;
	current_play.game_speed_base = settings->game_speed;
	current_play.level = settings->level;


	while (stop == 0){
		//Affiche le fond d'ecran
		positionFond.x = 0;
		positionFond.y = 0;
		SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);

		current_time = SDL_GetTicks();
		current_time2 = SDL_GetTicks();
		ftime = (current_time - old_time) / current_play.game_speed;
		ftime2 = (float) (current_time2 - old_time2);


		//Affiche le score
		positionFond.y = 20 * 25;
		positionFond.x = 200;
		SDL_BlitSurface(text, NULL, ecran, &positionFond);

		//Affiche le tetrino en mouvement
		blit_tet(current_play.current, tetra_col, ecran, 200, 30);

		//Affiche le tetrino suivant
		if (settings->next){
			blit_tet(current_play.next, tetra_col, ecran, 480, 100);
		}

		//Affiche le tetrino en retenu
		if (current_play.hold != NULL){
			blit_tet(current_play.hold, tetra_col, ecran, 40, 100);
		}

		//Affiche le tableau de jeu
		blit_tab(tetra_col, ecran, current_play.tab);

		//Bloque l'execution du jeu si l'on se met en pause
		while (pause_game){
			SDL_WaitEvent(&event);
			if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_p)
				pause_game = 0;
			if (event.type == SDL_QUIT){
				stop = 1;
				break;
			}
		}


		//Boucle lente 1FPS
		if (ftime > (current_play.game_speed / 10.0)){
			old_time = current_time;

			//Genere la texture lié au score
			sprintf(texto, "%d", current_play.score);
			if (settings->theme > 0){
				text = write_text(texto, 0, 255, 255, 65);
			}
			else
			{
				text = write_text(texto, 0, 255, 0, 65);
			}
			//Applique la gravité au tetrino 
			switch (legalPosition(&current_play, current_play.current->x_pos, current_play.current->y_pos + 1, 0)){
			case 1: //Pas de contact poursuit la chute
				current_play.current->y_pos += 1;
				break;
			case 0:
				break;
			case 2: // En cas de contact
				print_tet(current_play.current, current_play.tab); //Incruste le tetrino dans le tableau de jeu
				nextTetri(&current_play); //Passe au tetrino suivant
				break;
			case 3: //Defaite
				text = write_text("GAME OVER", 230, 100, 0, 80); //Message defaite
				positionFond.x = 100;
				positionFond.y = 200;
				SDL_BlitSurface(text, NULL, ecran, &positionFond);
				SDL_Flip(ecran);
				SDL_Delay(3000); //Met en pause le programme pendant 2s et quitte la boucle de jeu
				stop = 2;
				break;

			}
			current_play.lineCleared += is_complete_line(current_play.tab, f_line); //Incremente le nombre de ligne detruite

			//Calcul du score 
			switch (is_complete_line(current_play.tab, f_line))
			{
			case 0:
				break;
			case 1:
				current_play.score += 40 * current_play.level;
				levelUp(&current_play);
				break;
			case 2:
				current_play.score += 100 * current_play.level;
				levelUp(&current_play);
				break;
			case 3:
				current_play.score += 300 * current_play.level;
				levelUp(&current_play);
				break;
			case 4:
				current_play.score += 1200 * current_play.level;
				levelUp(&current_play);
				break;
			}

			//Detruit les lignes pleine
			for (int i = 0; i < GAME_SIZE_Y; i++){
				if (f_line[i]){
					clear_line(current_play.tab, i);
				}
			}


		}

		//Boucle rapide 10FPS
		if (ftime2 > KEY_LAG){
			old_time2 = current_time2;
			//Test si le tetrino peut poursuivre son deplacement
			if (legalPosition(&current_play, current_play.current->x_pos + xvel, current_play.current->y_pos, 0) == 1)
				current_play.current->x_pos += xvel;



		}

		//Affiche la composition visuel
		SDL_Flip(ecran);



		//Gestion des evenements
		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT) /* On teste le type d'événement */
			{
				/* Si c'est un événement QUITTER */
				stop = 1;
			}

			//Gestion des touches
			else if (event.type == SDL_KEYUP){

				switch (event.key.keysym.sym){
				case SDLK_LEFT:

					if (xvel < 0){
						xvel = 0;
					}
					break;

				case SDLK_RIGHT:
					if (xvel > 0){
						xvel = 0;
					}
					break;

				case SDLK_DOWN:
					current_play.game_speed = current_play.game_speed_base;
					break;

				case SDLK_ESCAPE:
					stop = 3;
					break;
				default:
					break;
				}
			}
			else if (event.type == SDL_KEYDOWN){

				switch (event.key.keysym.sym){
				case SDLK_UP:
					if (legalPosition(&current_play, current_play.current->x_pos + xvel, current_play.current->y_pos, 1) == 1){
						rotate_tet(current_play.current);
					}
					break;

				case SDLK_RIGHT:
					xvel = 1;
					break;

				case SDLK_LEFT:
					xvel = -1;
					break;

				case SDLK_DOWN:
					current_play.game_speed = current_play.game_speed_base / 5;
					break;

				case SDLK_p:
					if (settings->pause){
						pause_game = 1;
					}
					break;

				case SDLK_h:
					if (settings->hold){
						hold(&current_play);
					}
					break;
				default:
					break;
				}
			}

		}


		SDL_Delay(25);
	}

	//Si la boucle est quitté suite a un GameOver saisir nom joueur
	if (stop == 2){
		nameinput_menu(ecran, player_name);
		print_highscore(player_name, current_play.score);
	}

	//Libere les differents elements
	free(current_play.current);
	free(current_play.next);
	if (current_play.hold)
		free(current_play.hold);
	stop_music(system, musique);
	for (int i = 0; i < 7; i++){
		SDL_FreeSurface(tetra_col[i]);
	}
	SDL_FreeSurface(text);
	SDL_FreeSurface(imageDeFond);


	return stop;
}

int main_menu(){
	SDL_Surface *ecran = NULL;
	SDL_Event event;

	SDL_Init(SDL_INIT_VIDEO);
	ecran = SDL_SetVideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y, 32, SDL_HWSURFACE);


	int quiBrille = -1;
	Bouton content[4];
	content[0].brille = 0;
	strcpy(content[0].text, "Play\0");
	content[1].brille = 0;
	strcpy(content[1].text, "HighScore\0");
	content[2].brille = 0;
	strcpy(content[2].text, "Option\0");
	content[3].brille = 0;
	strcpy(content[3].text, "Exit\0");
	
	TTF_Init();
	//La police d'ecriture qu'on va utiliser
	TTF_Font *font;
	font = TTF_OpenFont("arial.ttf", 40);

	if (font == NULL){
		fprintf(stderr, "Erreur lors de la lecture du fichier de police");
		return 0;
	}

	//La couleur de la police
	SDL_Color textColor = { 0, 0, 0 };
	//Titre de la fenertre
	SDL_WM_SetCaption("Tetris", NULL);


	
	SDL_Surface     *image;
	image = SDL_LoadBMP("icon2.bmp");

	if (image == NULL){
		fprintf(stderr, "Erreur lors de la lecture du fichier de l'icon");
		return 0;
	}
	Uint32          colorkey;
	colorkey = SDL_MapRGB(image->format, 0, 255, 0);
	SDL_SetColorKey(image, SDL_SRCCOLORKEY, colorkey);
	SDL_WM_SetIcon(image, NULL);


	param settings = { 100, 1, 1, 1, 1,2,2 };

	SDL_Surface *message = NULL;
	SDL_Surface *carre = NULL;
	int op;
	SDL_Rect position;
	SDL_Rect position2;
	int  stop = 0;
	carre = SDL_CreateRGBSurface(SDL_HWSURFACE, BUTTON_X_SIZE, BUTTON_Y_SIZE, 32, 0, 0, 0, 0);


	while (!stop){


		//fonction d'affichage des boutons
		SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
		for (op = 0; op<4; op++){

			position.x = BUTTON_X_ALIGN;
			position.y = BUTTON_Y_ALIGN + op * BUTTON_Y_GAP;

			position2.x = BUTTON_X_ALIGN + BUTTON_X_TEXT;
			position2.y = BUTTON_Y_ALIGN + BUTTON_Y_TEXT + op * BUTTON_Y_GAP;

			if (op == quiBrille){
				//surbrillance
				SDL_FillRect(carre, NULL, SDL_MapRGB(ecran->format, 255, 0, 0));
				SDL_BlitSurface(carre, NULL, ecran, &position);
			}
			else{
				SDL_FillRect(carre, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
				SDL_BlitSurface(carre, NULL, ecran, &position);
			}
			message = TTF_RenderText_Solid(font, content[op].text, textColor);
			SDL_BlitSurface(message, NULL, ecran, &position2);
		}

		SDL_Flip(ecran);

		if (SDL_PollEvent(&event)){
			if (event.type == SDL_QUIT){
				stop = 1;
			}
			if (event.type == SDL_KEYDOWN){
				switch (event.key.keysym.sym){
				case SDLK_UP:{
					quiBrille = (quiBrille - 1) % 4;
					if (quiBrille < 0)
						quiBrille = 3;
					content[quiBrille].brille = 1;
					break;
				}
				case SDLK_DOWN:{
					quiBrille++;
					quiBrille = quiBrille % 4;
					content[quiBrille].brille = 1;
					break;
				}
				case SDLK_RETURN:{
					switch (quiBrille){
					case 0:{
						if (game(&settings, ecran) == 1){
							stop = 1;
						}

						break;
					}
					case 1:{
						highscore_menu(ecran);
						break;
					}
					case 2:{
						option_menu(ecran, &settings);
						break;
					}
					case 3:{

						stop = 1;
					}
					}
					break;
				}
				default:
					break;
				}

			}

		}



	}
	SDL_FreeSurface(carre);
	SDL_FreeSurface(ecran);
	TTF_CloseFont(font);
	TTF_Quit();
	SDL_Quit();
	return 1;
}
