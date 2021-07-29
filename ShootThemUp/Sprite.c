//
//  Sprite.c
//  ShootThemUp
//
//  Created by El-idrissi Elyas on 26/11/2019.
//  Copyright © 2019 El-idrissi Elyas. All rights reserved.
//

#include "Sprite.h"

Sprite Sprite_New(float x, float y, int ifErrorW, int ifErrorH, char * textureId, TextureManager * tm)
{
    Sprite s;
    Sprite_SetPos(&s, x, y);
    
    s.texture = TextureManager_GetTexture(tm, textureId);
    
    s.indexFrame = 0;
    s.maxFrame = TextureManager_GetTextureNbrOfFrame(tm, textureId);
    
    s.xOffSet = 0;
    s.yOffSet = 0;

    s.wFrame = TextureManager_GetTextureFrameW(tm, textureId);
    s.hFrame = TextureManager_GetTextureFrameH(tm, textureId);

    s.w = s.wFrame;
    s.h = s.hFrame;
    
    return s;
}

void Sprite_SetPos(Sprite * sprite, float x, float y)
{
    sprite->x = x;
    sprite->y = y;
    
}

int Sprite_GetPosX(Sprite * sprite)
{
    return sprite->x;
}

int Sprite_GetPosY(Sprite * sprite)
{
    return sprite->y;
}

void Sprite_SetTexture(Sprite * sprite, char * textureId, TextureManager * tm)
{
    sprite->texture = TextureManager_GetTexture(tm, textureId);
}

void Sprite_PosOffSet(Sprite * sprite, float xOffSet, float yOffSet)
{
    sprite->xOffSet = xOffSet;
    sprite->yOffSet = yOffSet;
}

void Sprite_LinkSize(Sprite * sprite, int w, int h)
{
    sprite->w = w;
    sprite->h = h;
}

void Sprite_Anime(Sprite * sprite, float addAnime)
{
    sprite->indexFrame += addAnime;
    
    if(sprite->indexFrame >= sprite->maxFrame)
    {
        sprite->indexFrame = 0;
    }
}

void Sprite_Draw(Sprite * sprite, float angle, float x, float y, Window * win)
{
    if(sprite)
    {
        if(sprite->texture)
        {
            SDL_Rect rectPos = {(int)sprite->x+sprite->xOffSet, (int)sprite->y+sprite->yOffSet, sprite->w, sprite->h};
            SDL_Point point = {x, y};
            
                SDL_Rect rectCut;
                rectCut.x = (int)sprite->indexFrame * sprite->wFrame;
                rectCut.y = 0;
                rectCut.w = sprite->wFrame;
                rectCut.h = sprite->hFrame;
                
                SDL_RenderCopyEx(win->renderer, sprite->texture, &rectCut, &rectPos, angle + 90, &point, SDL_FLIP_NONE);
            
            if(DEBUG_SPRITE_BOX)
            {
                SDL_SetRenderDrawColor(win->renderer, 0, 255, 0, 255);
                SDL_RenderDrawRect(win->renderer, &rectPos);
                SDL_SetRenderDrawColor(win->renderer, win->defaultColor.r, win->defaultColor.g, win->defaultColor.b, 255);
            }
        }
        else
        {
            SDL_Rect surface_rect = {sprite->x+sprite->xOffSet, sprite->y+sprite->yOffSet, sprite->wFrame, sprite->hFrame};
            
            SDL_Surface * surface = SDL_CreateRGBSurface(0, sprite->wFrame, sprite->hFrame, 32, 0, 0, 0, 0);
    
            SDL_Rect surface_color = {0, 0, sprite->wFrame, sprite->hFrame};
            SDL_FillRect(surface, &surface_color, SDL_MapRGB(surface->format, 255, 0, 255));
            surface_color.w = sprite->wFrame/2;
            surface_color.h = sprite->hFrame/2;
            SDL_FillRect(surface, &surface_color, SDL_MapRGB(surface->format, 0, 0, 0));
            surface_color.x = sprite->wFrame/2;
            surface_color.y = sprite->hFrame/2;
            surface_color.w = sprite->wFrame;
            surface_color.h = sprite->hFrame;
            SDL_FillRect(surface, &surface_color, SDL_MapRGB(surface->format, 0, 0, 0));
            
            SDL_Texture * texture = SDL_CreateTextureFromSurface(win->renderer, surface);
            
            SDL_Point point = {surface_rect.w/2, surface_rect.h/2};
            SDL_RenderCopyEx(win->renderer, texture, NULL, &surface_rect, angle + 90, &point, SDL_FLIP_NONE);
            
            SDL_FreeSurface(surface);
            SDL_DestroyTexture(texture);
        }
    }
}

void Sprite_Free(Sprite * sprite)
{
    SDL_DestroyTexture(sprite->texture);
}


bool Sprite_IsAnimationEnd(Sprite * sprite)
{
    return (sprite->indexFrame == 0)? true : false;
}
