//
//  Weapon.c
//  ShootThemUp
//
//  Created by El-idrissi Elyas on 12/12/2019.
//  Copyright © 2019 El-idrissi Elyas. All rights reserved.
//

#include "Weapon.h"

void Weapon_SetPos(Weapon * weapon, float x, float y)
{
    if(weapon)
    {
        weapon->x = x;
        weapon->y = y;
        weapon->sprite.x = x;
        weapon->sprite.y = y;
    }
}

void Weapon_Move(Weapon * weapon, float xPlus, float yPlus)
{
    if(weapon)
    {
        weapon->x += xPlus;
        weapon->y += yPlus;
        weapon->sprite.x += xPlus;
        weapon->sprite.y += yPlus;
    }
}

void Weapon_Shoot(Weapon * weapon, TeamType teamType, BulletType bulletType, Singleton * o)
{
    if(weapon)
    {
        if(Weapon_CanShoot(weapon))
        {
            if(o)
            {
                float radian = Utils_Math_DegreToRadian(weapon->angle);
            
                Bullet * b;
                
                b = PatternManager_GetBulletPattern(&o->pm, bulletType);
                
                b->x = weapon->x + weapon->slotPos.x - b->w/2;
                b->y = weapon->y + weapon->slotPos.y - b->h;
                
                float plusX = 0;
                float plusY = 0;
                Utils_Math_SetPosAtDistanceRelativeToAngle(&plusX, &plusY, radian, weapon->h);
                
                b->x += plusX;
                b->y += plusY;
                
                b->speed = weapon->speedBullet;
                b->damage = weapon->damage;
                b->sprite.x = b->x;
                b->sprite.y = b->y;
                b->angle = weapon->angle;
                b->teamType = teamType;
                
                if(teamType == PLAYER) Singleton_AddBullet(o, b);
                if(teamType == ENEMY) Singleton_AddBullet(o, b);
                
                Weapon_ResetCooldown(weapon);
            }
        }
    }
}

float Weapon_GetWeaponSlotPosXAbsolute(Weapon * weapon)
{
    if(weapon)
    {
        return weapon->x + weapon->slotPos.x;
    }
    else
    {
        return 0;
    }
}

float Weapon_GetWeaponSlotPosYAbsolute(Weapon * weapon)
{
    if(weapon)
    {
        return weapon->y + weapon->slotPos.y;
    }
    else
    {
        return 0;
    }
}

float Weapon_GetDamagePerSecond(Weapon * weapon)
{
    if(weapon)
    {
        
        return weapon->damage * (weapon->cooldownMax * (1.0/60.0));
    }
    else return 0;
}

void Weapon_ResetCooldown(Weapon * weapon)
{
    if(weapon)
    {
        weapon->cooldown = weapon->cooldownMax;
    }
}

void Weapon_CooldownUpdate(Weapon * weapon)
{
    if(weapon)
    {
        weapon->cooldown -= 1;
        if(weapon->cooldown < 0) weapon->cooldown = 0;
    }
}

bool Weapon_CanShoot(Weapon * weapon)
{
    if(weapon)
    {
        if(weapon->cooldown == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

void Weapon_Free(Weapon * weapon)
{
    if(weapon)
    {
        free(weapon);
        weapon = NULL;
    }
}

