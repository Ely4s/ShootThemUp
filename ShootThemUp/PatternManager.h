//
//  PatternManager.h
//  ShootThemUp
//
//  Created by El-idrissi Elyas on 06/12/2019.
//  Copyright © 2019 El-idrissi Elyas. All rights reserved.
//

#ifndef PatternManager_h
#define PatternManager_h

#include "main.h"
#include "TextureManager.h"
#include "Sprite.h"
#include "Utils.h"

void PatternManager_LoadTextures(PatternManager * pm, TextureManager * tm);

void PatternManager_AddBodyPattern(PatternManager * pm, BodyType bodyType, PointF slotPos, int w, int h, float lifeMax, char textureId[], TextureManager * tm);
Body * PatternManager_GetBodyPattern(PatternManager * pm, BodyType bodyType);

void PatternManager_AddReactorPattern(PatternManager * pm, ReactorType reactorType, PointF slotPos, int w, int h, float lifeMax, float speed, char textureId[], TextureManager * tm);
Reactor * PatternManager_GetReactorPattern(PatternManager * pm, ReactorType reactorType);

void PatternManager_AddWeaponPattern(PatternManager * pm, WeaponType weaponType, PointF slotPos, int w, int h, float lifeMax, float damage, float speedBullet, float cooldown, char textureId[], TextureManager * tm);
Weapon * PatternManager_GetWeaponPattern(PatternManager * pm, WeaponType weaponType);

void PatternManager_AddWeaponSecondaryPattern(PatternManager * pm, WeaponType weaponType, PointF slotPos, int w, int h, float lifeMax, float damage, float speedBullet, float cooldown, char textureId[], TextureManager * tm);
Weapon * PatternManager_GetWeaponSecondaryPattern(PatternManager * pm, WeaponType weaponType);

void PatternManager_AddTurretPattern(PatternManager * pm, TurretType turretType, PointF slotPos, int w, int h, float lifeMax, float damage, float speedBullet, float cooldown, float speedRotation, char textureId[], TextureManager * tm);
Turret * PatternManager_GetTurretPattern(PatternManager * pm, TurretType turretType);

void PatternManager_AddShieldPattern(PatternManager * pm, ShieldType shieldType, PointF slotPos, int w, int h, float lifeMax, float lifeTimeMax, float cooldown, char textureId[], TextureManager * tm);
Shield * PatternManager_GetShieldPattern(PatternManager * pm, ShieldType shieldType);

void PatternManager_AddBulletPattern(PatternManager * pm, BulletType bulletType, BulletEffectType bulletEffectType, PointF slotPos, int w, int h, char textureId[], TextureManager * tm);
Bullet * PatternManager_GetBulletPattern(PatternManager * pm, BulletType bulletType);

void PatternManager_AddSpaceshipSlotsPattern(PatternManager * pm, SpaceshipType spaceshipType, PointF spaceshipPos, PointF reactorPos, PointF reactorSecondaryPos, PointF weaponMainPos, PointF weaponSecondaryPos, PointF turretPos);

SpaceshipSlot * PatternManager_GetSpaceshipSlotsPattern(PatternManager * pm, SpaceshipType spaceshipType);

void PatterManager_GetTextureIdFromElementAndTier(int element, int tier, char str[]);

#endif /* PatternManager_h */
