//
//  Reactor.h
//  ShootThemUp
//
//  Created by El-idrissi Elyas on 12/12/2019.
//  Copyright © 2019 El-idrissi Elyas. All rights reserved.
//

#ifndef Reactor_h
#define Reactor_h

#include "main.h"

void Reactor_SetPos(Reactor * reactor, float x, float y);
void Reactor_Move(Reactor * reactor, float xPlus, float yPlus);
float Reactor_GetReactorSlotPosXAbsolute(Reactor * reactor);
float Reactor_GetReactorSlotPosYAbsolute(Reactor * reactor);
void Reactor_Free(Reactor * reactor);

#endif /* Reactor_h */
