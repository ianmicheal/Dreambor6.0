/*
 * OpenBOR - http://www.chronocrash.com
 * -----------------------------------------------------------------------
 * All rights reserved, see LICENSE in OpenBOR root for details.
 *
 * Copyright (c) 2004 - 2014 OpenBOR Team
 */


#include <SDL.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <string.h>
#include "globals.h"



//#define MEMTEST 1

void initSDL();
void borExit(int reset);
void openborMain(int argc, char** argv);

extern char packfile[128];
extern char paksDir[128];
extern char savesDir[128];
extern char logsDir[128];
extern char screenShotsDir[128];


