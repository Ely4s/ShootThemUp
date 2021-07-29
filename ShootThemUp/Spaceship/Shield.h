//
//  Shield.h
//  ShootThemUp
//
//  Created by El-idrissi Elyas on 17/12/2019.
//  Copyright © 2019 El-idrissi Elyas. All rights reserved.
//

#ifndef Shield_h
#define Shield_h

#include "main.h"

void Shield_SetPos(Shield * shield, float x, float y);

bool Shield_CanBeActivated(Shield * shield);
void Shield_AddDamage(Shield * shield, float damage);
void Shield_Activation(Shield * shield);
void Shield_LifeTimeUpdate(Shield * shield);
void Shield_CooldownUpdate(Shield * shield);
bool Shield_isActivated(Shield * shield);
void Shield_Free(Shield * shield);

#endif /* Shield_h */
