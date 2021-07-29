//
//  TextureManager.c
//  ShootThemUp
//
//  Created by El-idrissi Elyas on 26/11/2019.
//  Copyright © 2019 El-idrissi Elyas. All rights reserved.
//

#include "TextureManager.h"

//---------------------------------------[Texture]----------------------------------------//

void TextureManager_LoadTextures(TextureManager * tm, SDL_Renderer * renderer)
{
    map_init(&tm->allSpriteSheet);
    
    TextureManager_AddTexture(tm, "Resources/coeur.png", "coeur", 8, 8, 1, renderer);
    
    //-----------------[Spaceship]----------------//
    TextureManager_AddTexture(tm, "Resources/Texture/Equipement/Spaceship/spaceship_tier_1_idle.png", "spaceship_tier_1_idle", 110, 48, 1, renderer);
    TextureManager_AddTexture(tm, "Resources/Texture/Equipement/Spaceship/spaceship_tier_2_idle.png", "spaceship_tier_2_idle", 90, 94, 1, renderer);
    TextureManager_AddTexture(tm, "Resources/Texture/Equipement/Spaceship/spaceship_tier_3_idle.png", "spaceship_tier_3_idle", 158, 128, 1, renderer);
    TextureManager_AddTexture(tm, "Resources/Texture/Equipement/Spaceship/spaceship_tier_4_idle.png", "spaceship_tier_4_idle", 150, 166, 1, renderer);
    TextureManager_AddTexture(tm, "Resources/Texture/Equipement/Spaceship/spaceship_tier_5_idle.png", "spaceship_tier_5_idle", 230, 200, 1, renderer);

    //------------------[Reactor]-----------------//
    TextureManager_AddTexture(tm, "Resources/Texture/Equipement/Reactor/reactor_tier_1_idle.png", "reactor_tier_1_idle", 14, 10, 1, renderer);
    TextureManager_AddTexture(tm, "Resources/Texture/Equipement/Reactor/reactor_tier_2_idle.png", "reactor_tier_2_idle", 18, 22, 1, renderer);
    TextureManager_AddTexture(tm, "Resources/Texture/Equipement/Reactor/reactor_tier_3_idle.png", "reactor_tier_3_idle", 22, 30, 1, renderer);
    TextureManager_AddTexture(tm, "Resources/Texture/Equipement/Reactor/reactor_tier_4_idle.png", "reactor_tier_4_idle", 22, 42, 1, renderer);
    TextureManager_AddTexture(tm, "Resources/Texture/Equipement/Reactor/reactor_tier_5_idle.png", "reactor_tier_5_idle", 50, 60, 1, renderer);
    
    //-----------------[WeaponMain]---------------//
    TextureManager_AddTexture(tm, "Resources/Texture/Equipement/WeaponMain/weaponMain_tier_1_idle.png", "weaponMain_tier_1_idle", 10, 16, 1, renderer);
    TextureManager_AddTexture(tm, "Resources/Texture/Equipement/WeaponMain/weaponMain_tier_2_idle.png", "weaponMain_tier_2_idle", 14, 24, 1, renderer);
    TextureManager_AddTexture(tm, "Resources/Texture/Equipement/WeaponMain/weaponMain_tier_3_idle.png", "weaponMain_tier_3_idle", 14, 30, 1, renderer);
    TextureManager_AddTexture(tm, "Resources/Texture/Equipement/WeaponMain/weaponMain_tier_4_idle.png", "weaponMain_tier_4_idle", 26, 38, 1, renderer);
    TextureManager_AddTexture(tm, "Resources/Texture/Equipement/WeaponMain/weaponMain_tier_5_idle.png", "weaponMain_tier_5_idle", 38, 54, 1, renderer);
    
    //--------------[WeaponSecondary]-------------//
    TextureManager_AddTexture(tm, "Resources/Texture/Equipement/WeaponSecondary/weaponSecondary_tier_1_idle.png", "weaponSecondary_tier_1_idle", 8, 40, 1, renderer);
    TextureManager_AddTexture(tm, "Resources/Texture/Equipement/WeaponSecondary/weaponSecondary_tier_2_idle.png", "weaponSecondary_tier_2_idle", 8, 54, 1, renderer);
    TextureManager_AddTexture(tm, "Resources/Texture/Equipement/WeaponSecondary/weaponSecondary_tier_3_idle.png", "weaponSecondary_tier_3_idle", 12, 54, 1, renderer);
    TextureManager_AddTexture(tm, "Resources/Texture/Equipement/WeaponSecondary/weaponSecondary_tier_4_idle.png", "weaponSecondary_tier_4_idle", 12, 60, 1, renderer);
    TextureManager_AddTexture(tm, "Resources/Texture/Equipement/WeaponSecondary/weaponSecondary_tier_5_idle.png", "weaponSecondary_tier_5_idle", 12, 72, 1, renderer);

    //-------------------[Turret]-----------------//
    TextureManager_AddTexture(tm, "Resources/Texture/Equipement/Turret/turret_tier_1_idle.png", "turret_tier_1_idle", 18, 22, 1, renderer);
    TextureManager_AddTexture(tm, "Resources/Texture/Equipement/Turret/turret_tier_2_idle.png", "turret_tier_2_idle", 26, 30, 1, renderer);
    TextureManager_AddTexture(tm, "Resources/Texture/Equipement/Turret/turret_tier_3_idle.png", "turret_tier_3_idle", 30, 42, 1, renderer);
    TextureManager_AddTexture(tm, "Resources/Texture/Equipement/Turret/turret_tier_4_idle.png", "turret_tier_4_idle", 30, 56, 1, renderer);
    TextureManager_AddTexture(tm, "Resources/Texture/Equipement/Turret/turret_tier_5_idle.png", "turret_tier_5_idle", 30, 74, 1, renderer);
    
    //-------------------[Shield]-----------------//
    TextureManager_AddTexture(tm, "Resources/Texture/Equipement/Shield/shield_tier_1_idle.png", "shield_tier_1_idle", 318, 48, 6, renderer);
    TextureManager_AddTexture(tm, "Resources/Texture/Equipement/Shield/shield_tier_2_idle.png", "shield_tier_2_idle", 318, 48, 6, renderer);
    TextureManager_AddTexture(tm, "Resources/Texture/Equipement/Shield/shield_tier_3_idle.png", "shield_tier_3_idle", 318, 48, 6, renderer);
    TextureManager_AddTexture(tm, "Resources/Texture/Equipement/Shield/shield_tier_4_idle.png", "shield_tier_4_idle", 318, 48, 6, renderer);
    TextureManager_AddTexture(tm, "Resources/Texture/Equipement/Shield/shield_tier_5_idle.png", "shield_tier_5_idle", 318, 48, 6, renderer);
    
    //-------------------[Bullet]------------------//
    TextureManager_AddTexture(tm, "Resources/Texture/Equipement/Bullet/BulletMainWeapon.png", "BulletMainWeapon", 10, 13, 2, renderer);
    TextureManager_AddTexture(tm, "Resources/Texture/Equipement/Bullet/BulletSecondaryWeapon.png", "BulletSecondaryWeapon", 28, 52, 2, renderer);
    TextureManager_AddTexture(tm, "Resources/Texture/Equipement/Bullet/BulletTurret.png", "BulletTurret", 8, 9, 2, renderer);
    
    //-----------------[PlayerBar]-----------------//
    TextureManager_AddTexture(tm, "Resources/Texture/Gui/PlayerBar/PlayerBar.png", "PlayerBar", 1000, 118, 1, renderer);
    TextureManager_AddTexture(tm, "Resources/Texture/Gui/PlayerBar/BarShieldLife.png", "BarShieldLife", 382, 24, 1, renderer);
    TextureManager_AddTexture(tm, "Resources/Texture/Gui/PlayerBar/BarShieldTime.png", "BarShieldTime", 382, 14, 1, renderer);
    TextureManager_AddTexture(tm, "Resources/Texture/Gui/PlayerBar/BarLife.png", "BarLife", 382, 24, 1, renderer);
    TextureManager_AddTexture(tm, "Resources/Texture/Gui/PlayerBar/BarWeaponMainCooldown.png", "BarWeaponMainCooldown", 12, 96, 1, renderer);
    TextureManager_AddTexture(tm, "Resources/Texture/Gui/PlayerBar/BarSecondaryWeaponCooldown.png", "BarSecondaryWeaponCooldown", 12, 96, 1, renderer);
    TextureManager_AddTexture(tm, "Resources/Texture/Gui/PlayerBar/BarTurretCooldown.png", "BarTurretCooldown", 12, 96, 1, renderer);
    
    //--------------------[Shop]-------------------//
    TextureManager_AddTexture(tm, "Resources/Texture/Gui/Shop/ShopBackground.png", "ShopBackground", 1000, 1660, 1, renderer);
    TextureManager_AddTexture(tm, "Resources/Texture/Gui/Shop/ButtonPlay.png", "ButtonPlay", 80, 80, 1, renderer);
    TextureManager_AddTexture(tm, "Resources/Texture/Gui/Shop/ButtonCancel.png", "ButtonCancel", 80, 80, 1, renderer);
    TextureManager_AddTexture(tm, "Resources/Texture/Gui/Shop/SelectedCase.png", "SelectedCase", 84, 92, 1, renderer);
    
    //-------------------[Button]------------------//
    TextureManager_AddTexture(tm, "Resources/Texture/Gui/Button/ButtonSmall.png", "ButtonSmall", 102, 46, 1, renderer);
    TextureManager_AddTexture(tm, "Resources/Texture/Gui/Button/ButtonBig.png", "ButtonBig", 162, 70, 1, renderer);
    
    //---------------------[Div]-------------------//
    TextureManager_AddTexture(tm, "Resources/Texture/Gui/Div/DivSmall.png", "DivSmall", 595, 239, 1, renderer);
    TextureManager_AddTexture(tm, "Resources/Texture/Gui/Div/DivBig.png", "DivBig", 595, 344, 1, renderer);
    
    //-------------------[Effect]------------------//
    TextureManager_AddTexture(tm, "Resources/Texture/Effect/Explosion.png", "Explosion", 1200, 100, 12, renderer);
    TextureManager_AddTexture(tm, "Resources/Texture/Effect/BlackSmock.png", "BlackSmock", 1508, 168, 13, renderer);
    TextureManager_AddTexture(tm, "Resources/Texture/Effect/Flame.png", "Flame", 132, 56, 6, renderer);
    TextureManager_AddTexture(tm, "Resources/Texture/Effect/Star.png", "Star", 2, 2, 1, renderer);
    
    //--------------------[Play]-------------------//
    TextureManager_AddTexture(tm, "Resources/Texture/Gui/Play/BarTop.png", "BarTop", 1000, 52, 1, renderer);
    TextureManager_AddTexture(tm, "Resources/Texture/Gui/Play/BarBottom.png", "BarBottom", 1000, 52, 1, renderer);
    TextureManager_AddTexture(tm, "Resources/Texture/Gui/Play/ButtonPause.png", "ButtonPause", 80, 37, 1, renderer);
    TextureManager_AddTexture(tm, "Resources/Texture/Gui/Play/PlayBackground.png", "PlayBackground", 1000, 1660, 1, renderer);
}

void TextureManager_AddTexture(TextureManager * tm, char * strPath, char * strKey, int w, int h, int nbrOfFrame, SDL_Renderer * renderer)
{
    if(!strPath && !strKey)
    {
        if(DEBUG_TEXTURE_LOAD) printf("[ERROR__] Load Texture Fail : <NoPath> with Id <NoId> (Path and Id are missing)\n");
    }
    else if(!strPath)
    {
        if(DEBUG_TEXTURE_LOAD) printf("[ERROR__] Load Texture Fail : <NoPath> with Id \"%s\" (Path is missing)\n", strKey);
    }
    else if(!strKey)
    {
        if(DEBUG_TEXTURE_LOAD) printf("[ERROR__] Load Texture Fail : \"%s\" with Id <NoId> (Key is missing)\n", strPath);
    }
    else
    {
        if(!TextureManager_isTextureLoad(tm, strKey))
        {
            if(IMG_Load(strPath))
            {
                SDL_Surface * surface = IMG_Load(strPath);
                SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, surface);
                
                SpriteSheet spriteSheet;
                spriteSheet.texture = texture;
                spriteSheet.wFrame = w / nbrOfFrame;
                spriteSheet.hFrame = h;
                spriteSheet.nbrOfFrame = nbrOfFrame;
                
                map_set(&tm->allSpriteSheet, strKey, spriteSheet);
                
                if(DEBUG_TEXTURE_LOAD) printf("[SUCCES_] Load Texture Done : \"%s\" with Id \"%s\" \n", strPath, strKey);
            }
            else
            {
                if(DEBUG_TEXTURE_LOAD) printf("[ERROR__] Load Texture Fail : \"%s\" with Id \"%s\" (File Not Found)\n", strPath, strKey);
            }
        }
        else
        {
            if(DEBUG_TEXTURE_LOAD) printf("[WARNING] Load Texture Fail : \"%s\" with ID \"%s\" (Already Load)\n", strPath, strKey);
        }
    }
}

SDL_Texture * TextureManager_GetTexture(TextureManager * tm, char * strKey)
{
    if(tm)
    {
        if(strKey && map_get(&tm->allSpriteSheet, strKey))
        {
            SpriteSheet * spriteSheet = map_get(&tm->allSpriteSheet, strKey);
            return spriteSheet->texture;
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        return NULL;
    }
}

bool TextureManager_isTextureAnimated(TextureManager * tm, char * strKey)
{
    if(tm)
    {
        if(strKey && map_get(&tm->allSpriteSheet, strKey))
        {
            SpriteSheet * spriteSheet = map_get(&tm->allSpriteSheet, strKey);
            return spriteSheet->isAnimated;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

int TextureManager_GetTextureFrameW(TextureManager * tm, char * strKey)
{
    if(tm)
    {
        SpriteSheet * spriteSheet;
        
        if(strKey && map_get(&tm->allSpriteSheet, strKey))
        {
            spriteSheet = map_get(&tm->allSpriteSheet, strKey);
            return spriteSheet->wFrame;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

int TextureManager_GetTextureFrameH(TextureManager * tm, char * strKey)
{
    if(tm)
    {
        SpriteSheet * spriteSheet;
        
        if(strKey && map_get(&tm->allSpriteSheet, strKey))
        {
            spriteSheet = map_get(&tm->allSpriteSheet, strKey);
            return spriteSheet->hFrame;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

int TextureManager_GetTextureNbrOfFrame(TextureManager * tm, char * strKey)
{
    if(tm)
    {
        SpriteSheet * spriteSheet;
        
        if(strKey && map_get(&tm->allSpriteSheet, strKey))
        {
            spriteSheet = map_get(&tm->allSpriteSheet, strKey);
            return spriteSheet->nbrOfFrame;
        }
        else return 0;
    }
    else return 0;
}

bool TextureManager_isTextureLoad(TextureManager * tm, char * strKey)
{
    if(tm)
    {
        if(strKey && map_get(&tm->allSpriteSheet, strKey))  return true;
        else                                                return false;
    }
    else return false;
}

//-----------------------------------------[Font]-----------------------------------------//

void TextureManager_LoadFonts(TextureManager * tm)
{
    map_init(&tm->allFont);
}

void TextureManager_AddFont(TextureManager * tm, char * strKey, int fontSize)
{
    if(strKey)
    {
        char path[1024];
        sprintf(path, "%s%s.ttf", PRIVATE_TextureManager_FontFolderPath, strKey);
        
        TTF_Font * font = TTF_OpenFont(path, fontSize);
        
        if(font)
        {
            char strNewKey[1024];
            sprintf(strNewKey, "%s : %d", strKey, fontSize);
            
            map_set(&tm->allFont, strNewKey, font);
        }
    }
}

TTF_Font * TextureManager_GetFont(TextureManager * tm, char * strKey, int fontSize)
{
    char str[1024];
    sprintf(str, "%s : %d", strKey, fontSize);
    
    if(!TextureManager_isFontLoad(tm, str))
    {
        TextureManager_AddFont(tm, strKey, fontSize);
        TTF_Font ** font = map_get(&tm->allFont, str);
        
        if(font)    return *font;
        else        return NULL;
    }
    else return *map_get(&tm->allFont, str);
}

bool TextureManager_isFontLoad(TextureManager * tm, char * strKey)
{
    if(map_get(&tm->allFont, strKey) == NULL)   return false;
    else                                        return true;
}

void TextureManager_Free(TextureManager * tm)
{
    map_deinit(&tm->allSpriteSheet);
    map_deinit(&tm->allFont);
}
