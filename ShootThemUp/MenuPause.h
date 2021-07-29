//
//  MenuPause.h
//  ShootThemUp
//
//  Created by El-idrissi Elyas on 05/01/2020.
//  Copyright © 2020 El-idrissi Elyas. All rights reserved.
//

#ifndef MenuPause_h
#define MenuPause_h

#include "main.h"

#include "Sprite.h"
#include "Text.h"
#include "Event.h"
#include "Play.h"
#include "Utils.h"

static float PRIVATE_MenuPause_timeLeftDEFAULT = 10;

MenuPause MenuPause_New(TextureManager * tm);
void MenuPause_Draw(MenuPause * menuPause, Window * window, Player * player, TextureManager * tm, Singleton * o);
void MenuPause_Update(MenuPause * menuPause, Singleton * o);

#endif /* MenuPause_h */
