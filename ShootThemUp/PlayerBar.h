//
//  PlayerBar.h
//  ShootThemUp
//
//  Created by El-idrissi Elyas on 21/12/2019.
//  Copyright © 2019 El-idrissi Elyas. All rights reserved.
//

#ifndef PlayerBar_h
#define PlayerBar_h

#include "main.h"
#include "Sprite.h"

PlayerBar PlayerBar_New(int x, int y, Singleton * o);

void PlayerBar_Draw(PlayerBar * playerBar, Window * window);
void PlayerBar_Update(PlayerBar * playerBar, Player * player);

#endif /* PlayerBar_h */
