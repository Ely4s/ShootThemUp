//
//  PatternManager.c
//  ShootThemUp
//
//  Created by El-idrissi Elyas on 06/12/2019.
//  Copyright © 2019 El-idrissi Elyas. All rights reserved.
//

#include "PatternManager.h"

void PatternManager_SetEquipementValue(PatternManager * pm, float * equipement, float value1, float value2, float value3, float value4, float value5)
{
    equipement[0] = value1;
    equipement[1] = value2;
    equipement[2] = value3;
    equipement[3] = value4;
    equipement[4] = value5;
}

void PatternManager_LoadTextures(PatternManager * pm, TextureManager * tm)
{
    map_init(&pm->allBodyPatterns);
    
     map_init(&pm->allReactorPatterns);
    
    map_init(&pm->allWeaponPatterns);
    map_init(&pm->allWeaponSecondaryPatterns);
    
    map_init(&pm->allTurretPatterns);
    
    map_init(&pm->allShieldPatterns);
   
    map_init(&pm->allspaceshipSlotPatterns);
    map_init(&pm->allBulletPatterns);
    
    PatternManager_AddBulletPattern(pm, BulletMainWeapon, NoBulletEffect, Utils_PointF_New(11, 0), 5, 13, "BulletMainWeapon",tm);
    PatternManager_AddBulletPattern(pm, BulletSecondaryWeapon, ExplosiveEffect, Utils_PointF_New(11, 0), 14, 52, "BulletSecondaryWeapon",tm);
    PatternManager_AddBulletPattern(pm, BulletTurret, NoBulletEffect, Utils_PointF_New(13, 0), 4, 9, "BulletTurret",tm);
    
    PatternManager_AddBulletPattern(pm, BulletMainWeaponSpe, NoBulletEffect, Utils_PointF_New(11, 0), 5, 13, "BulletMainWeapon",tm);
    PatternManager_AddBulletPattern(pm, BulletSecondaryWeaponSpe, ExplosiveEffect, Utils_PointF_New(11, 0), 14, 52, "BulletSecondaryWeapon",tm);
    PatternManager_AddBulletPattern(pm, BulletTurretSpe, NoBulletEffect, Utils_PointF_New(13, 0), 4, 9, "BulletTurret",tm);
    
    PatternManager_SetEquipementValue(pm, pm->body_Life, 1500, 3000, 6000, 12000, 24000);
    
    PatternManager_SetEquipementValue(pm, pm->reactor_Life, 71, 143, 286, 571, 1143);
    PatternManager_SetEquipementValue(pm, pm->reactor_Speed, 1.5, 1.75, 2.0, 2.25, 2.5);
    
    PatternManager_SetEquipementValue(pm, pm->weaponM_Life, 71, 143, 286, 571, 1143);
    PatternManager_SetEquipementValue(pm, pm->weaponM_Damage, 15, 30, 60, 120, 240);
    PatternManager_SetEquipementValue(pm, pm->weaponM_SpeedBullet, 10, 10, 10, 10, 10);
    PatternManager_SetEquipementValue(pm, pm->weaponM_Cooldown, 20, 19, 18, 17, 16);
    
    PatternManager_SetEquipementValue(pm, pm->weaponS_Life, 71, 143, 286, 571, 1143);
    PatternManager_SetEquipementValue(pm, pm->weaponS_Damage, 50, 100, 200, 400, 800);
    PatternManager_SetEquipementValue(pm, pm->weaponS_SpeedBullet, 10, 10, 10, 10, 10);
    PatternManager_SetEquipementValue(pm, pm->weaponS_Cooldown, 800, 750, 700, 650, 600);
    
    PatternManager_SetEquipementValue(pm, pm->turret_Life, 171, 143, 286, 571, 1143);
    PatternManager_SetEquipementValue(pm, pm->turret_Damage, 1, 2, 3, 8, 16);
    PatternManager_SetEquipementValue(pm, pm->turret_SpeedBullet, 10, 10, 10, 10, 10);
    PatternManager_SetEquipementValue(pm, pm->turret_Cooldown, 10, 9, 8, 7, 6);
    PatternManager_SetEquipementValue(pm, pm->turret_SpeedRotation, 3, 5, 6, 8, 10);

    PatternManager_SetEquipementValue(pm, pm->shield_Life,400, 800, 1600, 3200, 6400);
    PatternManager_SetEquipementValue(pm, pm->shield_LifeTime, 600, 650, 700, 750, 800);
    PatternManager_SetEquipementValue(pm, pm->shield_Cooldown, 1000, 950, 900, 850, 800);
    
//    float bodyLife[5] =             {1500, 3000, 6000, 12000, 24000}; //OK//
//
//    float reactor_Life[5] =         {71, 143, 286, 571, 1143}; //OK//
//    float reactor_Speed[5] =        {1.5, 1.75, 2.0, 2.25, 2.5}; //OK//
//
//    float weaponM_Life[5] =         {71, 143, 286, 571, 1143}; //OK//
//    float weaponM_Damage[5] =       {15, 30, 60, 120, 240}; //OK//
//    float weaponM_SpeedBullet[5] =  {10, 10, 10, 10, 10}; //OK//
//    float weaponM_Cooldown[5] =     {20, 19, 18, 17, 16}; //OK//
//
//    float weaponS_Life[5] =         {71, 143, 286, 571, 1143}; //OK//
//    float weaponS_Damage[5] =       {50, 100, 200, 400, 800}; //OK//
//    float weaponS_SpeedBullet[5] =  {10, 10, 10, 10, 10}; //OK//
//    float weaponS_Cooldown[5] =     {800, 750, 700, 650, 600}; //OK//
//
//    float turret_Life[5] =          {71, 143, 286, 571, 1143}; //OK//
//    float turret_Damage[5] =        {1, 2, 3, 8, 16}; //OK//
//    float turret_SpeedBullet[5] =   {10, 10, 10, 10, 10}; //OK//
//    float turret_Cooldown[5] =      {10, 9, 8, 7, 6}; //OK//
//    float turret_SpeedRotation[5] = {3, 5, 6, 8, 10}; //OK//
//
//    float shield_Life[5] =          {400, 800, 1600, 3200, 6400};
//    float shield_LifeTime[5] =      {600, 650, 700, 750, 800};
//    float shield_Cooldow[5] =       {1000, 950, 900, 850, 800};
    
    //---------------------[Tier1]--------------------//
    PatternManager_AddSpaceshipSlotsPattern(pm, SpaceshipTier1, Utils_PointF_New(110,48), Utils_PointF_New(0,20), Utils_PointF_New(32, 18), Utils_PointF_New(0, -28), Utils_PointF_New(20, 10), Utils_PointF_New(0, 8));
    PatternManager_AddBodyPattern(pm, BodyTier1, Utils_PointF_New(55, 28), 110, 48, pm->body_Life[0], "spaceship_tier_1_idle", tm);
    PatternManager_AddReactorPattern(pm, ReactorTier1, Utils_PointF_New(7, 0), 14, 10, pm->reactor_Life[0], pm->reactor_Speed[0], "reactor_tier_1_idle", tm);
    PatternManager_AddWeaponPattern(pm, WeaponTier1, Utils_PointF_New(5, 16), 10, 16, pm->weaponM_Life[0], pm->weaponM_Damage[0], pm->weaponM_SpeedBullet[0], pm->weaponM_Cooldown[0], "weaponMain_tier_1_idle", tm);
    PatternManager_AddWeaponSecondaryPattern(pm, WeaponTier1, Utils_PointF_New(4, 40), 8, 40,  pm->weaponS_Life[0], pm->weaponS_Damage[0], pm->weaponS_SpeedBullet[0], pm->weaponS_Cooldown[0], "weaponSecondary_tier_1_idle", tm);
    PatternManager_AddTurretPattern(pm, TurretTier1, Utils_PointF_New(9, 15), 18, 22, pm->turret_Life[0], pm->turret_Damage[0], pm->turret_SpeedBullet[0], pm->turret_Cooldown[0], pm->turret_SpeedRotation[0], "turret_tier_1_idle", tm);
    PatternManager_AddShieldPattern(pm, ShieldTier1, Utils_PointF_New(53/2, 48/2), 53, 48, pm->shield_Life[0], pm->shield_LifeTime[0], pm->shield_Cooldown[0], "shield_tier_1_idle", tm);
    
    //---------------------[Tier2]--------------------//
    PatternManager_AddSpaceshipSlotsPattern(pm, SpaceshipTier2, Utils_PointF_New(90,94), Utils_PointF_New(0,39), Utils_PointF_New(30, 35), Utils_PointF_New(0, -46), Utils_PointF_New(25, 16), Utils_PointF_New(0, 8));
    PatternManager_AddBodyPattern(pm, BodyTier2, Utils_PointF_New(45, 53), 90, 94, pm->body_Life[1], "spaceship_tier_2_idle", tm);
    PatternManager_AddReactorPattern(pm, ReactorTier2, Utils_PointF_New(9, 0), 18, 22, pm->reactor_Life[1], pm->reactor_Speed[1], "reactor_tier_2_idle", tm);
    PatternManager_AddWeaponPattern(pm, WeaponTier2, Utils_PointF_New(7, 17), 14, 24, pm->weaponM_Life[1],pm-> weaponM_Damage[1], pm->weaponM_SpeedBullet[1], pm->weaponM_Cooldown[1], "weaponMain_tier_2_idle", tm);
    PatternManager_AddWeaponSecondaryPattern(pm, WeaponTier2, Utils_PointF_New(4, 54), 8, 54, pm->weaponS_Life[1], pm->weaponS_Damage[1], pm->weaponS_SpeedBullet[1], pm->weaponS_Cooldown[1], "weaponSecondary_tier_2_idle", tm);
    PatternManager_AddTurretPattern(pm, TurretTier2, Utils_PointF_New(13, 23), 26, 30, pm->turret_Life[1], pm->turret_Damage[1], pm->turret_SpeedBullet[1], pm->turret_Cooldown[1], pm->turret_SpeedRotation[1], "turret_tier_2_idle", tm);
    PatternManager_AddShieldPattern(pm, ShieldTier2, Utils_PointF_New(53/2, 48/2), 53, 48, pm->shield_Life[1], pm->shield_LifeTime[1], pm->shield_Cooldown[1], "shield_tier_2_idle", tm);
    
    //---------------------[Tier3]--------------------//
    PatternManager_AddSpaceshipSlotsPattern(pm, SpaceshipTier3, Utils_PointF_New(158,128), Utils_PointF_New(0,55), Utils_PointF_New(66, 31), Utils_PointF_New(0, -61), Utils_PointF_New(31, -19), Utils_PointF_New(0, 18));
    PatternManager_AddBodyPattern(pm, BodyTier3, Utils_PointF_New(79, 67), 110, 48, pm->body_Life[2], "spaceship_tier_3_idle", tm);
    PatternManager_AddReactorPattern(pm, ReactorTier3, Utils_PointF_New(11, 0), 22, 30, pm->reactor_Life[2], pm->reactor_Speed[2], "reactor_tier_3_idle", tm);
    PatternManager_AddWeaponPattern(pm, WeaponTier3, Utils_PointF_New(7, 23), 14, 30, pm->weaponM_Life[2], pm->weaponM_Damage[2], pm->weaponM_SpeedBullet[2], pm->weaponM_Cooldown[2], "weaponMain_tier_3_idle", tm);
    PatternManager_AddWeaponSecondaryPattern(pm, WeaponTier3, Utils_PointF_New(6, 54), 12, 54, pm->weaponS_Life[2], pm->weaponS_Damage[2], pm->weaponS_SpeedBullet[2], pm->weaponS_Cooldown[2], "weaponSecondary_tier_3_idle", tm);
    PatternManager_AddTurretPattern(pm, TurretTier3, Utils_PointF_New(15, 29), 30, 42, pm->turret_Life[2], pm->turret_Damage[2], pm->turret_SpeedBullet[2], pm->turret_Cooldown[2], pm->turret_SpeedRotation[2], "turret_tier_3_idle", tm);
    PatternManager_AddShieldPattern(pm, ShieldTier3, Utils_PointF_New(53/2, 48/2), 53, 48, pm->shield_Life[2], pm->shield_LifeTime[2], pm->shield_Cooldown[2], "shield_tier_3_idle", tm);
    
    //---------------------[Tier4]--------------------//
    PatternManager_AddSpaceshipSlotsPattern(pm, SpaceshipTier4, Utils_PointF_New(150,166), Utils_PointF_New(0,58), Utils_PointF_New(58, 53), Utils_PointF_New(0, -30), Utils_PointF_New(50, -20), Utils_PointF_New(0, 26));
    PatternManager_AddBodyPattern(pm, BodyTier4, Utils_PointF_New(75, 102), 150, 166, pm->body_Life[3], "spaceship_tier_4_idle", tm);
    PatternManager_AddReactorPattern(pm, ReactorTier4, Utils_PointF_New(11, 0), 22, 42, pm->reactor_Life[3], pm->reactor_Speed[3], "reactor_tier_4_idle", tm);
    PatternManager_AddWeaponPattern(pm, WeaponTier4, Utils_PointF_New(13, 31), 26, 38, pm->weaponM_Life[3], pm->weaponM_Damage[3], pm->weaponM_SpeedBullet[3], pm->weaponM_Cooldown[3], "weaponMain_tier_4_idle", tm);
    PatternManager_AddWeaponSecondaryPattern(pm, WeaponTier4, Utils_PointF_New(6, 60), 12, 60, pm->weaponS_Life[3], pm->weaponS_Damage[3], pm->weaponS_SpeedBullet[3], pm->weaponS_Cooldown[3], "weaponSecondary_tier_4_idle", tm);
    PatternManager_AddTurretPattern(pm, TurretTier4, Utils_PointF_New(15, 43), 30, 56, pm->turret_Life[3], pm->turret_Damage[3], pm->turret_SpeedBullet[3], pm->turret_Cooldown[3], pm->turret_SpeedRotation[3], "turret_tier_4_idle", tm);
    PatternManager_AddShieldPattern(pm, ShieldTier4, Utils_PointF_New(53/2, 48/2), 53, 48, pm->shield_Life[3], pm->shield_LifeTime[3], pm->shield_Cooldown[3], "shield_tier_4_idle", tm);
    
    
    //---------------------[Tier5]--------------------//
    PatternManager_AddSpaceshipSlotsPattern(pm, SpaceshipTier5, Utils_PointF_New(230, 200), Utils_PointF_New(0,80), Utils_PointF_New(50, 48), Utils_PointF_New(0, -106), Utils_PointF_New(72, -24), Utils_PointF_New(0, 46));
    PatternManager_AddBodyPattern(pm, BodyTier5, Utils_PointF_New(115, 112), 230, 200, pm->body_Life[4], "spaceship_tier_5_idle", tm);
    PatternManager_AddReactorPattern(pm, ReactorTier5, Utils_PointF_New(25, 0), 50, 60, pm->reactor_Life[4], pm->reactor_Speed[4], "reactor_tier_5_idle", tm);
    PatternManager_AddWeaponPattern(pm, WeaponTier5, Utils_PointF_New(19, 50), 38, 54, pm->weaponM_Life[4], pm->weaponM_Damage[4], pm->weaponM_SpeedBullet[4],pm-> weaponM_Cooldown[4], "weaponMain_tier_5_idle", tm);
    PatternManager_AddWeaponSecondaryPattern(pm, WeaponTier5, Utils_PointF_New(6, 72), 12, 72, pm->weaponS_Life[4],pm-> weaponS_Damage[4], pm->weaponS_SpeedBullet[4], pm->weaponS_Cooldown[4], "weaponSecondary_tier_5_idle", tm);
    PatternManager_AddTurretPattern(pm, TurretTier5, Utils_PointF_New(15, 61), 30, 74, pm->turret_Life[4], pm->turret_Damage[4], pm->turret_SpeedBullet[4], pm->turret_Cooldown[4], pm->turret_SpeedRotation[4], "turret_tier_5_idle", tm);
    PatternManager_AddShieldPattern(pm, ShieldTier5, Utils_PointF_New(53/2, 48/2), 53, 48, pm->shield_Life[4], pm->shield_LifeTime[4], pm->shield_Cooldown[4], "shield_tier_5_idle", tm);
}

void PatternManager_AddBodyPattern(PatternManager * pm, BodyType bodyType, PointF slotPos, int w, int h, float lifeMax, char textureId[], TextureManager * tm)
{
    if(pm && tm && textureId)
    {
        char strBodyType[1024];
        sprintf(strBodyType, "%d", bodyType);
        
        Body body;
        
        body.type = bodyType;
        
        body.x = 0;
        body.y = 0;
        
        body.w = w;
        body.h = h;
        
        body.slotPos = slotPos;
        
        body.angle = -90;
        
        body.lifeMax = lifeMax;
        body.life = lifeMax;
        
        body.sprite = Sprite_New(body.x, body.y, body.w, body.h, textureId, tm);
        
        map_set(&pm->allBodyPatterns, strBodyType, body);
    }
}
Body * PatternManager_GetBodyPattern(PatternManager * pm, BodyType bodyType)
{
    Body * b = NULL;
    
    if(pm)
    {
        char strBodyType[1024];
        sprintf(strBodyType, "%d", bodyType);
        
        if(map_get(&pm->allBodyPatterns, strBodyType))
        {
            b = malloc(sizeof(Body));
            *b = *map_get(&pm->allBodyPatterns, strBodyType);
        }
    }
    
    return b;
}

void PatternManager_AddReactorPattern(PatternManager * pm, ReactorType reactorType, PointF slotPos, int w, int h, float lifeMax, float speed, char textureId[], TextureManager * tm)
{
    if(pm && tm && textureId)
    {
        char strReactorType[1024];
        sprintf(strReactorType, "%d", reactorType);
        
        Reactor reactor;
        
        reactor.type = reactorType;
        
        reactor.w = w;
        reactor.h = h;
        
        reactor.slotPos = slotPos;
        
        reactor.angle = -90;
        
        reactor.speed = speed;
        reactor.lifeMax = lifeMax;
        reactor.life = lifeMax;
        
        reactor.sprite = Sprite_New(reactor.x, reactor.y, reactor.w, reactor.h, textureId, tm);
        reactor.spriteFlame = Sprite_New(reactor.x, reactor.y, 0, 0, "Flame", tm);
        
        map_set(&pm->allReactorPatterns, strReactorType, reactor);
    }
}
Reactor * PatternManager_GetReactorPattern(PatternManager * pm, ReactorType reactorType)
{
    Reactor * r = NULL;
    
    if(pm)
    {
        char strReactorType[1024];
        sprintf(strReactorType, "%d", reactorType);
        
        if(map_get(&pm->allReactorPatterns, strReactorType))
        {
            r = malloc(sizeof(Reactor));
            *r = *map_get(&pm->allReactorPatterns, strReactorType);
        }
    }
    return r;
}

void PatternManager_AddWeaponPattern(PatternManager * pm, WeaponType weaponType, PointF slotPos, int w, int h, float lifeMax, float damage, float speedBullet, float cooldown, char textureId[], TextureManager * tm)
{
    if(pm && tm && textureId)
    {
        
        char strWeaponType[1024];
        sprintf(strWeaponType, "%d", weaponType);
        
        Weapon weapon;
    
        weapon.type = weaponType;
        
        weapon.w = w;
        weapon.h = h;
    
        weapon.slotPos = slotPos;
        
        weapon.sprite = Sprite_New(weapon.x, weapon.y, weapon.w, weapon.h, textureId, tm);
        
        weapon.angle = -90;
        
        weapon.lifeMax = lifeMax;
        weapon.life = lifeMax;
        weapon.damage = damage;
        weapon.cooldownMax = cooldown;
        weapon.cooldown = cooldown;
        weapon.speedBullet = speedBullet;
    
        map_set(&pm->allWeaponPatterns, strWeaponType, weapon);
    }
}
Weapon * PatternManager_GetWeaponPattern(PatternManager * pm, WeaponType weaponType)
{
    Weapon * w = NULL;
    
    if(pm)
    {
        char strWeaponType[1024];
        sprintf(strWeaponType, "%d", weaponType);
        
        if(map_get(&pm->allWeaponPatterns, strWeaponType))
        {
            w = malloc(sizeof(Weapon));
            *w = *map_get(&pm->allWeaponPatterns, strWeaponType);
        }
    }
    
    return w;
}

void PatternManager_AddWeaponSecondaryPattern(PatternManager * pm, WeaponType weaponType, PointF slotPos, int w, int h, float lifeMax, float damage, float speedBullet, float cooldown, char textureId[], TextureManager * tm)
{
    if(pm && tm && textureId)
    {
        char strWeaponType[1024];
        sprintf(strWeaponType, "%d", weaponType);
        
        Weapon weapon;
        
        weapon.type = weaponType;
        
        weapon.w = w;
        weapon.h = h;
        
        weapon.slotPos = slotPos;
        
        weapon.sprite = Sprite_New(weapon.x, weapon.y, weapon.w, weapon.h, textureId, tm);
        
        weapon.angle = -90;
        
        weapon.lifeMax = lifeMax;
        weapon.life = lifeMax;
        weapon.damage = damage;
        weapon.cooldownMax = cooldown;
        weapon.cooldown = cooldown;
        weapon.speedBullet = speedBullet;
        
        map_set(&pm->allWeaponSecondaryPatterns, strWeaponType, weapon);
    }
}
Weapon * PatternManager_GetWeaponSecondaryPattern(PatternManager * pm, WeaponType weaponType)
{
    Weapon * w = NULL;
    
    if(pm)
    {
        char strWeaponType[1024];
        sprintf(strWeaponType, "%d", weaponType);
        
        if(map_get(&pm->allWeaponSecondaryPatterns, strWeaponType))
        {
            w = malloc(sizeof(Weapon));
            *w = *map_get(&pm->allWeaponSecondaryPatterns, strWeaponType);
        }
    }
    
    return w;
}

void PatternManager_AddTurretPattern(PatternManager * pm, TurretType turretType, PointF slotPos, int w, int h, float lifeMax, float damage, float speedBullet, float cooldown, float speedRotation, char textureId[], TextureManager * tm)
{
    if(pm && tm && textureId)
    {
        
        char strTurretType[1024];
        sprintf(strTurretType, "%d", turretType);
        
        Turret turret;
        
        turret.type = turretType;
        
        turret.w = w;
        turret.h = h;
        
        turret.slotPos = slotPos;
        
        turret.sprite = Sprite_New(turret.x, turret.y, turret.w, turret.h, textureId, tm);
        
        turret.angle = -90;
        
        turret.cible = NULL;
        turret.isManual = false;
        turret.lifeMax = lifeMax;
        turret.life = lifeMax;
        turret.damage = damage;
        turret.cooldownMax = cooldown;
        turret.cooldown = cooldown;
        turret.speedRotation = speedRotation;
        turret.speedBullet = speedBullet;
        
        map_set(&pm->allTurretPatterns, strTurretType, turret);
    }
}
Turret * PatternManager_GetTurretPattern(PatternManager * pm, TurretType turretType)
{
    Turret * w = NULL;
    
    if(pm)
    {
        char strTurretType[1024];
        sprintf(strTurretType, "%d", turretType);
        
        if(map_get(&pm->allTurretPatterns, strTurretType))
        {
            w = malloc(sizeof(Turret));
            *w = *map_get(&pm->allTurretPatterns, strTurretType);
        }
    }
    
    return w;
}

void PatternManager_AddShieldPattern(PatternManager * pm, ShieldType shieldType, PointF slotPos, int w, int h, float lifeMax, float lifeTimeMax, float cooldown, char textureId[], TextureManager * tm)
{
    if(pm && tm && textureId)
    {
        char strShieldType[1024];
        sprintf(strShieldType, "%d", shieldType);
        
        Shield shield;
        
        shield.type = shieldType;
        
        shield.w = w;
        shield.h = h;
        
        shield.slotPos = slotPos;
        
        shield.angle = -90;
        
        shield.isActivated = false;
        
        shield.lifeMax = lifeMax;
        shield.life = lifeMax;
        shield.lifeTimeMax = lifeTimeMax;
        shield.lifeTime = lifeTimeMax;
        shield.cooldownMax = cooldown;
        shield.cooldown = cooldown;
        
        shield.sprite = Sprite_New(shield.x, shield.y, shield.w, shield.h, textureId, tm);
        
        map_set(&pm->allShieldPatterns, strShieldType, shield);
    }
}
Shield * PatternManager_GetShieldPattern(PatternManager * pm, ShieldType shieldType)
{
    Shield * s = NULL;
    
    if(pm)
    {
        char strShieldType[1024];
        sprintf(strShieldType, "%d", shieldType);
    
        if(map_get(&pm->allShieldPatterns, strShieldType))
        {
            s = malloc(sizeof(Shield));
            *s = *map_get(&pm->allShieldPatterns, strShieldType);
        }
    }
    return s;
}

void PatternManager_AddBulletPattern(PatternManager * pm, BulletType bulletType, BulletEffectType bulletEffectType, PointF slotPos, int w, int h, char textureId[], TextureManager * tm)
{
    if(pm && tm && textureId)
    {
        char strBulletType[1024];
        sprintf(strBulletType, "%d", bulletType);
        
        Bullet bullet;
        
        bullet.type = bulletType;
        
        bullet.w = w;
        bullet.h = h;
        
        bullet.angle = -90;
        
        bullet.effectType = bulletEffectType;
        
        bullet.speed = 0;
        bullet.damage = 0;
        
        bullet.sprite = Sprite_New(bullet.x, bullet.y, bullet.w, bullet.h, textureId, tm);
        if(bulletEffectType == ExplosiveEffect) bullet.spriteFlame = Sprite_New(bullet.x, bullet.y, 0, 0, "Flame", tm);
        
        map_set(&pm->allBulletPatterns, strBulletType, bullet);
    }
}
Bullet * PatternManager_GetBulletPattern(PatternManager * pm, BulletType bulletType)
{
    Bullet * a = NULL;
    
    if(pm)
    {
        char strBulletType[1024];
        sprintf(strBulletType, "%d", bulletType);
    
        if(map_get(&pm->allBulletPatterns, strBulletType))
        {
            a = malloc(sizeof(Bullet));
            *a = *map_get(&pm->allBulletPatterns, strBulletType);
        }
    }
    
    return a;
}

void PatternManager_AddSpaceshipSlotsPattern(PatternManager * pm, SpaceshipType spaceshipType, PointF spaceshipPos, PointF reactorPos, PointF reactorSecondaryPos, PointF weaponMainPos, PointF weaponSecondaryPos, PointF turretPos)
{
    if(pm)
    {
        char strSpaceshipType[1024];
        sprintf(strSpaceshipType, "%d", spaceshipType);
    
        if(!map_get(&pm->allspaceshipSlotPatterns, strSpaceshipType))
        {
            SpaceshipSlot spaceshipSlot = {0};
        
            spaceshipSlot.spaceshipPos.x = spaceshipPos.x/2;
            spaceshipSlot.spaceshipPos.y = spaceshipPos.y/2;
            
            spaceshipSlot.reactorPos = reactorPos;
            spaceshipSlot.reactorSecondaryOnePos = reactorSecondaryPos;
            spaceshipSlot.reactorSecondaryTwoPos.x = - reactorSecondaryPos.x;
            spaceshipSlot.reactorSecondaryTwoPos.y = reactorSecondaryPos.y;
            
            spaceshipSlot.weaponMainPos = weaponMainPos;
            spaceshipSlot.weaponSecondaryOnePos = weaponSecondaryPos;
            spaceshipSlot.weaponSecondaryTwoPos.x = - weaponSecondaryPos.x;
            spaceshipSlot.weaponSecondaryTwoPos.y = weaponSecondaryPos.y;
            
            spaceshipSlot.turretPos = turretPos;
            
            map_set(&pm->allspaceshipSlotPatterns, strSpaceshipType, spaceshipSlot);
        }
    }
}

SpaceshipSlot * PatternManager_GetSpaceshipSlotsPattern(PatternManager * pm, SpaceshipType spaceshipType)
{
    char strSpaceshipType[1024];
    sprintf(strSpaceshipType, "%d", spaceshipType);
    
    SpaceshipSlot * spaceshipSlot = NULL;
    
    if(map_get_((map_base_t*)&pm->allspaceshipSlotPatterns, strSpaceshipType))
    {
        spaceshipSlot = map_get(&pm->allspaceshipSlotPatterns, strSpaceshipType);
    }
    return spaceshipSlot;
}

void PatterManager_GetTextureIdFromElementAndTier(int element, int tier, char str[])
{
    char elementStr[1024];
    if(element == 0) sprintf(elementStr, "spaceship");
    if(element == 1) sprintf(elementStr, "reactor");
    if(element == 2) sprintf(elementStr, "reactor");
    if(element == 3) sprintf(elementStr, "weaponMain");
    if(element == 4) sprintf(elementStr, "weaponSecondary");
    if(element == 5) sprintf(elementStr, "turret");
    if(element == 6) sprintf(elementStr, "shield");
    
    sprintf(str, "%s_tier_%d_idle", elementStr, tier);
}
