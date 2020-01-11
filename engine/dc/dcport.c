/*
 * OpenBOR - http://www.LavaLit.com
 * -----------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in OpenBOR root for details.
 *
 * Copyright (c) 2004 - 2011 OpenBOR Team
 */

/////////////////////////////////////////////////////////////////////////////

#include "dcport.h"
#include "timer.h"
#include "openbor.h"
#include "packfile.h"
#include "menu.h"
#include "SDL_framerate.h"
#include <SDL.h>
#include <kos.h>
/////////////////////////////////////////////////////////////////////////////
char packfile[128] = {"bor.pak"};
//char packfile[256] = {"bor.pak"};
int cd_lba;
#ifndef SKIP_CODE
	char pakname[256];
#endif

char paksDir[128] = {"Paks"};
char savesDir[128] = {"Saves"};
char logsDir[128] = {"Logs"};
char screenShotsDir[128] = {"ScreenShots"};
/////////////////////////////////////////////////////////////////////////////

unsigned readmsb32(const unsigned char *src)
{
	return
		((((unsigned)(src[0])) & 0xFF) << 24) |
		((((unsigned)(src[1])) & 0xFF) << 16) |
		((((unsigned)(src[2])) & 0xFF) <<  8) |
		((((unsigned)(src[3])) & 0xFF) <<  0);
}

// SDL 1.2
void initSDL1()
{
	const SDL_VideoInfo* video_info;
	int init_flags = SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER | SDL_INIT_JOYSTICK;
	SDL_Surface *icon;


	if(SDL_Init(init_flags) < 0)
	{
		printf("SDL Failed to Init!!!! (%s)\n", SDL_GetError());
		borExit(0);
	}
	SDL_ShowCursor(SDL_DISABLE);
	atexit(SDL_Quit);



	// Store the monitor's current resolution before setting the video mode for the first time
	video_info = SDL_GetVideoInfo();


	//SDL_initFramerate(&framerate_manager);
	//SDL_setFramerate(&framerate_manager, 200);
}

/////////////////////////////////////////////////////////////////////////////

void borExit(int reset)
{
	arch_reboot();
}

/////////////////////////////////////////////////////////////////////////////
int main(int argc, char *argv[])
//int main(int argc, char** argv)


{

	setSystemRam();
//	initSDL1();
    packfile_mode(0);
	getRamStatus(BYTES);
	Menu();
	getPakName(pakname, -1);
	//packfile_mode(0);
	if((cd_lba = gdrom_init()) <= 0)
	{
		printf("gdrom_init failed\n");
		arch_reboot();
	}
	openborMain(argc, argv);
	return 0;
}


/////////////////////////////////////////////////////////////////////////////
