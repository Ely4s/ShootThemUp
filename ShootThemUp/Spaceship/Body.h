//
//  Body.h
//  ShootThemUp
//
//  Created by El-idrissi Elyas on 07/12/2019.
//  Copyright © 2019 El-idrissi Elyas. All rights reserved.
//

#ifndef Body_h
#define Body_h

#include "main.h"
#include "Sprite.h"
#include "PatternManager.h"

Body * Body_New(BodyType bodyType, int x, int y, TextureManager * tm, PatternManager * pm);

void Body_Draw(Body * body, Window * window);

void Body_SetPos(Body * body, int x, int y);
void Body_Move(Body * body, float xPlus, float yPlus);
float Body_GetPosX(Body * body);
float Body_GetPosY(Body * body);

void Body_SetSize(Body * body, int w, int h);
int Body_GetW(Body * body);
int Body_GetH(Body * body);

void Body_SetLife(Body * body, int life);
void Body_AddLife(Body * body, int life);
int Body_GetLife(Body * body);

void Body_SetSlotPos(Body * body, PointF * slotPos);
PointF * Body_GetSlotPos(Body * body);
float Body_GetBodySlotPosXAbsolute(Body * body);
float Body_GetBodySlotPosYAbsolute(Body * body);
void Body_Free(Body * body);
#endif /* Body_h */
