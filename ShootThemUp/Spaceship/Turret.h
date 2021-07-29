//
//  Turret.h
//  ShootThemUp
//
//  Created by El-idrissi Elyas on 17/12/2019.
//  Copyright © 2019 El-idrissi Elyas. All rights reserved.
//

#ifndef Turret_h
#define Turret_h

#include "main.h"
#include "PatternManager.h"
#include "Singleton.h"

void Turret_SetPos(Turret * turret, float x, float y);

void Turret_Shoot(Turret * turret, Spaceship * spaceship, TeamType teamType, BulletType bulletType, Singleton * o);
float Turret_GetTurretSlotPosXAbsolute(Turret * turret);
float Turret_GetTurretSlotPosYAbsolute(Turret * turret);
float Turret_GetDamagePerSecond(Turret * turret);
void Turret_ResetCooldown(Turret * turret);
void Turret_CooldownUpdate(Turret * turret);
void Turret_CibleUpdate(Turret * turret, TeamType teamType, Spaceship * spaceship, Singleton * o);
bool Turret_CanShoot(Turret * turret);
void Turret_Free(Turret * turret);
#endif /* Turret_h */
