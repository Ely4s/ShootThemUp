//
//  Window.h
//  ShootThemUp
//
//  Created by El-idrissi Elyas on 26/11/2019.
//  Copyright © 2019 El-idrissi Elyas. All rights reserved.
//
#ifndef Window_h
#define Window_h

#include "main.h"
#include "Event.h"

static const int PRIVATE_Window_maxTileSize = 32;
static const char * PRIVATE_Window_defaultName = "Window";

void Window_CheckForCloseEvent(Game * game, Event * e);
Window Window_New(char * strWindowName, int w, int h);
void Window_SetTitle(Window * win, char * strWindowName);
void Window_SetSize(Window * win, int w, int h);
void Window_SetBackgroundColor(Window * win, SDL_Color color);
void Window_SetRenderer(Window * win);
void Window_Clear(Window * win);
void Window_Draw(Window * win);
void Window_Free(Window * win);

#endif /* Window_h */
