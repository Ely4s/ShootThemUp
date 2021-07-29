//
//  MenuDead.c
//  ShootThemUp
//
//  Created by El-idrissi Elyas on 22/12/2019.
//  Copyright © 2019 El-idrissi Elyas. All rights reserved.
//

#include "MenuDead.h"


MenuDead MenuDead_New(TextureManager * tm)
{
    MenuDead menuDead;
    menuDead.background = Sprite_New(220, 600, 10, 10, "DivBig", tm);
    menuDead.retry = Sprite_New(menuDead.background.x + 40, menuDead.background.y + 300, 10, 10, "ButtonBig", tm);
    menuDead.shop = Sprite_New(menuDead.background.x + 220, menuDead.retry.y, 10, 10, "ButtonBig", tm);
    menuDead.quit = Sprite_New(menuDead.background.x + 400, menuDead.retry.y, 10, 10, "ButtonBig", tm);
    
    return menuDead;
}

void MenuDead_Draw(MenuDead * menuDead, Window * window, Player * player, TextureManager * tm, Singleton * o)
{
    Sprite_Draw(&menuDead->background, -90, 0, 0, window);
    Sprite_Draw(&menuDead->retry, -90, 0, 0, window);
    char str[1024];
    
    memset(str, 0, sizeof str);
    sprintf(str, "Retry");
    Text_Draw(str, menuDead->retry.x + menuDead->retry.w/2, menuDead->retry.y + 10, TextCenter, 40, "PixelFont", Utils_Color_Get(0, 0, 0), window, tm);
    
    Sprite_Draw(&menuDead->shop, -90, 0, 0, window);
    memset(str, 0, sizeof str);
    sprintf(str, "Shop");
    Text_Draw(str,menuDead->shop.x + menuDead->shop.w/2, menuDead->shop.y + 10, TextCenter, 40, "PixelFont", Utils_Color_Get(0, 0, 0), window, tm);
    
    memset(str, 0, sizeof str);
    sprintf(str, "GAME OVER");
    Text_Draw(str, menuDead->background.x + menuDead->background.w/2, menuDead->background.y + 50, TextCenter, 60, "PixelFont", Utils_Color_Get(255, 80, 80), window, tm);
    
    memset(str, 0, sizeof str);
    sprintf(str, "at Level %d", o->play.level);
    Text_Draw(str, menuDead->background.x + menuDead->background.w/2, menuDead->background.y + 130, TextCenter, 45, "PixelFont", Utils_Color_Get(0, 0, 0), window, tm);
    
    memset(str, 0, sizeof str);
    sprintf(str, "Total :");
    Text_Draw(str, menuDead->background.x + menuDead->background.w/2, menuDead->background.y + 190, TextCenter, 30, "PixelFont", Utils_Color_Get(0, 0, 0), window, tm);
    
    memset(str, 0, sizeof str);
    sprintf(str, "%d kill | %d missed", player->score, player->missed);
    Text_Draw(str, menuDead->background.x + menuDead->background.w/2, menuDead->background.y + 240, TextCenter, 30, "PixelFont", Utils_Color_Get(0, 0, 0), window, tm);
    
    Sprite_Draw(&menuDead->quit, -90, 0, 0, window);
    memset(str, 0, sizeof str);
    sprintf(str, "Quit");
    Text_Draw(str,menuDead->quit.x + menuDead->quit.w/2, menuDead->quit.y + 10, TextCenter, 40, "PixelFont", Utils_Color_Get(0, 0, 0), window, tm);
}

void MenuDead_Update(MenuDead * menuDead, Singleton * o)
{
    if(Event_IsMouseDown(&o->event))
    {
        if(Utils_Collision_AABB(menuDead->retry.x, menuDead->retry.y, menuDead->retry.w, menuDead->retry.h, o->event.Xmouse, o->event.Ymouse, 4, 4))
        {
            Play_Reset(o);
        }
        if(Utils_Collision_AABB(menuDead->shop.x, menuDead->shop.y, menuDead->shop.w, menuDead->shop.h, o->event.Xmouse, o->event.Ymouse, 4, 4) && !o->player->spaceship)
        {
            o->game.gamePhase = ShopPhase;
            Play_Reset(o);
        }
        if(Utils_Collision_AABB(menuDead->quit.x, menuDead->quit.y, menuDead->quit.w, menuDead->quit.h, o->event.Xmouse, o->event.Ymouse, 4, 4))
        {
            o->game.isRunning = false;
        }
    }
}
