//
//  Bullet.c
//  ShootThemUp
//
//  Created by El-idrissi Elyas on 02/12/2019.
//  Copyright © 2019 El-idrissi Elyas. All rights reserved.
//

#include "Bullet.h"
#include "Sprite.h"

Bullet * Bullet_NewDefault(TextureManager * tm, int x, int y, float speed, float damage, BulletType bulletType, PatternManager * pm)
{
    Bullet * b = malloc(sizeof(Bullet));
    
    PatternManager_GetBulletPattern(pm, bulletType);
    sprintf(b->id, "%s-%d", PRIVATE_Bullet_ID, PRIVATE_Bullet_INSTANCE);
    
    b->x = x;
    b->y = y;
    
    b->w = PRIVATE_Bullet_defaultW;
    b->h = PRIVATE_Bullet_defaultH;
    
    b->speed = speed;
    
    b->damage = 10;
    
    Sprite s = Sprite_New(b->x, b->y, b->w, b->h, (char*)PRIVATE_Bullet_defaultIdleId, tm);
    
    s.indexFrame = 0;
    
    b->sprite = s;
    
    PRIVATE_Bullet_INSTANCE++;
    
    return b;
}

void Bullet_Draw(Bullet * bullet, Window * win)
{
    if(bullet)
    {
        if(bullet->effectType == ExplosiveEffect) Sprite_Draw(&bullet->spriteFlame, bullet->angle, bullet->spriteFlame.w/2, 0, win);
        Sprite_Draw(&bullet->sprite, bullet->angle, bullet->w/2, bullet->h, win);
    }
}

void Bullet_InMovePosUpdate(Bullet * bullet)
{
    bullet->x += cos(Utils_Math_DegreToRadian(bullet->angle)) * bullet->speed;
    bullet->y += sin(Utils_Math_DegreToRadian(bullet->angle)) * bullet->speed;
    
    bullet->sprite.x = bullet->x;
    bullet->sprite.y = bullet->y;
    
    if(bullet->effectType == ExplosiveEffect)
    {
        bullet->spriteFlame.x = bullet->x + bullet->w/2 - bullet->spriteFlame.w/2;
        bullet->spriteFlame.y = bullet->y + bullet->h;
        
        float plusX = 0;
        float plusY = 0;
        Utils_Math_SetPosAtDistanceRelativeToAngle(&plusX, &plusY, Utils_Math_DegreToRadian(bullet->angle), 0);
        
        bullet->spriteFlame.x += plusX;
        bullet->spriteFlame.y += plusY;
        
        bullet->spriteFlame.indexFrame += 0.3;
        if(bullet->spriteFlame.indexFrame >= bullet->spriteFlame.maxFrame)
        {
            bullet->spriteFlame.indexFrame = 0;
        }
    }
    
    if(bullet->type == BulletMainWeaponSpe || bullet->type == BulletSecondaryWeaponSpe || bullet->type == BulletTurretSpe)
    {
        if(bullet->type == BulletSecondaryWeaponSpe) bullet->sprite.indexFrame += 0.1;
        else bullet->sprite.indexFrame += 0.2;
        
        if(bullet->sprite.indexFrame >= bullet->sprite.maxFrame)
        {
            bullet->sprite.indexFrame = 0;
        }
    }
    
}
bool Bullet_IsOutOff(Bullet * bullet, int x, int y, int w, int h)
{
    if(bullet) return !Utils_Collision_AABB(bullet->x, bullet->y, bullet->w, bullet->h, x, y, w, h);
    else return false;
}

void Bullet_Free(Bullet * bullet)
{
    if(bullet)
    {
        free(bullet);
        bullet = NULL;
    }
}
