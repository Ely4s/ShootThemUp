//
//  Explosion.h
//  ShootThemUp
//
//  Created by El-idrissi Elyas on 18/12/2019.
//  Copyright © 2019 El-idrissi Elyas. All rights reserved.
//

#ifndef Explosion_h
#define Explosion_h

#include "main.h"
#include "Sprite.h"

Explosion * Explosion_New(float size, float damage, int x, int y, TeamType teamType, TextureManager * tm);
void Explosion_Draw(Explosion * explosion, Window * win);
void Explosion_Free(Explosion * explosion);
void Explosion_Anime(Explosion * explosion);
#endif /* Explosion_h */
