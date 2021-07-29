//
//  Spaceship.h
//  ShootThemUp
//
//  Created by El-idrissi Elyas on 07/12/2019.
//  Copyright © 2019 El-idrissi Elyas. All rights reserved.
//

#ifndef Spaceship_h
#define Spaceship_h

#include "main.h"
#include "PatternManager.h"
#include "Utils.h"
#include "Body.h"
#include "Reactor.h"
#include "Weapon.h"
#include "Turret.h"
#include "Shield.h"

static float PRIVATE_Spaceship_ratioToSmock = 0.25;

Spaceship * Spaceship_New(SpaceshipType spaceshipType,
                          float x, float y,
                          BodyType bodyType,
                          ReactorType reactorType,
                          ReactorType reactorSecondaryType,
                          WeaponType weaponMainType,
                          WeaponType weaponSecondaryType,
                          TurretType turretType,
                          ShieldType shieldType,
                          Singleton * o);

void Spaceship_SetBody(Spaceship * spaceship, BodyType bodyType, PatternManager * pm);
void Spaceship_SetReactor(Spaceship * spaceship, ReactorType reactorType, PatternManager * pm);
void Spaceship_SetReactorSecondary(Spaceship * spaceship, ReactorType reactorType, PatternManager * pm);
void Spaceship_SetMainWeapon(Spaceship * spaceship, WeaponType weaponType, PatternManager * pm);
void Spaceship_SetWeaponSecondary(Spaceship * spaceship, WeaponType weaponType, PatternManager * pm);
void Spaceship_SetTurret(Spaceship * spaceship, TurretType turretType, PatternManager * pm);
void Spaceship_SetShield(Spaceship * spaceship, ShieldType shieldType, PatternManager * pm);

void Spaceship_SetPos(Spaceship * spaceship, float x, float y);
float Spaceship_GetTotalSpeed(Spaceship * spaceship);
void Spaceship_Move(Spaceship * spaceship, float xPlus, float yPlus);
void Spaceship_ResetRotate(Spaceship * spaceship, PatternManager * pm);
void Spaceship_Rotate(Spaceship * spaceship, float anglePlus);
void Spaceship_Update(Spaceship * spaceship, TeamType teamType, Singleton * o);
bool Spaceship_IsOutOff(Spaceship * spaceship, int x, int y, int w, int h);

void Spaceship_SetLifeMax(Spaceship * spaceship, bool setFullLife);
float Spaceship_GetLifeMax(Spaceship * spaceship);
float Spaceship_GetLife(Spaceship * spaceship);
void Spaceship_SetDamage(Spaceship * spaceship, float damage);
float Spaceship_GetTotalDamagePerSeconde(Spaceship * spaceship);
void Spaceship_SetLife(Spaceship * spaceship, float life);
bool Spaceship_GotNoLife(Spaceship * spaceship);
void Spaceship_SetPosIfOutOf(Spaceship * spaceship, int x, int y, int w, int h);

void Spaceship_Draw(Spaceship * spaceship, Window * window, Singleton * o);
void Spaceship_Free(Spaceship * spaceship);
#endif /* Spaceship_h */
