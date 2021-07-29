//
//  Bullet.h
//  ShootThemUp
//
//  Created by El-idrissi Elyas on 04/12/2019.
//  Copyright © 2019 El-idrissi Elyas. All rights reserved.
//

#ifndef Bullet_h
#define Bullet_h

#include "main.h"
#include "TextureManager.h"
#include "Window.h"
#include "Utils.h"
#include "PatternManager.h"

static int PRIVATE_Bullet_INSTANCE = 0;
static const char PRIVATE_Bullet_ID[] = "Bullet";
static const char PRIVATE_Bullet_defaultIdleId[] = "bullet";

static int PRIVATE_Bullet_defaultLife = 3;
static int PRIVATE_Bullet_defaultSpeed = 20;
static int PRIVATE_Bullet_defaultW = 5;
static int PRIVATE_Bullet_defaultH = 13;

Bullet * Bullet_NewDefault(TextureManager * tm, int x, int y, float speed, float damage, BulletType bulletType, PatternManager * pm);
void Bullet_Draw(Bullet * bullet, Window * win);
void Bullet_InMovePosUpdate(Bullet * bullet);
bool Bullet_IsOutOff(Bullet * bullet, int x, int y, int w, int h);
void Bullet_Free(Bullet * bullet);

#endif /* Bullet_h */
