//
//  Enemy.h
//  ShootThemUp
//
//  Created by El-idrissi Elyas on 05/12/2019.
//  Copyright © 2019 El-idrissi Elyas. All rights reserved.
//

#ifndef Enemy_h
#define Enemy_h

#include "main.h"

#include "Sprite.h"
#include "TextureManager.h"
#include "Singleton.h"
#include "Bullet.h"

static int PRIVATE_Enemy_INSTANCE = 0;
static const char PRIVATE_Enemy_ID[] = "Enemy";

static const double PRIVATE_Enemy_defaultX = 0;
static const double PRIVATE_Enemy_defaultY = 0;

static const int PRIVATE_Enemy_defaultW = 64;
static const int PRIVATE_Enemy_defaultH = 64;

static const int PRIVATE_Enemy_defaultLife = 1;

static const double PRIVATE_Enemy_defaultSpeed = 4;

static const int PRIVATE_Enemy_defaultNbrMunition = 500;

static const int PRIVATE_Enemy_defaultRotation = 180;

static const char PRIVATE_Enemy_defaultIdleId[] = "ship";


//------------------ [Constructeurs] ------------------//

Enemy * Enemy_NewDefault(void);

//-------------------- [Méthodes] ---------------------//

void Enemy_DrawSpaceship(Enemy * enemy, Window * window, Singleton * o);
void Enemy_SetSpaceship(Enemy * enemy, Spaceship * spaceship);
void Enemy_AutoActionOnSpaceship(Enemy * enemy, Singleton * o);
void Enemy_SpaceshipHamper(Enemy * enemy);

//------------------ [Déstructeurs] -------------------//
void Enemy_Free(Enemy * enemy);
#endif /* Enemy_h */
