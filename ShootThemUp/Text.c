//
//  Text.c
//  ShootThemUp
//
//  Created by El-idrissi Elyas on 28/11/2019.
//  Copyright © 2019 El-idrissi Elyas. All rights reserved.
//

#include "Text.h"

void Text_Draw(char * str, int x, int y, TextAlign textAlign, int size, char * fontStr, SDL_Color color, Window * window, TextureManager * tm)
{
    TTF_Font * font = TextureManager_GetFont(tm, fontStr, size);
    
    if(font)
    {
        SDL_Rect texr = {x, y, 0, 0};
        TTF_SizeUTF8(font, str, &texr.w, &texr.h);
    
        if(textAlign == TextCenter) texr.x -= texr.w/2;
        if(textAlign == TextRight)  texr.x -= texr.w;
    
        SDL_Surface * surface = TTF_RenderUTF8_Blended(font, str, color);
        SDL_Texture * texture = SDL_CreateTextureFromSurface(window->renderer, surface);
        SDL_RenderCopy(window->renderer, texture, NULL, &texr);
    
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(texture);
    }
}
