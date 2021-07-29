//
//  Play.h
//  ShootThemUp
//
//  Created by El-idrissi Elyas on 26/11/2019.
//  Copyright © 2019 El-idrissi Elyas. All rights reserved.
//

#ifndef Play_h
#define Play_h


#include "main.h"

#include "Singleton.h"
#include "Game.h"
#include "Utils.h"
#include "Player.h"
#include "Text.h"
#include "PatternManager.h"
#include "Spaceship.h"
#include "Body.h"
#include "Explosion.h"
#include "MenuDead.h"
#include "LevelManager.h"
#include "Star.h"

static int PRIVATE_Play_nextLevelMessageTimeLife = 10;

void Play_Update(Play * play, Singleton * o);
void Play_Draw(Play * play, Singleton * o);

void Play_SetPlayerSpaceshipPosInDefault(Play * play, Spaceship * spaceship);

void Play_Reset(Singleton * o);
void Play_CheckForNextLevel(Play * play, Singleton * o);
void Play_DestroyedAllEnemy(Singleton * o);
void Play_DestroyedAllBullet(Singleton * o);

#endif /* Play_h */
