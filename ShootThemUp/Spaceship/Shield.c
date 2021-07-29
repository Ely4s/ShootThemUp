//
//  Shield.c
//  ShootThemUp
//
//  Created by El-idrissi Elyas on 17/12/2019.
//  Copyright © 2019 El-idrissi Elyas. All rights reserved.
//

#include "Shield.h"

void Shield_SetPos(Shield * shield, float x, float y)
{
    if(shield)
    {
        shield->x = x;
        shield->y = y;
        shield->sprite.x = x;
        shield->sprite.y = y;
    }
}

bool Shield_CanBeActivated(Shield * shield)
{
    if(shield)
    {
        if(shield->cooldown <= 0 && !shield->isActivated) return true;
        else return false;
    }
    else
    {
        return false;
    }
}

void Shield_AddDamage(Shield * shield, float damage)
{
    if(shield)
    {
        shield->life -= damage;
        if(shield->life <= 0)
        {
            shield->life = 0;
            shield->lifeTime = 0;
            shield->isActivated = false;
        }
    }
}

void Shield_Activation(Shield * shield)
{
    if(shield && Shield_CanBeActivated(shield))
    {
        shield->isActivated = true;
        shield->life = shield->lifeMax;
        shield->lifeTime = shield->lifeTimeMax;
        shield->cooldown = shield->cooldownMax;
    }
}

void Shield_LifeTimeUpdate(Shield * shield)
{
    if(shield)
    {
        if(shield->isActivated)
        {
            shield->lifeTime -= 1;
            if(shield->lifeTime <= 0)
            {
                shield->lifeTime = 0;
                shield->life = 0;
                shield->isActivated = false;
            }
        }
    }
}


void Shield_CooldownUpdate(Shield * shield)
{
    if(shield)
    {
        if(!shield->isActivated)
        {
            shield->cooldown -= 1;
            if(shield->cooldown <= 0)
            {
                shield->cooldown = 0;
            }
        }
    }
}

bool Shield_isActivated(Shield * shield)
{
    if(shield)
    {
        return shield->isActivated;
    }
    else
    {
        return false;
    }
}

void Shield_Free(Shield * shield)
{
    if(shield)
    {
        free(shield);
        shield = NULL;
    }
}
