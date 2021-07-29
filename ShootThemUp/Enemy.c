//
//  Enemy.c
//  ShootThemUp
//
//  Created by El-idrissi Elyas on 05/12/2019.
//  Copyright © 2019 El-idrissi Elyas. All rights reserved.
//

#include "Enemy.h"
#include "Bullet.h"

Enemy * Enemy_NewDefault()
{
    Enemy * enemy = malloc(sizeof(Enemy));
    
    sprintf(enemy->id, "%s-%d", PRIVATE_Enemy_ID, PRIVATE_Enemy_INSTANCE);
    
    enemy->chanceWeaponMain = 200;
    enemy->chanceWeaponSecondary = 2000;
    enemy->chanceTurret = 50;
    
    enemy->spaceship = NULL;
    
    PRIVATE_Enemy_INSTANCE++;
    
    return enemy;
}


void Enemy_DrawSpaceship(Enemy * enemy, Window * window, Singleton * o)
{
    if(enemy && window)
    {
        if(enemy->spaceship)
        {
            Spaceship_Draw(enemy->spaceship, window, o);
        }
    }
}

void Enemy_AutoActionOnSpaceship(Enemy * enemy, Singleton * o)
{
    if(enemy && enemy->spaceship && o)
    {
        if(Shield_CanBeActivated(enemy->spaceship->shield))
        {
            if(Utils_Random_Int(0, 4000) == 0) Shield_Activation(enemy->spaceship->shield);
        }
        if(Turret_CanShoot(enemy->spaceship->turret))
        {
            if(Utils_Random_Int(0, enemy->chanceTurret) == 0)
            {
                int typeBullet;
                if(enemy->enemyType == EnemyTurret) typeBullet = BulletTurretSpe;
                else typeBullet = BulletTurret;
                
                Turret_Shoot(enemy->spaceship->turret, enemy->spaceship, ENEMY, typeBullet, o);
            }
        }
        if(Weapon_CanShoot(enemy->spaceship->weaponMain))
        {
            if(Utils_Random_Int(0, enemy->chanceWeaponMain) == 0)
            {
                int typeBullet;
                if(enemy->enemyType == EnemySniper) typeBullet = BulletMainWeaponSpe;
                else typeBullet = BulletMainWeapon;
                
                Weapon_Shoot(enemy->spaceship->weaponMain, ENEMY, typeBullet, o);
            }
        }
        if(Weapon_CanShoot(enemy->spaceship->weaponSecondaryOne) && Weapon_CanShoot(enemy->spaceship->weaponSecondaryTwo))
        {
            if(Utils_Random_Int(0, enemy->chanceWeaponSecondary) == 0)
            {
                int typeBullet;
                if(enemy->enemyType == EnemyArtificer) typeBullet = BulletSecondaryWeaponSpe;
                else typeBullet = BulletSecondaryWeapon;
                
                Weapon_Shoot(enemy->spaceship->weaponSecondaryOne, ENEMY, typeBullet, o);
                Weapon_Shoot(enemy->spaceship->weaponSecondaryTwo, ENEMY, typeBullet, o);
            }
        }
        
        if(Spaceship_GetLife(enemy->spaceship)/Spaceship_GetLifeMax(enemy->spaceship) <= PRIVATE_Spaceship_ratioToSmock)
        {
            Spaceship_Rotate(enemy->spaceship, 2);
            if(Spaceship_GetLife(enemy->spaceship)/Spaceship_GetLifeMax(enemy->spaceship) <= 50.0/100.0) Sprite_Anime(&enemy->spaceship->blackSmock, 0.2);
        }
        Spaceship_Move(enemy->spaceship, 0, 1);
    }
}

void Enemy_SetSpaceship(Enemy * enemy, Spaceship * spaceship)
{
    if(enemy && spaceship)
    {
        if(spaceship->weaponMain)
        {
            spaceship->weaponMain->speedBullet += Spaceship_GetTotalSpeed(spaceship);
//            spaceship->weaponMain->cooldownMax *= 15;
        }
        if(spaceship->weaponSecondaryOne)
        {
            spaceship->weaponSecondaryOne->speedBullet += Spaceship_GetTotalSpeed(spaceship);

//            spaceship->weaponSecondaryOne->cooldownMax *= 15;
        }
        if(spaceship->weaponSecondaryTwo)
        {
            spaceship->weaponSecondaryTwo->speedBullet += Spaceship_GetTotalSpeed(spaceship);
//            spaceship->weaponSecondaryTwo->cooldownMax *= 15;
        }
        
        enemy->spaceship = spaceship;
    }
}

void Enemy_SpaceshipHamper(Enemy * enemy)
{
    if(enemy && enemy->spaceship)
    {
        
        enemy->spaceship->totalLifeMax = (enemy->spaceship->totalLifeMax * 0.028);
        enemy->spaceship->totalLife = enemy->spaceship->totalLifeMax;
        enemy->spaceship->shield->lifeMax  = (enemy->spaceship->shield->lifeMax * 0.028);
        enemy->spaceship->shield->life = enemy->spaceship->shield->lifeMax;
        
//        if(spaceship->body) spaceship->body->angle += ;
//        if(spaceship->reactor)spaceship->reactor->angle += ;
//        if(spaceship->reactorSecondaryOne)spaceship->reactorSecondaryOne->angle += ;
//        if(spaceship->reactorSecondaryTwo)spaceship->reactorSecondaryTwo->angle += ;
//        if(spaceship->weaponMain)spaceship->weaponMain->angle += ;
//        if(spaceship->weaponSecondaryOne) spaceship->weaponSecondaryOne->angle += ;
//        if(spaceship->weaponSecondaryTwo) spaceship->weaponSecondaryTwo->angle += ;
//        if(spaceship->turret) spaceship->turret->angle += ;
//
//        spaceship->weaponMain->cooldownMax *= 15;
//        spaceship->weaponSecondaryOne->cooldownMax *= 10;
//        spaceship->weaponSecondaryTwo->cooldownMax *= 10;
    }
    
}
void Enemy_Free(Enemy * enemy)
{
    if(enemy)
    {
        if(enemy->spaceship) Spaceship_Free(enemy->spaceship);
        free(enemy); enemy = NULL;
    }
}

