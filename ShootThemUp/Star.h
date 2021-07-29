//
//  Star.h
//  ShootThemUp
//
//  Created by El-idrissi Elyas on 05/01/2020.
//  Copyright © 2020 El-idrissi Elyas. All rights reserved.
//

#ifndef Star_h
#define Star_h

static float PRIVATE_Star_speed = 7;

#include "main.h"
#include "Sprite.h"
#include "Singleton.h"

void Star_Generate(Singleton * o, bool forAllScreen);
void Star_UpdateAll(Singleton * o);
void Star_DrawAll(Singleton * o);
void Star_FreeAll(Singleton * o);

#endif /* Star_h */
