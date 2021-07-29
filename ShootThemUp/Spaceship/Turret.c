//
//  Turret.c
//  ShootThemUp
//
//  Created by El-idrissi Elyas on 17/12/2019.
//  Copyright © 2019 El-idrissi Elyas. All rights reserved.
//

#include "Turret.h"

void Turret_SetPos(Turret * turret, float x, float y)
{
    if(turret)
    {
        turret->x = x;
        turret->y = y;
        turret->sprite.x = x;
        turret->sprite.y = y;
    }
}

void Turret_Shoot(Turret * turret, Spaceship * spaceship, TeamType teamType, BulletType bulletType, Singleton * o)
{
    if(turret)
    {
        if(teamType == PLAYER)
        {
            
            if(!(!turret->cible && !turret->isManual) && array_size(o->enemy) != 0 && turret->cooldown <= 0 && o)
            {
                float radian = Utils_Math_DegreToRadian(turret->angle);
                float shootX = Turret_GetTurretSlotPosXAbsolute(turret);
                float shootY = Turret_GetTurretSlotPosYAbsolute(turret);
                Utils_Math_SetPosAtDistanceRelativeToAngle(&shootX, &shootY, radian, turret->slotPos.y);
                
                
                Bullet * b = PatternManager_GetBulletPattern(&o->pm, bulletType);
                
                Utils_Math_SetPosAtDistanceRelativeToAngle(&shootX, &shootY, radian - Utils_Math_DegreToRadian(90), turret->w/4);
                b->x = shootX - b->w/2;
                b->y = shootY - b->h;
                b->sprite.x = b->x;
                b->sprite.y = b->y;
                b->angle = turret->angle;
                b->speed = turret->speedBullet;
                b->damage = turret->damage;
                b->teamType = teamType;
                Singleton_AddBullet(o, b);
                
                Utils_Math_SetPosAtDistanceRelativeToAngle(&shootX, &shootY, radian - Utils_Math_DegreToRadian(-90), turret->w/2);
                Bullet * b1 = PatternManager_GetBulletPattern(&o->pm, bulletType);
                b1->x = shootX - b1->w/2;
                b1->y = shootY - b1->h;
                b1->sprite.x = b1->x;
                b1->sprite.y = b1->y;
                b1->angle = turret->angle;
                b1->speed = turret->speedBullet;
                b1->damage = turret->damage;
                b1->teamType = teamType;
                Singleton_AddBullet(o, b1);
                
                turret->cooldown = turret->cooldownMax;
            }
        }
        
        if(teamType == ENEMY)
        {
            if(!(!turret->cible && !turret->isManual) && o->player && turret->cooldown <= 0 && o)
            {
                float radian = Utils_Math_DegreToRadian(turret->angle);
                float shootX = Turret_GetTurretSlotPosXAbsolute(turret);
                float shootY = Turret_GetTurretSlotPosYAbsolute(turret);
                Utils_Math_SetPosAtDistanceRelativeToAngle(&shootX, &shootY, radian, turret->h);
                
                
                Bullet * b = PatternManager_GetBulletPattern(&o->pm, bulletType);
                
                Utils_Math_SetPosAtDistanceRelativeToAngle(&shootX, &shootY, radian - Utils_Math_DegreToRadian(90), turret->w/4);
                b->x = shootX - b->w/2;
                b->y = shootY - b->h;
                b->sprite.x = b->x;
                b->sprite.y = b->y;
                b->angle = turret->angle;
                b->speed = turret->speedBullet;
                b->damage = turret->damage;
                b->teamType = teamType;
                Singleton_AddBullet(o, b);
                
                Utils_Math_SetPosAtDistanceRelativeToAngle(&shootX, &shootY, radian - Utils_Math_DegreToRadian(-90), turret->w/2);
                Bullet * b1 = PatternManager_GetBulletPattern(&o->pm, bulletType);
                b1->x = shootX - b1->w/2;
                b1->y = shootY - b1->h;
                b1->sprite.x = b1->x;
                b1->sprite.y = b1->y;
                b1->angle = turret->angle;
                b1->speed = turret->speedBullet;
                b1->damage = turret->damage;
                b1->teamType = teamType;
                Singleton_AddBullet(o, b1);
                
                turret->cooldown = turret->cooldownMax;
            }
        }
    }
}

float Turret_GetTurretSlotPosXAbsolute(Turret * turret)
{
    if(turret)
    {
        return turret->x + turret->slotPos.x;
    }
    else
    {
        return 0;
    }
}

float Turret_GetTurretSlotPosYAbsolute(Turret * turret)
{
    if(turret)
    {
        return turret->y + turret->slotPos.y;
    }
    else
    {
        return 0;
    }
}

float Turret_GetDamagePerSecond(Turret * turret)
{
    if(turret)
    {
        float a = turret->damage * (turret->cooldownMax * (1.0/60.0));
        return a;
    }
    else return 0;
}

void Turret_ResetCooldown(Turret * turret)
{
    if(turret)
    {
        turret->cooldown = turret->cooldownMax;
    }
}

void Turret_CooldownUpdate(Turret * turret)
{
    if(turret)
    {
        turret->cooldown -= 1;
        if(turret->cooldown < 0) turret->cooldown = 0;
    }
}

void Turret_CibleUpdate(Turret * turret, TeamType teamType, Spaceship * spaceship, Singleton * o)
{
    if(turret)
    {
        float radian = 0;
        
        int targetX = 0;
        int targetY = 0;
        
        float distance = 0;
        
        if(teamType == PLAYER)
        {
            Enemy * enemy = NULL;
            
            if(turret->isManual == true)
            {
                targetX = o->event.Xmouse;
                targetY = o->event.Ymouse;
            }
            else
            {
                for(int i = 0; i < array_size(o->enemy); i++)
                {
                    Enemy * enemyTemp = array_get_at(o->enemy, i);
                    
                    if(enemyTemp && enemyTemp->spaceship)
                    {
                        float distanceTemp = Utils_Math_DistanceBetweenPoint(enemyTemp->spaceship->x + enemyTemp->spaceship->w/2, enemyTemp->spaceship->y + enemyTemp->spaceship->h/2, turret->x + turret->slotPos.x, turret->y + turret->slotPos.y);
                        
                        if(i == 0)
                        {
                            distance = distanceTemp;
                            enemy = enemyTemp;
                        }
                        else if (distanceTemp < distance)
                        {
                            distance = distanceTemp;
                            enemy = enemyTemp;
                        }
                    }
                }
                if(enemy)
                {
                    float distance = Utils_Math_DistanceBetweenPoint(enemy->spaceship->x + enemy->spaceship->w/2, enemy->spaceship->y + enemy->spaceship->h/2, turret->x + turret->slotPos.x, turret->y + turret->slotPos.y);
                    float yOff = (distance/turret->speedBullet) * Spaceship_GetTotalSpeed(enemy->spaceship);
                    targetX = enemy->spaceship->x + enemy->spaceship->w/2 ; //+ Utils_Random_Int(-150, 150);
                    targetY = enemy->spaceship->y + enemy->spaceship->h/2 + yOff; //+ Utils_Random_Int(-150, 150);
                    
                    turret->cible = enemy;
                }
            }
            
            radian = Utils_Math_GetRadianFromTwoPoints(turret->x + turret->slotPos.x, turret->y + turret->slotPos.y, targetX, targetY);
            
            if(!enemy && !turret->isManual && spaceship) radian = Utils_Math_DegreToRadian(spaceship->angle);
            if(!enemy && !turret->isManual && !spaceship)
            {
                radian = Utils_Math_DegreToRadian(90);
                turret->cible = NULL;
            }
        }
    
        if(teamType == ENEMY)
        {
            Player * player = o->player;
            
            if(player && player->spaceship)
            {
                targetX = player->spaceship->x + player->spaceship->w/2 ; //+ Utils_Random_Int(-150, 150);
                targetY = player->spaceship->y + player->spaceship->h/2 ; //+ Utils_Random_Int(-150, 150);
                
                turret->cible = player;
            }
            
            radian = Utils_Math_GetRadianFromTwoPoints(turret->x + turret->slotPos.x, turret->y + turret->slotPos.y, targetX, targetY);
            if(!player && !turret->isManual && spaceship) radian = Utils_Math_DegreToRadian(spaceship->angle);
            if(!player && !turret->isManual && !spaceship) radian = Utils_Math_DegreToRadian(90);
        }
        
        int target = (int)Utils_Math_RadianToDegre(radian);
        int current = (turret->angle);
        
        int final = target - current;
        
        for(int i = 0; i < turret->speedRotation && final != 0; i++)
        {
            if(final > 180)
            {
                final -= 360;
            }
            
            if(final <= -180)
            {
                final += 360;
            }
            
            if(final > 0)
            {
                turret->angle += 0.1;
            }
            if (final < 0)
            {
                turret->angle -= 0.1;
            }
            
            current = (turret->angle);
            final = target - current;
        }
    }
}

bool Turret_CanShoot(Turret * turret)
{
    if(turret)
    {
        if(turret->cooldown == 0)
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

void Turret_Free(Turret * turret)
{
    if(turret)
    {
        free(turret);
        turret = NULL;
    }
}
