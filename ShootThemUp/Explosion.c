//
//  Explosion.c
//  ShootThemUp
//
//  Created by El-idrissi Elyas on 18/12/2019.
//  Copyright © 2019 El-idrissi Elyas. All rights reserved.
//

#include "Explosion.h"

Explosion * Explosion_New(float size, float damage, int x, int y, TeamType teamType, TextureManager * tm)
{
    Explosion * explosion = malloc(sizeof(Explosion));
    
    explosion->x = x - size/2;
    explosion->y = y - size/2;
    explosion->w = size;
    explosion->h = size;
    
    explosion->sprite = Sprite_New(explosion->x, explosion->y, explosion->w, explosion->h, "Explosion", tm);
    explosion->sprite.w = explosion->w;
    explosion->sprite.h = explosion->h;
    
    explosion->damage = damage;
    
    explosion->teamType = teamType;
    
    return explosion;
}

void Explosion_Draw(Explosion * explosion, Window * win)
{
    if(explosion)
    {
        Sprite_Draw(&explosion->sprite, 0, explosion->w/2, explosion->h/2, win);
    }
}

void Explosion_Free(Explosion * explosion)
{
    if(explosion)
    {
        free(explosion);
        explosion = NULL;
    }
}

void Explosion_Anime(Explosion * explosion)
{
    explosion->sprite.indexFrame += 0.3;
    
    if(explosion->sprite.indexFrame >= explosion->sprite.maxFrame)
    {
        explosion->sprite.indexFrame = 0;
    }
}
