//
//  Utils.c
//  ShootThemUp
//
//  Created by El-idrissi Elyas on 26/11/2019.
//  Copyright © 2019 El-idrissi Elyas. All rights reserved.
//

#include "Utils.h"
#include <time.h>

//struct _Timer
//{
//    float begin;
//    float end;
//    
//};

//---------------------- [TIMER] ------------------------//

void Utils_Timer_Start(Timer * t)
{
    t->begin = (float)(clock())/ CLOCKS_PER_SEC;
}

void Utils_Timer_Stop(Timer * t)
{
    t->end = ((float)(clock())/ CLOCKS_PER_SEC);
    t->end += ((float)PRIVATE_Utils_Sleep_MsInSleep)/1000.0;
}

float Utils_Timer_TimeS(Timer * t)
{
    return (t->end - t->begin);
}

float Utils_Timer_TimeMs(Timer * t)
{
    return ((t->end - t->begin))*1000.0;
}

//---------------------- [RANDOM] -----------------------//

int Utils_Random_Int(int randomMin, int randomMax)
{
    if(!PRIVATE_Utils_Random_isInit)
    {
        srand((unsigned int)time(NULL));
        PRIVATE_Utils_Random_isInit = true;
    }
    
    if(randomMax != randomMin)
    {
        return rand() % randomMax + randomMin;
    }
    else
    {
        return randomMin;
    }
}

//---------------------- [SLEEP] ------------------------//

void Utils_Sleep_MsInSleepInit()
{
    PRIVATE_Utils_Sleep_MsInSleep = 0;
}

void Utils_Sleep_Ms(int msSpleepDuration)
{
    PRIVATE_Utils_Sleep_MsInSleep += msSpleepDuration;
    SDL_Delay(msSpleepDuration);
}

//---------------------- [PRINT] ------------------------//

void Utils_Print_FpsFromTimer(Timer * timer)
{
    printf("FPS : %.0f\n", (1/Utils_Timer_TimeS(timer)));
}

//---------------------- [COLOR] ------------------------//

SDL_Color Utils_Color_Get(uint8_t r, uint8_t g, uint8_t b)
{
    SDL_Color color = {r,g,b};
    
    return color;
}

//---------------------- [Collision] ------------------------//

bool Utils_Collision_isBulletInCollisionWithSpaceship(Bullet * bullet, Spaceship * spaceship)
{
    return Utils_Collision_AABB(bullet->x, bullet->y, bullet->w, bullet->h, spaceship->x, spaceship->y, spaceship->w, spaceship->h);
}

bool Utils_Collision_isBulletInCollisionWithShield(Bullet * bullet, Shield * shield)
{
    return Utils_Collision_AABBC(bullet->x, bullet->y, bullet->w, bullet->h, shield->x + shield->w/2, shield->y + shield->h/2, shield->h/2);
}

bool Utils_Collision_isExplosionInCollisionWithSpaceship(Explosion * explosion, Spaceship * spaceship)
{
    return Utils_Collision_AABBC(spaceship->x, spaceship->y, spaceship->w, spaceship->h, explosion->x + explosion->w/2, explosion->y + explosion->h/2, explosion->h/2);
}

bool Utils_Collision_isExplosionInCollisionWithShield(Explosion * explosion, Shield * shield)
{
    return Utils_Collision_CC(explosion->x + explosion->w/2, explosion->y + explosion->h/2, explosion->h/2, shield->x + shield->w/2, shield->y + shield->h/2, shield->h/2);
}

float max(float a, float b)
{
    return (a>b)? a : b;
}


float min(float a, float b)
{
    return (a<b)? a : b;
}

bool Utils_Collision_AABB(int aX, int aY, int aW, int aH, int bX, int bY, int bW, int bH)
{
    return !((aX >= bX + bW)
             || (aX + aW <= bX)
             || (aY >= bY + bH)
             || (aY + aH <= bY));
}

bool Utils_Collision_AABBC(int aX, int aY, int aW, int aH, int centerX, int centerY, int radius)
{
    float DeltaX = centerX - max(aX, min(centerX, aX + aW/2));
    float DeltaY = centerY - max(aY, min(centerY, aY + aH/2));
    return (DeltaX * DeltaX + DeltaY * DeltaY) < (radius * radius);
}

bool Utils_Collision_CC(int centerX1, int centerY1, int radius1, int centerX2, int centerY2, int radius2)
{
    int d2 = (centerX1 - centerX2)*(centerX1 - centerX2) + (centerY1 - centerY2)*(centerY1 - centerY2);
    if (d2 > (radius1 + radius2)*(radius1 + radius2))
        return false;
    else
        return true;
}




//bool intersects(Bullet * bullet, Shield * shield)
//{
//
//    float circleDistanceX = fabsf((shield->x + shield->w/2) - (bullet->x + bullet->w/2));
//    float circleDistanceY = fabsf((shield->y + shield->h/2) - (bullet->y + bullet->h/2));
//
//    if (circleDistanceX > (bullet->w/2 + 124/2)) { return false; }
//    if (circleDistanceY > (bullet->h/2 + 124/2)) { return false; }
//
//    if (circleDistanceX <= (bullet->w/2)) { return true; }
//    if (circleDistanceY <= (bullet->h/2)) { return true; }
//
//    float cornerDistance_sq = (int)(circleDistanceX - bullet->w/2)^2 + (int)(circleDistanceY - bullet->h/2)^2;
//
//    return (cornerDistance_sq <= ((124/2)^2));
//}

//---------------------- [Draw] ------------------------//

void Utils_Draw_Rect(int x, int y, int w, int h, Window * window)
{
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
    
    SDL_SetRenderDrawColor(window->renderer, 255, 0, 0, 255);
    SDL_RenderDrawRect(window->renderer, &rect);
    SDL_SetRenderDrawColor(window->renderer, window->defaultColor.r , window->defaultColor.g, window->defaultColor.b, 255);
}

//---------------------- [Point] ------------------------//

PointF Utils_PointF_New(float x, float y)
{
    PointF pointF;
    pointF.x = x;
    pointF.y = y;
    
    return pointF;
}

//---------------------- [Math] ------------------------//

float Utils_Math_DistanceBetweenPoint(float point1x, float point1y, float point2x, float point2y)
{
    return sqrt(((point2x-point1x)*(point2x-point1x))+((point2y-point1y)*(point2y-point1y)));
}

void Utils_Math_MoveRelativeToRotationAxis(float * pointx, float * pointy, float * centerx, float * centery, float radian)
{
    
    float rotatedX = cos(radian) * (*pointx - *centerx) - sin(radian) * (*pointy - *centery) + *centerx;
    float rotatedY = sin(radian) * (*pointx - *centerx) + cos(radian) * (*pointy - *centery) + *centerx;
    
    *pointx = rotatedX;
    *pointy = rotatedY;
    
}

float Utils_Math_RadianToDegre(float radian)
{
    return radian/(M_PI/180);
}

float Utils_Math_DegreToRadian(float degre)
{
    return degre*(M_PI/180);
}

void Utils_Math_SetPosRelativeToRotationAxis(float * pointx, float * pointy, float * centerx, float * centery, float radian)
{
    float distance = Utils_Math_DistanceBetweenPoint(*centerx, *centery, *pointx, *pointy);
    
    float rotatedX = (distance * cos(radian)) + *centerx;
    float rotatedY = (distance * sin(radian)) + *centery;
    
    *pointx = rotatedX;
    *pointy = rotatedY;
}

float Utils_Math_GetRadianFromTwoPoints(float point1x, float point1y, float point2x, float point2y)
{
    float deltaX = point2x - point1x;
    float deltaY = point2y - point1y;
    return atan2(deltaY, deltaX);
}

void Utils_Math_SetPosAtDistanceRelativeToAngle(float * pointx, float * pointy, float radian, float distance)
{
    *pointx += distance * cos(radian);
    *pointy += distance * sin(radian);
}

int Utils_2DTabPosTo1D(int x, int y, int w)
{
    return w*x + y;
}



