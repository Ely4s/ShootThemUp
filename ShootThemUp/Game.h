//
//  Game.h
//  ShootThemUp
//
//  Created by El-idrissi Elyas on 03/01/2020.
//  Copyright © 2020 El-idrissi Elyas. All rights reserved.
//

#ifndef Game_h
#define Game_h

#include "main.h"
#include "Play.h"
#include "Singleton.h"
#include "Utils.h"
#include "Player.h"
#include "Text.h"
#include "PatternManager.h"
#include "Spaceship.h"
#include "Body.h"
#include "Explosion.h"
#include "MenuDead.h"

void Game_Update(Game * game, Singleton * o);
void Game_Draw(Game * game, Singleton * o);
void Game_Wait(Game * game, Timer * t);

void Game_SetFps(Game * game, float fps);
void Game_Start(Game * game);
void Game_Over(Game * game);
bool Game_GetIsRunning(Game * game);

#endif /* Game_h */
