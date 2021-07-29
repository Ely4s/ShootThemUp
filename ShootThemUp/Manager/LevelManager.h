//
//  LevelManager.h
//  ShootThemUp
//
//  Created by El-idrissi Elyas on 03/01/2020.
//  Copyright © 2020 El-idrissi Elyas. All rights reserved.
//

#ifndef LevelManager_h
#define LevelManager_h

#include "main.h"
#include "Enemy.h"
#include "Spaceship.h"

Enemy * LevelManager_NewEnemy(Singleton * o, EnemyType enemyType, int level);
Spaceship * LevelManager_EnemyApplyVisual(Singleton * o, EnemyType enemyType);
void LevelManager_EnemyApplyLevel(Singleton * o, Enemy * enemy, int level);
void LevelManager_EnemyApplyType(Singleton * o, Enemy * enemy, EnemyType enemyType);

#endif /* LevelManager_h */
