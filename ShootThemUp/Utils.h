//
//  Utils.h
//  ShootThemUp
//
//  Created by El-idrissi Elyas on 26/11/2019.
//  Copyright © 2019 El-idrissi Elyas. All rights reserved.
//

#ifndef Utils_h
#define Utils_h

#include "main.h"

//---------------------- [TIMER] ------------------------//

void Utils_Timer_Start(Timer * t);
void Utils_Timer_Stop(Timer * t);

float Utils_Timer_TimeS(Timer * t);
float Utils_Timer_TimeMs(Timer * t);

//---------------------- [RANDOM] -----------------------//

static bool PRIVATE_Utils_Random_isInit = 0;

int Utils_Random_Int(int randomMin, int randomMax);

//---------------------- [SLEEP] ------------------------//

static int PRIVATE_Utils_Sleep_MsInSleep = 0;

void Utils_Sleep_MsInSleepInit(void);
void Utils_Sleep_Ms(int msSpleepDuration);

//---------------------- [PRINT] ------------------------//

void Utils_Print_FpsFromTimer(Timer * timer);

//---------------------- [COLOR] ------------------------//

SDL_Color Utils_Color_Get(uint8_t r, uint8_t g, uint8_t b);

bool Utils_Collision_isBulletInCollisionWithSpaceship(Bullet * bullet, Spaceship * spaceship);
bool Utils_Collision_isBulletInCollisionWithShield(Bullet * bullet, Shield * shield);
bool Utils_Collision_isExplosionInCollisionWithSpaceship(Explosion * explosion, Spaceship * spaceship);
bool Utils_Collision_isExplosionInCollisionWithShield(Explosion * explosion, Shield * shield);

bool Utils_Collision_AABB(int aX, int aY, int aW, int aH, int bX, int bY, int bW, int bH);
bool Utils_Collision_AABBC(int aX, int aY, int aW, int aH, int centerX, int centerY, int radius);
bool Utils_Collision_CC(int centerX1, int centerY1, int radius1, int centerX2, int centerY2, int radius2);

float max(float a, float b);
float min(float a, float b);

void Utils_Draw_Rect(int x, int y, int w, int h, Window * window);

float Utils_Math_DistanceBetweenPoint(float point1x, float point1y, float point2x, float point2y);

void Utils_Math_MoveRelativeToRotationAxis(float * pointx, float * pointy, float * centerx, float * centery, float radian);

void Utils_Math_SetPosRelativeToRotationAxis(float * pointx, float * pointy, float * centerx, float * centery, float radian);

float Utils_Math_RadianToDegre(float radian);
float Utils_Math_DegreToRadian(float degre);
float Utils_Math_GetRadianFromTwoPoints(float point1x, float point1y, float point2x, float point2y);
void Utils_Math_SetPosAtDistanceRelativeToAngle(float * pointx, float * pointy, float radian, float distance);


PointF Utils_PointF_New(float x, float y);

int Utils_2DTabPosTo1D(int x, int y, int w);
#endif /* Utils_h */
