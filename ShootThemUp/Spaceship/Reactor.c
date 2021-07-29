//
//  Reactor.c
//  ShootThemUp
//
//  Created by El-idrissi Elyas on 12/12/2019.
//  Copyright © 2019 El-idrissi Elyas. All rights reserved.
//

#include "Reactor.h"

void Reactor_SetPos(Reactor * reactor, float x, float y)
{
    if(reactor)
    {
        reactor->x = x;
        reactor->y = y;
        reactor->sprite.x = x;
        reactor->sprite.y = y;
    }
}

void Reactor_Move(Reactor * reactor, float xPlus, float yPlus)
{
    if(reactor)
    {
        reactor->x += xPlus;
        reactor->y += yPlus;
        reactor->sprite.x += xPlus;
        reactor->sprite.y += yPlus;
    }
}

float Reactor_GetReactorSlotPosXAbsolute(Reactor * reactor)
{
    if(reactor)
    {
        return reactor->x + reactor->slotPos.x;
    }
    else
    {
        return 0;
    }
}

float Reactor_GetReactorSlotPosYAbsolute(Reactor * reactor)
{
    if(reactor)
    {
        return reactor->y + reactor->slotPos.y;
    }
    else
    {
        return 0;
    }
}


void Reactor_Free(Reactor * reactor)
{
    if(reactor)
    {
        free(reactor);
        reactor = NULL;
    }
}
