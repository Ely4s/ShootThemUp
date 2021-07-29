//
//  MenuDead.h
//  ShootThemUp
//
//  Created by El-idrissi Elyas on 22/12/2019.
//  Copyright © 2019 El-idrissi Elyas. All rights reserved.
//

#ifndef MenuDead_h
#define MenuDead_h

#include "main.h"
#include "Sprite.h"
#include "Utils.h"
#include "Game.h"
#include "Shop.h"

MenuDead MenuDead_New(TextureManager * tm);
void MenuDead_Draw(MenuDead * menuDead, Window * window, Player * player, TextureManager * tm, Singleton * o);
void MenuDead_Update(MenuDead * menuDead, Singleton * o);

#endif /* MenuDead_h */
