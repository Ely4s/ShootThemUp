//
//  Weapon.h
//  ShootThemUp
//
//  Created by El-idrissi Elyas on 12/12/2019.
//  Copyright © 2019 El-idrissi Elyas. All rights reserved.
//

#ifndef Weapon_h
#define Weapon_h

#include "main.h"
#include "PatternManager.h"
#include "Singleton.h"

void Weapon_SetPos(Weapon * weapon, float x, float y);
void Weapon_Move(Weapon * weapon, float xPlus, float yPlus);
float Weapon_GetDamagePerSecond(Weapon * weapon);
float Weapon_GetWeaponSlotPosXAbsolute(Weapon * weapon);
float Weapon_GetWeaponSlotPosYAbsolute(Weapon * weapon);
void Weapon_Shoot(Weapon * weapon, TeamType teamType, BulletType bulletType, Singleton * o);
void Weapon_ResetCooldown(Weapon * weapon);
void Weapon_CooldownUpdate(Weapon * weapon);
bool Weapon_CanShoot(Weapon * weapon);
void Weapon_Free(Weapon * weapon);
#endif /* Weapon_h */
