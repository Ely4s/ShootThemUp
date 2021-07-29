//
//  Text.h
//  ShootThemUp
//
//  Created by El-idrissi Elyas on 28/11/2019.
//  Copyright © 2019 El-idrissi Elyas. All rights reserved.
//

#ifndef Text_h
#define Text_h

#include "main.h"

#include "TextureManager.h"

void Text_Draw(char * str, int x, int y, TextAlign textAlign, int size, char * fontStr, SDL_Color color, Window * window, TextureManager * tm);


#endif /* Text_h */
