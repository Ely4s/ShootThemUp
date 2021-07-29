//
//  TextureManager.h
//  ShootThemUp
//
//  Created by El-idrissi Elyas on 26/11/2019.
//  Copyright © 2019 El-idrissi Elyas. All rights reserved.
//

#ifndef TextureManager_h
#define TextureManager_h

#include "main.h"

static const int PRIVATE_TextureManager_textureKeyMaxSize = 32;
static char PRIVATE_TextureManager_errorTextureNull[] = "Error";
static char PRIVATE_TextureManager_errorTexturePath[] = "NoPath";
static char PRIVATE_TextureManager_errorTextureId[] = "NoId";
static char PRIVATE_TextureManager_FontFolderPath[] = "Resources/Font/";

void TextureManager_AddTexture(TextureManager * tm, char * strPath, char * strKey, int w, int h, int nbrOfFrame, SDL_Renderer * renderer);
void TextureManager_LoadTextures(TextureManager * tm, SDL_Renderer * renderer);
SDL_Texture * TextureManager_GetTexture(TextureManager * tm, char * strKey);
bool TextureManager_isTextureLoad(TextureManager * tm, char * strKey);
bool TextureManager_isTextureAnimated(TextureManager * tm, char * strKey);
int TextureManager_GetTextureFrameW(TextureManager * tm, char * strKey);
int TextureManager_GetTextureFrameH(TextureManager * tm, char * strKey);
int TextureManager_GetTextureNbrOfFrame(TextureManager * tm, char * strKey);


void TextureManager_LoadFonts(TextureManager * tm);
void TextureManager_AddFont(TextureManager * tm, char * strKey, int fontSize);
TTF_Font * TextureManager_GetFont(TextureManager * tm, char * strKey, int fontSize);
bool TextureManager_isFontLoad(TextureManager * tm, char * strKey);

void TextureManager_Free(TextureManager * tm);

#endif /* TextureManager_h */
