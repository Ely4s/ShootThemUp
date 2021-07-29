//
//  MenuPause.c
//  ShootThemUp
//
//  Created by El-idrissi Elyas on 05/01/2020.
//  Copyright © 2020 El-idrissi Elyas. All rights reserved.
//

#include "MenuPause.h"

MenuPause MenuPause_New(TextureManager * tm)
{
    MenuPause menuPause;
    menuPause.x = 210;
    menuPause.y = 620;
    menuPause.background = Sprite_New(menuPause.x, menuPause.y, 10, 10, "DivSmall", tm);
    menuPause.resume = Sprite_New(menuPause.x + 40, menuPause.y + 190, 10, 10, "ButtonBig", tm);
    menuPause.restart = Sprite_New(menuPause.x + 220, menuPause.resume.y, 10, 10, "ButtonBig", tm);
    menuPause.quit = Sprite_New(menuPause.x + 400, menuPause.resume.y, 10, 10, "ButtonBig", tm);
    menuPause.timeLeft = PRIVATE_MenuPause_timeLeftDEFAULT;
    
    return menuPause;
}

void MenuPause_Draw(MenuPause * menuPause, Window * window, Player * player, TextureManager * tm, Singleton * o)
{
    Sprite_Draw(&menuPause->background, -90, 0, 0, window);
    Sprite_Draw(&menuPause->resume, -90, 0, 0, window);
    Sprite_Draw(&menuPause->restart, -90, 0, 0, window);
    Sprite_Draw(&menuPause->quit, -90, 0, 0, window);
    
    char str[1024];
    
    memset(str, 0, sizeof str);
    sprintf(str, "Pause");
    Text_Draw(str, menuPause->x + menuPause->background.w/2, menuPause->y + 50, TextCenter, 60, "PixelFont", Utils_Color_Get(255, 80, 80), window, tm);
    
    memset(str, 0, sizeof str);
    sprintf(str, "Time pause left : %d", (int)(o->menuPause.timeLeft + 1));
    Text_Draw(str, menuPause->x + menuPause->background.w/2, menuPause->y + 130, TextCenter, 30, "PixelFont", Utils_Color_Get(0, 0, 0), window, tm);
    
    memset(str, 0, sizeof str);
    sprintf(str, "Resume");
    Text_Draw(str, menuPause->resume.x + menuPause->resume.w/2, menuPause->resume.y + 18, TextCenter, 27, "PixelFont", Utils_Color_Get(0, 0, 0), window, tm);
    
    memset(str, 0, sizeof str);
    sprintf(str, "Restart");
    Text_Draw(str, menuPause->restart.x + menuPause->restart.w/2, menuPause->restart.y + 18, TextCenter, 27, "PixelFont", Utils_Color_Get(0, 0, 0), window, tm);
    
    memset(str, 0, sizeof str);
    sprintf(str, "Quit");
    Text_Draw(str,menuPause->quit.x + menuPause->quit.w/2, menuPause->quit.y + 18, TextCenter, 27, "PixelFont", Utils_Color_Get(0, 0, 0), window, tm);
}

void MenuPause_Update(MenuPause * menuPause, Singleton * o)
{
    menuPause->timeLeft -= 1.0/60.0;
    
    if(menuPause->timeLeft <= 0)
    {
        menuPause->timeLeft = PRIVATE_MenuPause_timeLeftDEFAULT;
        o->play.inMenuPause = false;
    }
    
    if(Event_IsMouseDown(&o->event))
    {
        if(Utils_Collision_AABB(menuPause->resume.x, menuPause->resume.y, menuPause->resume.w, menuPause->resume.h, o->event.Xmouse, o->event.Ymouse, 4, 4))
        {
            menuPause->timeLeft = PRIVATE_MenuPause_timeLeftDEFAULT;
            o->play.inMenuPause = false;
        }
        if(Utils_Collision_AABB(menuPause->restart.x, menuPause->restart.y, menuPause->restart.w, menuPause->restart.h, o->event.Xmouse, o->event.Ymouse, 4, 4))
        {
            menuPause->timeLeft = PRIVATE_MenuPause_timeLeftDEFAULT;
            o->play.inMenuPause = false;
            o->game.gamePhase = ShopPhase;
            Play_Reset(o);
        }
        if(Utils_Collision_AABB(menuPause->quit.x, menuPause->quit.y, menuPause->quit.w, menuPause->quit.h, o->event.Xmouse, o->event.Ymouse, 4, 4))
        {
            o->game.isRunning = false;
        }
    }
}
