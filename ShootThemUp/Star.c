//
//  Star.c
//  ShootThemUp
//
//  Created by El-idrissi Elyas on 05/01/2020.
//  Copyright © 2020 El-idrissi Elyas. All rights reserved.
//

#include "Star.h"

void Star_Generate(Singleton * o, bool forAllScreen)
{
    int nbrTry;
    
    if(!forAllScreen) nbrTry = 20 * PRIVATE_Star_speed;
    else nbrTry = (20 * o->window.h) ;
    
    for(int i = 0; i < nbrTry; i++)
    {
        if(Utils_Random_Int(0, 1000) == 0)
        {
            Sprite * star = malloc(sizeof(Sprite));
            *star = Sprite_New(0, 0, 0, 0, "Star", &o->tm);
            
            star->w = star->w;
            star->h = star->w;
            
            star->x = Utils_Random_Int(0, o->window.w - star->w);
            if(forAllScreen) star->y = Utils_Random_Int(0, o->window.h - star->h);
            
            array_add(o->starsFar, star);
            
        }
    }
    
    if(!forAllScreen) nbrTry = 8 * PRIVATE_Star_speed;
    else nbrTry = (8 * o->window.h) ;
    
    for(int i = 0; i < nbrTry; i++)
    {
        if(Utils_Random_Int(0, 1000) == 0)
        {
            Sprite * star = malloc(sizeof(Sprite));
            *star = Sprite_New(0, 0, 0, 0, "Star", &o->tm);
            
            star->w = star->w*2;
            star->h = star->h*2;
            
            star->x = Utils_Random_Int(0, o->window.w - star->w);
            if(forAllScreen) star->y = Utils_Random_Int(0, o->window.h - star->h);
            
            array_add(o->starsMidway, star);
        }
    }
    
    if(!forAllScreen) nbrTry = 2 * PRIVATE_Star_speed;
    else nbrTry = (2 * o->window.h) ;
    
    for(int i = 0; i < nbrTry; i++)
    {
        if(Utils_Random_Int(0, 1000) == 0)
        {
            Sprite * star = malloc(sizeof(Sprite));
            *star = Sprite_New(0, 0, 0, 0, "Star", &o->tm);
            
            star->w = star->w*3;
            star->h = star->h*3;
            
            star->x = Utils_Random_Int(0, o->window.w - star->w);
            if(forAllScreen) star->y = Utils_Random_Int(0, o->window.h - star->h);
            
            array_add(o->starsNear, star);
        }
    }
}

void Star_UpdateAll(Singleton * o)
{
    for(int i = 0; i < array_size(o->starsFar); i++)
    {
        Sprite * star = array_get_at(o->starsFar, i);
        star->y += 0.40 * PRIVATE_Star_speed;
        
        if(star->y > o->window.h || star->x + star->w < 0 || star->x > o->window.h)
        {
            array_remove_at(o->starsFar, i, NULL);
            i--;
        }
    }
    
    for(int i = 0; i < array_size(o->starsMidway); i++)
    {
        Sprite * star = array_get_at(o->starsMidway, i);
        star->y += 0.62 * PRIVATE_Star_speed;
        
        if(star->y > o->window.h || star->x + star->w < 0 || star->x > o->window.h)
        {
            array_remove_at(o->starsMidway, i, NULL);
            i--;
        }
    }
    
    
    for(int i = 0; i < array_size(o->starsNear); i++)
    {
        Sprite * star = array_get_at(o->starsNear, i);
        star->y += 0.75 * PRIVATE_Star_speed;
        
        if(star->y > o->window.h || star->x + star->w < 0 || star->x > o->window.h)
        {
            array_remove_at(o->starsNear, i, NULL);
            i--;
        }
    }
}

void Star_FreeAll(Singleton * o)
{
    for(int i = 0; i < array_size(o->starsFar); i++)
    {
        array_remove_at(o->starsFar, i, NULL);
        i--;
        
    }
    
    for(int i = 0; i < array_size(o->starsMidway); i++)
    {
        array_remove_at(o->starsMidway, i, NULL);
        i--;
        
    }
    
    for(int i = 0; i < array_size(o->starsNear); i++)
    {
        array_remove_at(o->starsNear, i, NULL);
        i--;
    }
    
}

void Star_DrawAll(Singleton * o)
{
    for(int i = 0; i < array_size(o->starsFar); i++)
    {
        Sprite * star = array_get_at(o->starsFar, i);
        Sprite_Draw(star, -90, 0, 0, &o->window);
    }
    
    for(int i = 0; i < array_size(o->starsMidway); i++)
    {
        Sprite * star = array_get_at(o->starsMidway, i);
        Sprite_Draw(star, -90, 0, 0, &o->window);
    }
    
    for(int i = 0; i < array_size(o->starsNear); i++)
    {
        
        Sprite * star = array_get_at(o->starsNear, i);
        
        Sprite_Draw(star, -90, 0, 0, &o->window);
        
    }
}
