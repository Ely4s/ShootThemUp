//
//  Singleton.h
//  ShootThemUp
//
//  Created by El-idrissi Elyas on 02/12/2019.
//  Copyright © 2019 El-idrissi Elyas. All rights reserved.
//

#ifndef Singleton_h
#define Singleton_h

#include "main.h"

#include "Play.h"
#include "Window.h"
#include "TextureManager.h"
#include "PatternManager.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Explosion.h"
#include "PlayerBar.h"
#include "Shop.h"
#include "MenuDead.h"
#include "MenuPause.h"

void Singleton_InitAll(Singleton * o);
void Singleton_AddPlayer(Singleton * o, Player * player);
void Singleton_AddText(Singleton * o, Text * text);
void Singleton_AddBullet(Singleton * o, Bullet * text);
void Singleton_AddEnemy(Singleton * o, Enemy * enemy);
void Singleton_AddExplosion(Singleton * o, Explosion * explosion);
void Singleton_ZindexOnEnemy(Array * array, int low, int high);

void Singleton_FreePlayer(Singleton * o);
void Singleton_FreeText(Singleton * o, int it);
void Singleton_FreeBullet(Singleton * o,int it);
void Singleton_FreeEnemy(Singleton * o, int it);
void Singleton_FreeExplosion(Singleton * o, int it);

void Singleton_Free(Singleton * o);

#endif /* Singleton_h */
