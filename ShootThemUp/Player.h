//
//  Player.h
//  ShootThemUp
//
//  Created by El-idrissi Elyas on 01/12/2019.
//  Copyright © 2019 El-idrissi Elyas. All rights reserved.
//

#ifndef Player_h
#define Player_h

#include "main.h"

#include "Sprite.h"
#include "TextureManager.h"
#include "Singleton.h"
#include "Bullet.h"
#include "PatternManager.h"
#include "Utils.h"
#include "Shield.h"

static int PRIVATE_Player_INSTANCE = 0;
static const char PRIVATE_Player_ID[] = "Player";

static const int PRIVATE_Player_defaultRotation = 0;

//------------------ [Constructeurs] ------------------//

Player * Player_NewDefault(float x, float y);

//-------------------- [Méthodes] ---------------------//

void Player_DrawSpaceship(Player * player, Window * window,Singleton * o);
void Player_ActionOnSpaceship(Player * player, const Uint8 * eventList, Singleton * o);
void Player_AutoActionOnSpaceship(Player * player, Singleton * o);
void Player_SetSpaceship(Player * player, Spaceship * spaceship);

//------------------ [Déstructeurs] -------------------//
void Player_Free(Player * player);

#endif /* Player_h */
