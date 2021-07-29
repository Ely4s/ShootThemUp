//
//  LevelManager.c
//  ShootThemUp
//
//  Created by El-idrissi Elyas on 03/01/2020.
//  Copyright © 2020 El-idrissi Elyas. All rights reserved.
//

#include "LevelManager.h"

Enemy * LevelManager_NewEnemy(Singleton * o, EnemyType enemyType, int level)
{
    Enemy * enemy = Enemy_NewDefault();
    Spaceship * spaceship = LevelManager_EnemyApplyVisual(o, enemyType);
    
    if(spaceship)
    {
        Spaceship_Rotate(spaceship, 180);
        Spaceship_SetPos(spaceship,  Utils_Random_Int(0, o->window.w - spaceship->w), - spaceship->h - 30);
        Enemy_SetSpaceship(enemy, spaceship);
        
        LevelManager_EnemyApplyLevel(o, enemy, level);
        LevelManager_EnemyApplyType(o, enemy, enemyType);
        
        return enemy;
    }
    else
    {
        return NULL;
    }
}

Spaceship * LevelManager_EnemyApplyVisual(Singleton * o, EnemyType enemyType)
{
    SpaceshipType spaceshipType = NoSpaceship;
    BodyType bodyType = NoBody;
    ReactorType reactorMType = NoReactor;
    ReactorType reactorSType = NoReactor;
    WeaponType weaponMType = NoWeapon;
    WeaponType weaponSType = NoWeapon;
    TurretType turretType = NoTurret;
    ShieldType shieldType = NoShield;
    
    if(enemyType == EnemyNormal)
    {
        spaceshipType = SpaceshipTier1;
        bodyType = BodyTier1;
        
        reactorMType = ReactorTier2;
        reactorSType = ReactorTier1;
        
        weaponMType = WeaponTier3;
        weaponSType = WeaponTier2;
        
        turretType = TurretTier2;
        
        shieldType = ShieldTier1;
    }
    if(enemyType == EnemyTank)
    {
        spaceshipType = SpaceshipTier5;
        bodyType = BodyTier5;
        
        reactorMType = ReactorTier3;
        reactorSType = ReactorTier2;
        
        weaponMType = WeaponTier3;
        weaponSType = WeaponTier2;
        
        turretType = TurretTier2;
        
        shieldType = ShieldTier1;
    }
    if(enemyType == EnemyScout)
    {
        spaceshipType = SpaceshipTier2;
        bodyType = BodyTier2;
        
        reactorMType = ReactorTier5;
        reactorSType = ReactorTier4;
        
        weaponMType = WeaponTier2;
        
        shieldType = ShieldTier1;
    }
    if(enemyType == EnemySniper)
    {
        spaceshipType = SpaceshipTier1;
        bodyType = BodyTier1;
        
        reactorMType = ReactorTier2;
        reactorSType = ReactorTier1;
        
        weaponMType = WeaponTier5;
        
        shieldType = ShieldTier1;
    }
    if(enemyType == EnemyArtificer)
    {
        spaceshipType = SpaceshipTier4;
        bodyType = BodyTier4;
        
        reactorMType = ReactorTier3;
        reactorSType = ReactorTier2;
        
        weaponSType = WeaponTier5;
        
        shieldType = ShieldTier1;
    }
    if(enemyType == EnemyTurret)
    {
        spaceshipType = SpaceshipTier3;
        bodyType = BodyTier3;
        
        reactorMType = ReactorTier3;
        reactorSType = ReactorTier2;
        
        turretType = TurretTier5;
        
        shieldType = ShieldTier1;
    }
    if(enemyType == EnemySoldier)
    {
        spaceshipType = SpaceshipTier1;
        bodyType = BodyTier1;
        
        reactorMType = ReactorTier1;
        reactorSType = ReactorTier1;
        
        weaponMType = WeaponTier1;
        weaponSType = WeaponTier1;
        
        turretType = TurretTier1;
        
        shieldType = ShieldTier1;
    }
    
    Spaceship * spaceship = Spaceship_New(spaceshipType, 0, 0, bodyType, reactorMType, reactorSType, weaponMType, weaponSType, turretType, shieldType, o);
    
    return spaceship;
}

void LevelManager_EnemyApplyLevel(Singleton * o, Enemy * enemy, int level)
{
    if(enemy && enemy->spaceship)
    {
        int min = 0;
        int max = 4;
        
        Spaceship * spaceship = enemy->spaceship;

        if(spaceship->body)
        {
            spaceship->body->lifeMax = ((float)o->lm.multiLife * (float)o->pm.body_Life[min]) + (((float)o->lm.multiLife * ((float)o->pm.body_Life[max] - (float)o->pm.body_Life[min])) * ((float)level/((float)o->lm.levelUnit/2.0)));
            spaceship->body->life = spaceship->body->lifeMax;
        }
        if(spaceship->reactor)
        {
            spaceship->reactor->lifeMax = ((float)o->lm.multiLife * (float)o->pm.reactor_Life[min]) + (((float)o->lm.multiLife * ((float)o->pm.reactor_Life[max] - (float)o->pm.reactor_Life[min])) * ((float)level/((float)o->lm.levelUnit/2.0)));
            spaceship->reactor->speed = ((float)o->lm.multiSpeed * (float)o->pm.reactor_Speed[min]) + (((float)o->lm.multiSpeed * ((float)o->pm.reactor_Speed[max] - (float)o->pm.reactor_Speed[min])) * ((float)level/((float)o->lm.levelUnit/2.0)));
            spaceship->reactor->life = spaceship->reactor->lifeMax;
        }
        if(spaceship->reactorSecondaryOne && spaceship->reactorSecondaryTwo)
        {
            spaceship->reactorSecondaryOne->lifeMax = ((float)o->lm.multiLife * (float)o->pm.reactor_Life[min]) + (((float)o->lm.multiLife * ((float)o->pm.reactor_Life[max] - (float)o->pm.reactor_Life[min])) * ((float)level/((float)o->lm.levelUnit/2.0)));
            spaceship->reactorSecondaryOne->speed = ((float)o->lm.multiSpeed * (float)o->pm.reactor_Speed[min]) + (((float)o->lm.multiSpeed * ((float)o->pm.reactor_Speed[max] - (float)o->pm.reactor_Speed[min])) * ((float)level/((float)o->lm.levelUnit)));
            spaceship->reactorSecondaryOne->life = spaceship->reactorSecondaryOne->lifeMax;
            
            spaceship->reactorSecondaryTwo->lifeMax = spaceship->reactorSecondaryOne->lifeMax;
            spaceship->reactorSecondaryTwo->speed = spaceship->reactorSecondaryOne->speed;
            spaceship->reactorSecondaryTwo->life = spaceship->reactorSecondaryTwo->lifeMax;
        }
        if(spaceship->weaponMain)
        {
            spaceship->weaponMain->lifeMax = ((float)o->lm.multiLife * (float)o->pm.weaponM_Life[min]) + (((float)o->lm.multiLife * ((float)o->pm.weaponM_Life[max] - (float)o->pm.weaponM_Life[min])) * ((float)level/((float)o->lm.levelUnit/2.0)));
            spaceship->weaponMain->damage = ((float)o->lm.multiDefault * (float)o->pm.weaponM_Damage[min]) + (((float)o->lm.multiDefault * ((float)o->pm.weaponM_Damage[max] - (float)o->pm.weaponM_Damage[min])) * ((float)level/((float)o->lm.levelUnit/2.0)));
            spaceship->weaponMain->cooldownMax = ((float)o->lm.multiDefault * (float)o->pm.weaponM_Cooldown[min]) + (((float)o->lm.multiDefault * ((float)o->pm.weaponM_Cooldown[max] - (float)o->pm.weaponM_Cooldown[min])) * ((float)level/((float)o->lm.levelUnit)));
            spaceship->weaponMain->cooldown = 0;
            spaceship->weaponMain->life = spaceship->weaponMain->lifeMax;
        }
        if(spaceship->weaponSecondaryOne && spaceship->weaponSecondaryTwo)
        {
            spaceship->weaponSecondaryOne->lifeMax = ((float)o->lm.multiLife * (float)o->pm.weaponS_Life[min]) + (((float)o->lm.multiLife * ((float)o->pm.weaponS_Life[max] - (float)o->pm.weaponS_Life[min])) * ((float)level/((float)o->lm.levelUnit/2.0)));
            spaceship->weaponSecondaryOne->damage = ((float)o->lm.multiDefault * (float)o->pm.weaponS_Damage[min]) + (((float)o->lm.multiDefault * ((float)o->pm.weaponS_Damage[max] - (float)o->pm.weaponS_Damage[min])) * ((float)level/((float)o->lm.levelUnit/2.0)));
            spaceship->weaponSecondaryOne->cooldownMax = ((float)o->lm.multiDefault * (float)o->pm.weaponS_Cooldown[min]) + (((float)o->lm.multiDefault * ((float)o->pm.weaponS_Cooldown[max] - (float)o->pm.weaponS_Cooldown[min])) * ((float)level/((float)o->lm.levelUnit)));
            spaceship->weaponSecondaryOne->cooldown = 0;
            spaceship->weaponSecondaryOne->life = spaceship->weaponSecondaryOne->lifeMax;
            
            spaceship->weaponSecondaryTwo->lifeMax = spaceship->weaponSecondaryOne->lifeMax;
            spaceship->weaponSecondaryTwo->damage = spaceship->weaponSecondaryOne->damage;
            spaceship->weaponSecondaryTwo->cooldownMax = spaceship->weaponSecondaryOne->cooldown;
            spaceship->weaponSecondaryTwo->cooldown = 0;
            spaceship->weaponSecondaryTwo->life = spaceship->weaponSecondaryTwo->lifeMax;
        }
        if(spaceship->turret)
        {
            spaceship->turret->lifeMax = ((float)o->lm.multiLife * (float)o->pm.turret_Life[min]) + (((float)o->lm.multiLife * ((float)o->pm.turret_Life[max] - (float)o->pm.turret_Life[min])) * ((float)level/((float)o->lm.levelUnit/2.0)));
            spaceship->turret->damage = ((float)o->lm.multiDefault * (float)o->pm.turret_Damage[min]) + (((float)o->lm.multiDefault * ((float)o->pm.turret_Damage[max] - (float)o->pm.turret_Damage[min])) * ((float)level/((float)o->lm.levelUnit/2.0)));
            spaceship->turret->cooldownMax = ((float)o->lm.multiDefault * (float)o->pm.turret_Cooldown[min]) + (((float)o->lm.multiDefault * ((float)o->pm.turret_Cooldown[max] - (float)o->pm.turret_Cooldown[min])) * ((float)level/((float)o->lm.levelUnit)));
            spaceship->turret->speedRotation = ((float)o->lm.multiDefault * (float)o->pm.turret_SpeedRotation[min]) + (((float)o->lm.multiDefault * ((float)o->pm.turret_SpeedRotation[max] - (float)o->pm.turret_SpeedRotation[min])) * ((float)level/((float)o->lm.levelUnit)));
            spaceship->turret->cooldown = 0;
            spaceship->turret->life = spaceship->turret->lifeMax;
        }
        if(spaceship->shield)
        {
            spaceship->shield->lifeMax = ((float)o->lm.multiLife * (float)o->pm.shield_Life[min]) + (((float)o->lm.multiLife * ((float)o->pm.shield_Life[max] - (float)o->pm.shield_Life[min])) * ((float)level/((float)o->lm.levelUnit/2.0)));
            spaceship->shield->lifeTimeMax = ((float)o->lm.multiDefault * (float)o->pm.shield_LifeTime[min]) + (((float)o->lm.multiDefault * ((float)o->pm.shield_LifeTime[max] - (float)o->pm.shield_LifeTime[min])) * ((float)level/((float)o->lm.levelUnit)));
            spaceship->shield->cooldownMax = ((float)o->lm.multiDefault * (float)o->pm.shield_Cooldown[min]) + (((float)o->lm.multiDefault * ((float)o->pm.shield_Cooldown[max] - (float)o->pm.shield_Cooldown[min])) * ((float)level/((float)o->lm.levelUnit)));
            spaceship->shield->cooldown = 0;
            spaceship->shield->life = spaceship->shield->lifeMax;
        }
    }
}

void LevelManager_EnemyApplyType(Singleton * o, Enemy * enemy, EnemyType enemyType)
{
    enemy->enemyType = enemyType;
    
    Spaceship * spaceship = enemy->spaceship;
    
    float lifeMulti = 1;
    
    if(enemyType == EnemyTank)
    {
        lifeMulti = 10.0;
        
        spaceship->reactor->speed = (float)spaceship->reactor->speed / 3.0;
        spaceship->reactorSecondaryOne->speed = (float)spaceship->reactorSecondaryOne->speed / 3.0;
        spaceship->reactorSecondaryTwo->speed = spaceship->reactorSecondaryOne->speed;
        
    }
    if(enemyType == EnemyScout)
    {
        lifeMulti = 1.0/2.0;
        
        spaceship->reactor->speed = (float)spaceship->reactor->speed * 2.0;
        spaceship->reactorSecondaryOne->speed = (float)spaceship->reactorSecondaryOne->speed * 2.0;
        spaceship->reactorSecondaryTwo->speed = spaceship->reactorSecondaryOne->speed;
        
        Weapon_Free(spaceship->weaponSecondaryOne); spaceship->weaponSecondaryOne = NULL;
        Weapon_Free(spaceship->weaponSecondaryTwo); spaceship->weaponSecondaryTwo = NULL;
        
        Turret_Free(spaceship->turret); spaceship->turret = NULL;
    }
    if(enemyType == EnemySniper)
    {
        lifeMulti = 1.0/2.0;
        
        spaceship->weaponMain->damage = (float)spaceship->weaponMain->damage * 3.0;
        Weapon_Free(spaceship->weaponSecondaryOne); spaceship->weaponSecondaryOne = NULL;
        Weapon_Free(spaceship->weaponSecondaryTwo); spaceship->weaponSecondaryTwo = NULL;
        Weapon_Free(spaceship->weaponSecondaryOne); spaceship->weaponSecondaryOne = NULL;
        Weapon_Free(spaceship->weaponSecondaryTwo); spaceship->weaponSecondaryTwo = NULL;
        
        Turret_Free(spaceship->turret); spaceship->turret = NULL;
    }
    if(enemyType == EnemyArtificer)
    {
        lifeMulti = 3.0;
        
        Weapon_Free(spaceship->weaponMain); spaceship->weaponMain = NULL;
        spaceship->weaponSecondaryOne->damage = (float)spaceship->weaponSecondaryOne->damage * 3.0;
        spaceship->weaponSecondaryOne->cooldownMax = (float)spaceship->weaponSecondaryOne->cooldownMax / 5.0;
        spaceship->weaponSecondaryOne->cooldown = spaceship->weaponSecondaryOne->cooldownMax;
        spaceship->weaponSecondaryTwo->damage = spaceship->weaponSecondaryOne->damage;
        spaceship->weaponSecondaryTwo->cooldownMax = spaceship->weaponSecondaryOne->cooldownMax;
        spaceship->weaponSecondaryTwo->cooldown = spaceship->weaponSecondaryTwo->cooldownMax;
        enemy->chanceWeaponSecondary = (float)spaceship->weaponSecondaryTwo->cooldownMax / 3.0;
        Turret_Free(spaceship->turret); spaceship->turret = NULL;
    }
    if(enemyType == EnemyTurret)
    {
        lifeMulti = 1.5;
        
        Weapon_Free(spaceship->weaponMain); spaceship->weaponMain = NULL;
        Weapon_Free(spaceship->weaponSecondaryOne); spaceship->weaponSecondaryOne = NULL;
        Weapon_Free(spaceship->weaponSecondaryTwo); spaceship->weaponSecondaryTwo = NULL;
        
        spaceship->turret->damage = (float)spaceship->turret->damage * 3.0;
        enemy->chanceTurret = enemy->chanceTurret / 3.0;
    }
    if(enemyType == EnemySoldier)
    {
        lifeMulti = 1.0/6.0;
        
        spaceship->weaponMain->damage = (float)spaceship->weaponMain->damage / 2.0;
        spaceship->weaponSecondaryOne->damage = (float)spaceship->weaponSecondaryOne->damage / 2.0;
        spaceship->weaponSecondaryTwo->damage = spaceship->weaponSecondaryOne->damage;
        spaceship->turret->damage = (float)spaceship->turret->damage / 2.0;
    }
    
    Spaceship_SetLifeMax(spaceship, true);
    
    spaceship->totalLifeMax = (float)spaceship->totalLifeMax * lifeMulti;
    spaceship->totalLife = spaceship->totalLifeMax;
    
    spaceship->shield->lifeMax = (float)spaceship->shield->lifeMax * lifeMulti;
    spaceship->shield->life = spaceship->body->lifeMax;
}

