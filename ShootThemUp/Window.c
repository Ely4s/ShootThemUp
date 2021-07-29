//
//  Window.c
//  ShootThemUp
//
//  Created by El-idrissi Elyas on 26/11/2019.
//  Copyright © 2019 El-idrissi Elyas. All rights reserved.
//

#include "Window.h"
#include "Utils.h"
#include "Game.h"

Window Window_New(char * strWindowName, int w, int h)
{
    Window win;
    
    win.window = SDL_CreateWindow(NULL, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_FOREIGN | SDL_WINDOW_ALLOW_HIGHDPI);

    Window_SetSize(&win, w, h);
    Window_SetTitle(&win, strWindowName);
    Window_SetRenderer(&win);
    
    Window_SetBackgroundColor(&win, Utils_Color_Get(0, 0, 0));
    
    return win;
}

void Window_CheckForCloseEvent(Game * game, Event * e)
{    
    if (Event_IsEventType(e, SDL_QUIT)) Game_Over(game);

    if(Event_IsEventRealTime(e, SDL_SCANCODE_ESCAPE))
    {
        Game_Over(game);
    }
}

void Window_SetTitle(Window * win, char * strWindowName)
{
    
    if(strWindowName)
    {
        snprintf(win->title, PRIVATE_Window_maxTileSize+1, "%s", strWindowName);
    }
    else
    {
        snprintf(win->title, PRIVATE_Window_maxTileSize+1, "%s", PRIVATE_Window_defaultName);
    }
    
    SDL_SetWindowTitle(win->window, win->title);
}

void Window_SetSize(Window * win, int w, int h)
{
    SDL_SetWindowSize(win->window, w, h);
    win->w = w*2;
    win->h = h*2;
}

void Window_SetBackgroundColor(Window * win, SDL_Color color)
{
    SDL_SetRenderDrawColor(win->renderer, color.r, color.g, color.b, 0);
    win->defaultColor = color;
}

void Window_SetRenderer(Window * win)
{
    win->renderer = SDL_CreateRenderer(win->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawBlendMode(win->renderer, SDL_BLENDMODE_BLEND);
//    SDL_Rect rect = {0, 0, 100, 100};
//    SDL_RenderSetViewport(win->renderer, &rect);
//    SDL_RenderSetIntegerScale(win->renderer, SDL_TRUE);
}

void Window_Clear(Window * win)
{
    SDL_RenderClear(win->renderer);
}

void Window_Draw(Window * win)
{
    SDL_RenderPresent(win->renderer);
}

void Window_Free(Window * win)
{
    SDL_DestroyRenderer(win->renderer);
    SDL_DestroyWindow(win->window);
}
