//
//  Sprite.h
//  ShootThemUp
//
//  Created by El-idrissi Elyas on 26/11/2019.
//  Copyright © 2019 El-idrissi Elyas. All rights reserved.
//

#ifndef Sprite_h
#define Sprite_h

#include "main.h"

#include "Window.h"
#include "TextureManager.h"

Sprite Sprite_New(float x, float y, int ifErrorW, int ifErrorH, char * textureId, TextureManager * tm);
void Sprite_SetPos(Sprite * sprite, float x, float y);
int Sprite_GetPosX(Sprite * sprite);
int Sprite_GetPosY(Sprite * sprite);

void Sprite_Anime(Sprite * sprite, float addAnime);

void Sprite_PosOffSet(Sprite * sprite, float xOffSet, float yOffSet);

void Sprite_SetTexture(Sprite * sprite, char * textureId, TextureManager * tm);

void Sprite_Draw(Sprite * sprite, float angle, float x, float y, Window * win);

bool Sprite_IsAnimationEnd(Sprite * sprite);

void Sprite_Free(Sprite * sprite);
#endif /* Sprite_h */
