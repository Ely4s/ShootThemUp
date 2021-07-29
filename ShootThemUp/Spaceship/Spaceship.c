//
//  Spaceship.c
//  ShootThemUp
//
//  Created by El-idrissi Elyas on 07/12/2019.
//  Copyright © 2019 El-idrissi Elyas. All rights reserved.
//

#include "Spaceship.h"

Spaceship * Spaceship_New(SpaceshipType spaceshipType, float x, float y, BodyType bodyType, ReactorType reactorType, ReactorType reactorSecondaryType, WeaponType weaponMainType, WeaponType weaponSecondaryType, TurretType turretType, ShieldType shieldType, Singleton * o)
{
    Spaceship * spaceship = NULL;
    
    if(PatternManager_GetSpaceshipSlotsPattern(&o->pm, spaceshipType))
    {
        if(PatternManager_GetBodyPattern(&o->pm, bodyType))
        {
            spaceship = malloc(sizeof(Spaceship));
            
            spaceship->x = x;
            spaceship->y = y;
            
            spaceship->type = spaceshipType;
            
            spaceship->slotsPos = *PatternManager_GetSpaceshipSlotsPattern(&o->pm, spaceshipType);
            
            spaceship->body = PatternManager_GetBodyPattern(&o->pm, bodyType);
            
            spaceship->reactor = PatternManager_GetReactorPattern(&o->pm, reactorType);
            spaceship->reactorSecondaryOne = PatternManager_GetReactorPattern(&o->pm, reactorSecondaryType);
            spaceship->reactorSecondaryTwo = PatternManager_GetReactorPattern(&o->pm, reactorSecondaryType);
            
            spaceship->weaponMain = PatternManager_GetWeaponPattern(&o->pm, weaponMainType);
            spaceship->weaponSecondaryOne = PatternManager_GetWeaponSecondaryPattern(&o->pm, weaponSecondaryType);
            spaceship->weaponSecondaryTwo = PatternManager_GetWeaponSecondaryPattern(&o->pm, weaponSecondaryType);
            
            spaceship->turret = PatternManager_GetTurretPattern(&o->pm, turretType);
            
            spaceship->angle = -90;
            
            spaceship->w = spaceship->slotsPos.spaceshipPos.x*2;
            spaceship->h = spaceship->slotsPos.spaceshipPos.y*2;
            
            spaceship->shield = PatternManager_GetShieldPattern(&o->pm, shieldType);
            
            if(spaceship->shield)
            {
                spaceship->shield->w = spaceship->w * 1.5;
                spaceship->shield->h = spaceship->w * 1.5;
                
                spaceship->shield->sprite.w = spaceship->shield->w;
                spaceship->shield->sprite.h = spaceship->shield->h;
            }
            
            Spaceship_SetPos(spaceship, x, y);
            
            Spaceship_SetLifeMax(spaceship, true);
            Spaceship_SetLife(spaceship, Spaceship_GetLifeMax(spaceship));
            
            spaceship->blackSmock = Sprite_New(0, 0, 0, 0, "BlackSmock", &o->tm);
        }
    }
    
    return spaceship;
}

bool Spaceship_GotNoLife(Spaceship * spaceship)
{
    if(spaceship) return (spaceship->totalLife <= 0);
    else return true;
}

void Spaceship_SetBody(Spaceship * spaceship, BodyType bodyType, PatternManager * pm)
{
    if(pm && spaceship)
    {
        spaceship->slotsPos = *PatternManager_GetSpaceshipSlotsPattern(pm, (int)bodyType);
        spaceship->w = spaceship->slotsPos.spaceshipPos.x*2;
        spaceship->h = spaceship->slotsPos.spaceshipPos.y*2;
        
        if(spaceship->shield)
        {
            spaceship->shield->w = spaceship->w * 1.5;
            spaceship->shield->h = spaceship->w * 1.5;
            
            spaceship->shield->sprite.w = spaceship->shield->w;
            spaceship->shield->sprite.h = spaceship->shield->h;
        }
        
        if(spaceship->body) Body_Free(spaceship->body);
        
        spaceship->body = PatternManager_GetBodyPattern(pm, bodyType);
        Spaceship_SetPos(spaceship, spaceship->x, spaceship->y);
    }
}

void Spaceship_SetReactor(Spaceship * spaceship, ReactorType reactorType, PatternManager * pm)
{
    if(pm && spaceship)
    {
        if(spaceship->reactor) Reactor_Free(spaceship->reactor);
        spaceship->reactor = PatternManager_GetReactorPattern(pm, reactorType);
        Spaceship_SetPos(spaceship, spaceship->x, spaceship->y);
    }
}

void Spaceship_SetReactorSecondary(Spaceship * spaceship, ReactorType reactorType, PatternManager * pm)
{
    if(pm && spaceship)
    {
        if(spaceship->reactorSecondaryOne) Reactor_Free(spaceship->reactorSecondaryOne);
        if(spaceship->reactorSecondaryTwo) Reactor_Free(spaceship->reactorSecondaryTwo);
        spaceship->reactorSecondaryOne = PatternManager_GetReactorPattern(pm, reactorType);
        spaceship->reactorSecondaryTwo = PatternManager_GetReactorPattern(pm, reactorType);
        Spaceship_SetPos(spaceship, spaceship->x, spaceship->y);
    }
}

void Spaceship_SetMainWeapon(Spaceship * spaceship, WeaponType weaponType, PatternManager * pm)
{
    if(pm && spaceship)
    {
        if(spaceship->weaponMain) Weapon_Free(spaceship->weaponMain);
        spaceship->weaponMain = PatternManager_GetWeaponPattern(pm, weaponType);
        Spaceship_SetPos(spaceship, spaceship->x, spaceship->y);
    }
}

void Spaceship_SetWeaponSecondary(Spaceship * spaceship, WeaponType weaponType, PatternManager * pm)
{
    if(pm && spaceship)
    {
        if(spaceship->weaponSecondaryOne) Weapon_Free(spaceship->weaponSecondaryOne);
        if(spaceship->weaponSecondaryTwo) Weapon_Free(spaceship->weaponSecondaryTwo);
        spaceship->weaponSecondaryOne = PatternManager_GetWeaponSecondaryPattern(pm, weaponType);
        spaceship->weaponSecondaryTwo = PatternManager_GetWeaponSecondaryPattern(pm, weaponType);
        Spaceship_SetPos(spaceship, spaceship->x, spaceship->y);
    }
}

void Spaceship_SetTurret(Spaceship * spaceship, TurretType turretType, PatternManager * pm)
{
    if(pm && spaceship)
    {
        if(spaceship->turret) Turret_Free(spaceship->turret);
        spaceship->turret = PatternManager_GetTurretPattern(pm, turretType);
        Spaceship_SetPos(spaceship, spaceship->x, spaceship->y);
    }
}

void Spaceship_SetShield(Spaceship * spaceship, ShieldType shieldType, PatternManager * pm)
{
    if(pm && spaceship)
    {
        if(spaceship->shield) Shield_Free(spaceship->shield);
        
        spaceship->shield = PatternManager_GetShieldPattern(pm, shieldType);
        
        if(spaceship->shield)
        {
            spaceship->shield->w = spaceship->w * 1.5;
            spaceship->shield->h = spaceship->w * 1.5;
            
            spaceship->shield->sprite.w = spaceship->shield->w;
            spaceship->shield->sprite.h = spaceship->shield->h;
        }
        Spaceship_SetPos(spaceship, spaceship->x, spaceship->y);
    }
}

void Spaceship_SetPos(Spaceship * spaceship, float x, float y)
{
    if(spaceship)
    {
        spaceship->x = x;
        spaceship->y = y;
    
        float posX;
        float posY;
        
        if(spaceship->body)
        {
            posX = (spaceship->x + spaceship->w/2) - spaceship->body->slotPos.x + 0;
            posY = (spaceship->y + spaceship->h/2) - spaceship->body->slotPos.y + 0;
            Body_SetPos(spaceship->body, posX, posY);
        }
        
        if(spaceship->reactor)
        {
            posX = (spaceship->x + spaceship->w/2) - spaceship->reactor->slotPos.x + spaceship->slotsPos.reactorPos.x;
            posY = (spaceship->y + spaceship->h/2) - spaceship->reactor->slotPos.y + spaceship->slotsPos.reactorPos.y;
            
            Reactor_SetPos(spaceship->reactor, posX, posY);
            
            spaceship->reactor->spriteFlame.x = spaceship->reactor->x + spaceship->reactor->slotPos.x - spaceship->reactor->spriteFlame.w/2;
            spaceship->reactor->spriteFlame.y = spaceship->reactor->y + spaceship->reactor->slotPos.y;
            
            float plusX = 0;
            float plusY = 0;
            Utils_Math_SetPosAtDistanceRelativeToAngle(&plusX, &plusY, Utils_Math_DegreToRadian(spaceship->angle), -spaceship->reactor->h + 10);
            
            spaceship->reactor->spriteFlame.x += plusX;
            spaceship->reactor->spriteFlame.y += plusY;
        }
        if(spaceship->reactorSecondaryOne)
        {
            posX = (spaceship->x + spaceship->w/2) - spaceship->reactorSecondaryOne->slotPos.x + spaceship->slotsPos.reactorSecondaryOnePos.x;
            posY = (spaceship->y + spaceship->h/2) - spaceship->reactorSecondaryOne->slotPos.y + spaceship->slotsPos.reactorSecondaryOnePos.y;
            Reactor_SetPos(spaceship->reactorSecondaryOne, posX, posY);
            
            spaceship->reactorSecondaryOne->spriteFlame.x = spaceship->reactorSecondaryOne->x + spaceship->reactorSecondaryOne->slotPos.x - spaceship->reactorSecondaryOne->spriteFlame.w/2;
            spaceship->reactorSecondaryOne->spriteFlame.y = spaceship->reactorSecondaryOne->y + spaceship->reactorSecondaryOne->slotPos.y;
            
            float plusX = 0;
            float plusY = 0;
            Utils_Math_SetPosAtDistanceRelativeToAngle(&plusX, &plusY, Utils_Math_DegreToRadian(spaceship->angle), -spaceship->reactorSecondaryOne->h + 10);
            
            spaceship->reactorSecondaryOne->spriteFlame.x += plusX;
            spaceship->reactorSecondaryOne->spriteFlame.y += plusY;
            
        }
        if(spaceship->reactorSecondaryTwo)
        {
            posX = (spaceship->x + spaceship->w/2) - spaceship->reactorSecondaryTwo->slotPos.x + spaceship->slotsPos.reactorSecondaryTwoPos.x;
            posY = (spaceship->y + spaceship->h/2) - spaceship->reactorSecondaryTwo->slotPos.y + spaceship->slotsPos.reactorSecondaryTwoPos.y;
            Reactor_SetPos(spaceship->reactorSecondaryTwo, posX, posY);
            
            spaceship->reactorSecondaryTwo->spriteFlame.x = spaceship->reactorSecondaryTwo->x + spaceship->reactorSecondaryTwo->slotPos.x - spaceship->reactorSecondaryTwo->spriteFlame.w/2;
            spaceship->reactorSecondaryTwo->spriteFlame.y = spaceship->reactorSecondaryTwo->y + spaceship->reactorSecondaryTwo->slotPos.y;
            
            float plusX = 0;
            float plusY = 0;
            Utils_Math_SetPosAtDistanceRelativeToAngle(&plusX, &plusY, Utils_Math_DegreToRadian(spaceship->angle), -spaceship->reactorSecondaryTwo->h + 10);
            
            spaceship->reactorSecondaryTwo->spriteFlame.x += plusX;
            spaceship->reactorSecondaryTwo->spriteFlame.y += plusY;
            
        }
        
        if(spaceship->weaponMain)
        {
            posX = (spaceship->x + spaceship->slotsPos.spaceshipPos.x) - spaceship->weaponMain->slotPos.x + spaceship->slotsPos.weaponMainPos.x;
            posY = (spaceship->y + spaceship->slotsPos.spaceshipPos.y) - spaceship->weaponMain->slotPos.y + spaceship->slotsPos.weaponMainPos.y;
            Weapon_SetPos(spaceship->weaponMain, posX, posY);
        }
        if(spaceship->weaponSecondaryOne)
        {
            posX = (spaceship->x + spaceship->slotsPos.spaceshipPos.x) - spaceship->weaponSecondaryOne->slotPos.x + spaceship->slotsPos.weaponSecondaryOnePos.x;
            posY = (spaceship->y + spaceship->slotsPos.spaceshipPos.y) - spaceship->weaponSecondaryOne->slotPos.y + spaceship->slotsPos.weaponSecondaryOnePos.y;
            Weapon_SetPos(spaceship->weaponSecondaryOne, posX, posY);
        }
        if(spaceship->weaponSecondaryTwo)
        {
            posX = (spaceship->x + spaceship->slotsPos.spaceshipPos.x) - spaceship->weaponSecondaryTwo->slotPos.x + spaceship->slotsPos.weaponSecondaryTwoPos.x;
            posY = (spaceship->y + spaceship->slotsPos.spaceshipPos.y) - spaceship->weaponSecondaryTwo->slotPos.y + spaceship->slotsPos.weaponSecondaryTwoPos.y;
            Weapon_SetPos(spaceship->weaponSecondaryTwo, posX, posY);
        }
        
        if(spaceship->turret)
        {
            posX = (spaceship->x + spaceship->slotsPos.spaceshipPos.x) - spaceship->turret->slotPos.x + spaceship->slotsPos.turretPos.x;
            posY = (spaceship->y + spaceship->slotsPos.spaceshipPos.y) - spaceship->turret->slotPos.y + spaceship->slotsPos.turretPos.y;
            Turret_SetPos(spaceship->turret, posX, posY);
        }
        
        if(spaceship->shield)
        {
            posX = (spaceship->x + spaceship->slotsPos.spaceshipPos.x - spaceship->shield->w/2);
            posY = (spaceship->y + spaceship->slotsPos.spaceshipPos.y - spaceship->shield->h/2);
            Shield_SetPos(spaceship->shield, posX, posY);
        }
    }
}

void Spaceship_ResetRotate(Spaceship * spaceship, PatternManager * pm)
{
    if(spaceship)
    {
        if(spaceship->type)
        {
            spaceship->slotsPos = *PatternManager_GetSpaceshipSlotsPattern(pm, spaceship->type);
        }
    }
}

float Spaceship_GetTotalSpeed(Spaceship * spaceship)
{
    if(spaceship)
    {
        float totalSpeed = 0;
        
        if(spaceship->reactor) totalSpeed += spaceship->reactor->speed;
        if(spaceship->reactorSecondaryOne) totalSpeed += spaceship->reactorSecondaryOne->speed;
        if(spaceship->reactorSecondaryTwo) totalSpeed += spaceship->reactorSecondaryTwo->speed;
        
        return totalSpeed;
    }
    else
    {
        return 0;
    }
}

float Spaceship_GetTotalDamagePerSeconde(Spaceship * spaceship)
{
    if(spaceship)
    {
        float totalDamage = 0;
        
        if(spaceship->weaponMain) totalDamage += Weapon_GetDamagePerSecond(spaceship->weaponMain);
        if(spaceship->weaponSecondaryOne) totalDamage += Weapon_GetDamagePerSecond(spaceship->weaponSecondaryOne);
        if(spaceship->weaponSecondaryTwo) totalDamage += Weapon_GetDamagePerSecond(spaceship->weaponSecondaryTwo);
        if(spaceship->turret) totalDamage += Turret_GetDamagePerSecond(spaceship->turret);
        
        return totalDamage;
    }
    else
    {
        return 0;
    }
}

void Spaceship_SetLifeMax(Spaceship * spaceship, bool setFullLife)
{
    if(spaceship)
    {
        int totalLifeMax = 0;
        
        if(spaceship->body) totalLifeMax += spaceship->body->lifeMax;
        if(spaceship->reactor) totalLifeMax += spaceship->reactor->lifeMax;
        if(spaceship->reactorSecondaryOne) totalLifeMax += spaceship->reactorSecondaryOne->lifeMax;
        if(spaceship->reactorSecondaryTwo) totalLifeMax += spaceship->reactorSecondaryTwo->lifeMax;
        if(spaceship->weaponMain) totalLifeMax += spaceship->weaponMain->lifeMax;
        if(spaceship->weaponSecondaryOne) totalLifeMax += spaceship->weaponSecondaryTwo->lifeMax;
        if(spaceship->weaponSecondaryTwo) totalLifeMax += spaceship->weaponSecondaryTwo->lifeMax;
        if(spaceship->turret) totalLifeMax += spaceship->turret->lifeMax;
        
        spaceship->totalLifeMax = totalLifeMax;
        
        if(setFullLife) spaceship->totalLife = spaceship->totalLifeMax;
    }
}

float Spaceship_GetLifeMax(Spaceship * spaceship)
{
    if(spaceship)
    {
        return spaceship->totalLifeMax;
    }
    else return 0;
}

float Spaceship_GetLife(Spaceship * spaceship)
{
    if(spaceship)
    {
        return spaceship->totalLife;
    }
    else return 0;
}

void Spaceship_SetDamage(Spaceship * spaceship, float damage)
{
    if(spaceship)
    {
        spaceship->totalLife -= damage;
        if(spaceship->totalLife <= 0) spaceship->totalLife = 0;
    }
}

void Spaceship_SetLife(Spaceship * spaceship, float life)
{
    if(spaceship)
    {
        spaceship->totalLife = life;
    }
}

void Spaceship_Move(Spaceship * spaceship, float xPlus, float yPlus)
{
    if(spaceship)
    {
        Spaceship_SetPos(spaceship, spaceship->x + (xPlus * Spaceship_GetTotalSpeed(spaceship)), spaceship->y + (yPlus * Spaceship_GetTotalSpeed(spaceship)));
    }
}

void Spaceship_Rotate(Spaceship * spaceship, float anglePlus)
{
    if(spaceship)
    {
        float centrerX = 0;
        float centrerY = 0;
        
        float posX = 0;
        float posY = 0;
        
        // Reactor Main //
        
        posX = spaceship->slotsPos.reactorPos.x;
        posY = spaceship->slotsPos.reactorPos.y;
        Utils_Math_MoveRelativeToRotationAxis(&posX, &posY, &centrerX, &centrerY, Utils_Math_DegreToRadian(anglePlus));
        spaceship->slotsPos.reactorPos.x = posX;
        spaceship->slotsPos.reactorPos.y = posY;
        
        // Reactor Secondary //
        
        posX = spaceship->slotsPos.reactorSecondaryOnePos.x;
        posY = spaceship->slotsPos.reactorSecondaryOnePos.y;
        Utils_Math_MoveRelativeToRotationAxis(&posX, &posY, &centrerX, &centrerY, Utils_Math_DegreToRadian(anglePlus));
        spaceship->slotsPos.reactorSecondaryOnePos.x = posX;
        spaceship->slotsPos.reactorSecondaryOnePos.y = posY;
        
        posX = spaceship->slotsPos.reactorSecondaryTwoPos.x;
        posY = spaceship->slotsPos.reactorSecondaryTwoPos.y;
        Utils_Math_MoveRelativeToRotationAxis(&posX, &posY, &centrerX, &centrerY, Utils_Math_DegreToRadian(anglePlus));
        spaceship->slotsPos.reactorSecondaryTwoPos.x = posX;
        spaceship->slotsPos.reactorSecondaryTwoPos.y = posY;
        
        // Weapon Main //
        
        posX = spaceship->slotsPos.weaponMainPos.x;
        posY = spaceship->slotsPos.weaponMainPos.y;
        Utils_Math_MoveRelativeToRotationAxis(&posX, &posY, &centrerX, &centrerY, Utils_Math_DegreToRadian(anglePlus));
        spaceship->slotsPos.weaponMainPos.x = posX;
        spaceship->slotsPos.weaponMainPos.y = posY;
        
        // Weapon Secondary //
        
        posX = spaceship->slotsPos.weaponSecondaryOnePos.x;
        posY = spaceship->slotsPos.weaponSecondaryOnePos.y;
        Utils_Math_MoveRelativeToRotationAxis(&posX, &posY, &centrerX, &centrerY, Utils_Math_DegreToRadian(anglePlus));
        spaceship->slotsPos.weaponSecondaryOnePos.x = posX;
        spaceship->slotsPos.weaponSecondaryOnePos.y = posY;
        
        posX = spaceship->slotsPos.weaponSecondaryTwoPos.x;
        posY = spaceship->slotsPos.weaponSecondaryTwoPos.y;
        Utils_Math_MoveRelativeToRotationAxis(&posX, &posY, &centrerX, &centrerY, Utils_Math_DegreToRadian(anglePlus));
        spaceship->slotsPos.weaponSecondaryTwoPos.x = posX;
        spaceship->slotsPos.weaponSecondaryTwoPos.y = posY;
        
        // Turret //
        
        posX = spaceship->slotsPos.turretPos.x;
        posY = spaceship->slotsPos.turretPos.y;
        Utils_Math_MoveRelativeToRotationAxis(&posX, &posY, &centrerX, &centrerY, Utils_Math_DegreToRadian(anglePlus));
        spaceship->slotsPos.turretPos.x = posX;
        spaceship->slotsPos.turretPos.y = posY;
        
        Spaceship_SetPos(spaceship, spaceship->x, spaceship->y);
        
        spaceship->angle += anglePlus;
        if(spaceship->body) spaceship->body->angle += anglePlus;
        if(spaceship->reactor)spaceship->reactor->angle += anglePlus;
        if(spaceship->reactorSecondaryOne)spaceship->reactorSecondaryOne->angle += anglePlus;
        if(spaceship->reactorSecondaryTwo)spaceship->reactorSecondaryTwo->angle += anglePlus;
        if(spaceship->weaponMain)spaceship->weaponMain->angle += anglePlus;
        if(spaceship->weaponSecondaryOne) spaceship->weaponSecondaryOne->angle += anglePlus;
        if(spaceship->weaponSecondaryTwo) spaceship->weaponSecondaryTwo->angle += anglePlus;
        if(spaceship->turret) spaceship->turret->angle += anglePlus;
    }
}

void fill_circle(SDL_Renderer * gRenderer, int cx, int cy, int radius, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    for (double dy = 0; dy <= radius; dy += 1.0)
    {
        double dx = floor(sqrt((2.0 * radius * dy) - (dy * dy)));
        SDL_SetRenderDrawColor(gRenderer, r, g, b, a);
        SDL_RenderDrawLine(gRenderer, cx - dx, cy + dy - radius, cx + dx, cy + dy - radius);
        if(dy != radius)
        {
            SDL_RenderDrawLine(gRenderer, cx - dx, cy - dy + radius, cx + dx, cy - dy + radius);
        }
    }
}


void Spaceship_Update(Spaceship * spaceship, TeamType teamType, Singleton * o)
{
    if(spaceship)
    {
        Weapon_CooldownUpdate(spaceship->weaponMain);
        Weapon_CooldownUpdate(spaceship->weaponSecondaryOne);
        Weapon_CooldownUpdate(spaceship->weaponSecondaryTwo);
        Turret_CooldownUpdate(spaceship->turret);
        Turret_CibleUpdate(spaceship->turret, teamType, spaceship, o);
        Shield_LifeTimeUpdate(spaceship->shield);
        Shield_CooldownUpdate(spaceship->shield);
        
        if(spaceship->shield)
        {
            spaceship->shield->sprite.indexFrame += 0.3;
            
            if(spaceship->shield->sprite.indexFrame >= spaceship->shield->sprite.maxFrame)
            {
                spaceship->shield->sprite.indexFrame = 0;
            }
        }
        
        spaceship->reactor->spriteFlame.indexFrame += 0.3;
        if(spaceship->reactor->spriteFlame.indexFrame >= spaceship->reactor->spriteFlame.maxFrame)
        {
            spaceship->reactor->spriteFlame.indexFrame = 0;
        }
        
        spaceship->reactorSecondaryTwo->spriteFlame.indexFrame += 0.3;
        if(spaceship->reactorSecondaryTwo->spriteFlame.indexFrame >= spaceship->reactorSecondaryTwo->spriteFlame.maxFrame)
        {
            spaceship->reactorSecondaryTwo->spriteFlame.indexFrame = 0;
        }
        
        spaceship->reactorSecondaryOne->spriteFlame.indexFrame += 0.3;
        if(spaceship->reactorSecondaryOne->spriteFlame.indexFrame >= spaceship->reactorSecondaryOne->spriteFlame.maxFrame)
        {
            spaceship->reactorSecondaryOne->spriteFlame.indexFrame = 0;
        }
    }
}

bool Spaceship_IsOutOff(Spaceship * spaceship, int x, int y, int w, int h)
{
    if(spaceship) return !Utils_Collision_AABB(spaceship->x, spaceship->y, spaceship->w, spaceship->h, x, y, w, h);
    else return false;
}


void Spaceship_SetPosIfOutOf(Spaceship * spaceship, int x, int y, int w, int h)
{
    if(spaceship->x < x)                spaceship->x = x;
    if(spaceship->x + spaceship->w > w) spaceship->x = w - spaceship->w ;
    if(spaceship->y < y)                spaceship->y = y;
    if(spaceship->y + spaceship->h > h) spaceship->y = h - spaceship->h ;
}
void Spaceship_Draw(Spaceship * spaceship, Window * window, Singleton * o)
{
    if(spaceship)
    {
        if(spaceship->body)
        {
            Sprite_Draw(&spaceship->body->sprite, spaceship->angle, spaceship->body->slotPos.x, spaceship->body->slotPos.y, window);
        }
        
        if(spaceship->reactor)
        {
            Sprite_Draw(&spaceship->reactor->spriteFlame, spaceship->angle, spaceship->reactor->spriteFlame.w/2, 0, window);
            Sprite_Draw(&spaceship->reactor->sprite, spaceship->angle, spaceship->reactor->slotPos.x, spaceship->reactor->slotPos.y, window);
        }
        if(spaceship->reactorSecondaryOne)
        {
            Sprite_Draw(&spaceship->reactorSecondaryOne->spriteFlame, spaceship->angle, spaceship->reactorSecondaryOne->spriteFlame.w/2, 0, window);
            Sprite_Draw(&spaceship->reactorSecondaryOne->sprite, spaceship->angle, spaceship->reactorSecondaryOne->slotPos.x, spaceship->reactorSecondaryOne->slotPos.y, window);
        }
        if(spaceship->reactorSecondaryTwo)
        {
            Sprite_Draw(&spaceship->reactorSecondaryTwo->spriteFlame, spaceship->angle, spaceship->reactorSecondaryTwo->spriteFlame.w/2, 0, window);
            Sprite_Draw(&spaceship->reactorSecondaryTwo->sprite, spaceship->angle, spaceship->reactorSecondaryTwo->slotPos.x, spaceship->reactorSecondaryTwo->slotPos.y, window);
        }
        
        if(spaceship->weaponMain)
        {
            Sprite_Draw(&spaceship->weaponMain->sprite, spaceship->angle, spaceship->weaponMain->slotPos.x, spaceship->weaponMain->slotPos.y, window);
        }
        if(spaceship->weaponSecondaryOne)
        {
            Sprite_Draw(&spaceship->weaponSecondaryOne->sprite, spaceship->angle, spaceship->weaponSecondaryOne->slotPos.x, spaceship->weaponSecondaryOne->slotPos.y, window);
        }
        if(spaceship->weaponSecondaryTwo)
        {
            Sprite_Draw(&spaceship->weaponSecondaryTwo->sprite, spaceship->angle, spaceship->weaponSecondaryTwo->slotPos.x, spaceship->weaponSecondaryTwo->slotPos.y, window);
        }
        if(spaceship->turret)
        {
            Sprite_Draw(&spaceship->turret->sprite, spaceship->turret->angle, spaceship->turret->slotPos.x, spaceship->turret->slotPos.y, window);
        }
        if(spaceship->shield && Shield_isActivated(spaceship->shield))
        {
            Sprite_Draw(&spaceship->shield->sprite, spaceship->shield->angle, spaceship->shield->slotPos.x, spaceship->shield->slotPos.y, window);
        }
        
        if(DEBUG_SPACESHIP_BOX)
        {
            SDL_SetRenderDrawColor(window->renderer, 255, 0, 0, 255);
            
            SDL_RenderDrawPoint(window->renderer, spaceship->x+ spaceship->w/2, spaceship->y+ spaceship->h/2);
            
            SDL_RenderDrawPoint(window->renderer, spaceship->x + spaceship->w/2 + spaceship->slotsPos.reactorPos.x, spaceship->y + spaceship->h/2 + spaceship->slotsPos.reactorPos.y);
            SDL_RenderDrawPoint(window->renderer, spaceship->x + spaceship->w/2 + spaceship->slotsPos.reactorSecondaryOnePos.x, spaceship->y + spaceship->h/2 + spaceship->slotsPos.reactorSecondaryOnePos.y);
            SDL_RenderDrawPoint(window->renderer, spaceship->x + spaceship->w/2 + spaceship->slotsPos.reactorSecondaryTwoPos.x, spaceship->y + spaceship->h/2 + spaceship->slotsPos.reactorSecondaryTwoPos.y);
            
            SDL_RenderDrawPoint(window->renderer, spaceship->x + spaceship->w/2 + spaceship->slotsPos.weaponMainPos.x, spaceship->y + spaceship->h/2 + spaceship->slotsPos.weaponMainPos.y);
            SDL_RenderDrawPoint(window->renderer, spaceship->x + spaceship->w/2 + spaceship->slotsPos.weaponSecondaryOnePos.x, spaceship->y + spaceship->h/2 + spaceship->slotsPos.weaponSecondaryOnePos.y);
            SDL_RenderDrawPoint(window->renderer, spaceship->x + spaceship->w/2 + spaceship->slotsPos.weaponSecondaryTwoPos.x, spaceship->y + spaceship->h/2 + spaceship->slotsPos.weaponSecondaryTwoPos.y);
            
            SDL_RenderDrawPoint(window->renderer, spaceship->x + spaceship->w/2 + spaceship->slotsPos.turretPos.x, spaceship->y + spaceship->h/2 + spaceship->slotsPos.turretPos.y);
            
            Utils_Draw_Rect(spaceship->x, spaceship->y,spaceship->w, spaceship->h, window);
        }
        
        if(Spaceship_GetLife(spaceship)/Spaceship_GetLifeMax(spaceship) <= PRIVATE_Spaceship_ratioToSmock)
        {
            spaceship->blackSmock.x = spaceship->x + spaceship->w/2 - spaceship->blackSmock.w/2;
            spaceship->blackSmock.y = spaceship->y + spaceship->h/2 - spaceship->blackSmock.h;
            Sprite_Draw(&spaceship->blackSmock, -90, 0, 0, window);
        }
    }
}


void Spaceship_Free(Spaceship * spaceship)
{
    if(spaceship)
    {
        if(spaceship->body) {Body_Free(spaceship->body); spaceship->body = NULL;}
        if(spaceship->reactor) {Reactor_Free(spaceship->reactor); spaceship->reactor = NULL;}
        if(spaceship->reactorSecondaryOne) {Reactor_Free(spaceship->reactorSecondaryOne); spaceship->reactorSecondaryOne = NULL;}
        if(spaceship->reactorSecondaryTwo) {Reactor_Free(spaceship->reactorSecondaryTwo); spaceship->reactorSecondaryTwo = NULL;}
        if(spaceship->weaponMain) {Weapon_Free(spaceship->weaponMain); spaceship->weaponMain = NULL;}
        if(spaceship->weaponSecondaryOne) {Weapon_Free(spaceship->weaponSecondaryOne); spaceship->weaponSecondaryOne = NULL;}
        if(spaceship->weaponSecondaryTwo) {Weapon_Free(spaceship->weaponSecondaryTwo); spaceship->weaponSecondaryTwo = NULL;}
        if(spaceship->turret) {Turret_Free(spaceship->turret); spaceship->turret = NULL;}
        if(spaceship->shield) {Shield_Free(spaceship->shield); spaceship->shield = NULL;}
        
        free(spaceship);
        spaceship = NULL;
    }
}
