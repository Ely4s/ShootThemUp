//
//  Body.c
//  ShootThemUp
//
//  Created by El-idrissi Elyas on 07/12/2019.
//  Copyright © 2019 El-idrissi Elyas. All rights reserved.
//

#include "Body.h"

Body * Body_New(BodyType bodyType, int x, int y, TextureManager * tm, PatternManager * pm)
{
    if(tm && pm)
    {
        Body * body = malloc(sizeof(Body));
        body = PatternManager_GetBodyPattern(pm, bodyType);
    
        body->x = x;
        body->y = y;
    
        body->sprite.x = body->x;
        body->sprite.y = body->y;
    
        body->sprite.w = body->w;
        body->sprite.h = body->h;
    
        return body;
    }
    else
    {
        return NULL;
    }
}

void Body_Draw(Body * body, Window * window)
{
    if(body)
    {
        Sprite_Draw(&body->sprite, 0, 0, 0, window);
    }
}

void Body_SetPos(Body * body, int x, int y)
{
    if(body)
    {
        body->x = x;
        body->y = y;
        body->sprite.x = x;
        body->sprite.y = y;
    }
}

void Body_Move(Body * body, float xPlus, float yPlus)
{
    if(body)
    {
        body->x += xPlus;
        body->y += yPlus;
        body->sprite.x += xPlus;
        body->sprite.y += yPlus;
    }
}

void Body_SetLife(Body * body, int life)
{
    if(body)
    {
        body->life = life;
    }
}

void Body_AddLife(Body * body, int life)
{
    if(body)
    {
        body->life += life;
    }
}

int Body_GetLife(Body * body)
{
    if(body)
    {
        return body->life;
    }
    else
    {
        return 0;
    }
}

void Body_SetSlotPos(Body * body, PointF * slotPos)
{
    if(body && slotPos)
    {
        body->slotPos = *slotPos;
    }
    
    if(slotPos) free(slotPos);
}

PointF * Body_GetSlotPosX(Body * body)
{
    if(body)
    {
        return &body->slotPos;
    }
    else
    {
        return NULL;
    }
}

void Body_SetSize(Body * body, int w, int h)
{
    if(body)
    {
        body->w = w;
        body->h = h;
    }
}

int Body_GetW(Body * body)
{
    if(body)
    {
        return body->w;
    }
    else
    {
        return 0;
    }
}

int Body_GetH(Body * body)
{
    if(body)
    {
        return body->h;
    }
    else
    {
        return 0;
    }
}

float Body_GetPosX(Body * body)
{
    if(body)
    {
        return body->x;
    }
    else
    {
        return 0;
    }
}

float Body_GetPosY(Body * body)
{
    if(body)
    {
        return body->y;
    }
    else
    {
        return 0;
    }
}

float Body_GetBodySlotPosXAbsolute(Body * body)
{
    if(body)
    {
        return body->x + body->slotPos.x;
    }
    else
    {
        return 0;
    }
}

float Body_GetBodySlotPosYAbsolute(Body * body)
{
    if(body)
    {
        return body->y + body->slotPos.y;
    }
    else
    {
        return 0;
    }
}

void Body_Free(Body * body)
{
    if(body)
    {
        free(body);
        body = NULL;
    }
}
