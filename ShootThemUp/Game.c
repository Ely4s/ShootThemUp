//
//  Game.c
//  ShootThemUp
//
//  Created by El-idrissi Elyas on 03/01/2020.
//  Copyright © 2020 El-idrissi Elyas. All rights reserved.
//

#include "Game.h"

void Game_Update(Game * game, Singleton * o)
{
    Event_HandleTypedKey(&o->event);
    Event_HandleRealTimeInput(&o->event);
    Window_CheckForCloseEvent(&o->game, &o->event);
    
    if(game->gamePhase == PlayPhase && !o->play.inMenuPause)
    {
        Play_Update(&o->play, o);
    }
    if(o->play.inMenuPause)
    {
        MenuPause_Update(&o->menuPause, o);
    }
    if(game->gamePhase == ShopPhase)
    {
        Shop_Update(&o->shop, o);
    }
}

void Game_Draw(Game * game, Singleton * o)
{
    Window_Clear(&o->window);
    
    if(game->gamePhase == PlayPhase)
    {
        Play_Draw(&o->play, o);
    }
    if(o->play.inMenuPause)
    {
        MenuPause_Draw(&o->menuPause, &o->window, o->player, &o->tm, o);
    }
    if(game->gamePhase == ShopPhase)
    {
        Shop_Draw(&o->shop, o);
    }
    Window_Draw(&o->window);
}

void Game_Wait(Game * game, Timer * t)
{
    Utils_Timer_Stop(t);
    
    if(Utils_Timer_TimeMs(t)<= game->fps)
    {
        Utils_Sleep_Ms(game->fps - Utils_Timer_TimeMs(t));
    }
    
    Utils_Timer_Stop(t);
}

void Game_SetFps(Game * game, float fps)
{
    game->fps = (1.0/fps) * 1000.0;
}

void Game_Start(Game * game)
{
    game->isRunning = true;
}

void Game_Over(Game * game)
{
    game->isRunning = false;
}

bool Game_GetIsRunning(Game * game)
{
    return game->isRunning;
}
