//
//  Singleton.c
//  ShootThemUp
//
//  Created by El-idrissi Elyas on 02/12/2019.
//  Copyright © 2019 El-idrissi Elyas. All rights reserved.
//

#include "Singleton.h"

void Singleton_InitAll(Singleton * o)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    SDL_SetHint(SDL_HINT_VIDEO_MAC_FULLSCREEN_SPACES, "0");
    
    Window window = Window_New("Shoot Them Up", 500, 830);
    Window_SetBackgroundColor(&window, Utils_Color_Get(0, 0, 0));

    Event e = {0};
    e.mouseCanClick = 1;
    
    Game g;
    Game_SetFps(&g, 60);
    
    Play p = {0};
    
    TextureManager tm;
    TextureManager_LoadTextures(&tm, window.renderer);
    TextureManager_LoadFonts(&tm);
    
    PatternManager pm;
    PatternManager_LoadTextures(&pm, &tm);
    
    LevelManager lm = {0};
    
    array_new(&o->bullets);
    array_new(&o->texts);
    array_new(&o->enemy);
    array_new(&o->explosions);
    array_new(&o->starsFar);
    array_new(&o->starsMidway);
    array_new(&o->starsNear);
    
    o->event = e;
    o->window = window;
    o->game = g;
    o->play = p;
    o->tm = tm;
    o->pm = pm;
    o->lm = lm;
    
    Star_Generate(o, true);
    
    o->play.xPlayerBar = 0;
    o->play.yPlayerBar = o->window.h - 160;
    
    o->playerBar = PlayerBar_New(o->play.xPlayerBar, o->play.yPlayerBar, o);
    
    o->play.xPlayerSpaceship = o->window.w/2;
    o->play.yPlayerSpaceship = o->play.yPlayerBar;
    
    o->play.barBottom = Sprite_New(0, 0, 0, 0, "BarBottom", &o->tm);
    o->play.barTop = Sprite_New(0, 0, 0, 0, "BarTop", &o->tm);
    o->play.barBottom.y = window.h - o->play.barBottom.h;
    o->play.background = Sprite_New(0, 0, 0, 0, "PlayBackground", &o->tm);
    o->play.buttonPause = Sprite_New(window.w - 120, 20, 0, 0, "ButtonPause", &o->tm);
    
    Player * player = Player_NewDefault(0, 0);
    Spaceship * spaceship = Spaceship_New(SpaceshipTier1, 0, 0, BodyTier1, ReactorTier1, ReactorTier1, WeaponTier1, WeaponTier1, TurretTier1, ShieldTier1, o);
    spaceship->totalLife = 10;
    if(spaceship) Play_SetPlayerSpaceshipPosInDefault(&o->play, spaceship);
    Player_SetSpaceship(player, spaceship);
    Singleton_AddPlayer(o, player);
    
    o->shop = Shop_New(o);
    o->shop.xCaseSelected = -1;
    o->shop.yCaseSelected = -1;
    Shop_InitShopEquipement(&o->shop, o);
    
    o->menuDead = MenuDead_New(&o->tm);
    o->menuPause = MenuPause_New(&o->tm);
    
    o->game.gamePhase = ShopPhase;
    o->play.inMenuDead = false;
    o->play.inMenuPause = false;
    o->play.level = 1;
    o->play.summonedEnemy = 0;
    o->play.destroyedEnemy = 0;
    o->play.destroyedEnemyByPlayer = 0;
    o->play.enemyPerLevel = 25;
    o->play.nextLevelMessageTimeLife = PRIVATE_Play_nextLevelMessageTimeLife;
    o->play.isNextLevelMessage = true;
    
    o->lm.levelUnit = 100;
    o->lm.multiDefault = 1;
    o->lm.multiLife = 0.028;
    o->lm.multiSpeed = 0.5;
}

void Singleton_AddPlayer(Singleton * o, Player * player)
{
    if(o && player) o->player = player;
}

void Singleton_AddText(Singleton * o, Text * text)
{
    if(o && text) array_add(o->texts, (void*)text);
}

void Singleton_AddBullet(Singleton * o, Bullet * bullet)
{
    if(o && bullet) array_add(o->bullets, (void*)bullet);
}

void Singleton_AddEnemy(Singleton * o, Enemy * enemy)
{
    if(o && enemy) array_add(o->enemy, (void*)enemy);
}

void Singleton_AddExplosion(Singleton * o, Explosion * explosion)
{
    if(o && explosion) array_add(o->explosions, (void*)explosion);
}

void Singleton_FreePlayer(Singleton * o)
{
    Player_Free(o->player);
    o->player = NULL;
}

void Singleton_FreeText(Singleton * o, int it)
{
    if(o)
    {
//        Text * text = array_get_at(o->texts, it);
//        array_remove_at(o->texts, it, NULL);
//        Text_Free(text);
    }
}

void Singleton_FreeBullet(Singleton * o, int it)
{
    if(o)
    {
        Bullet * bullet = array_get_at(o->bullets, it);
        array_remove_at(o->bullets, it, NULL);
        Bullet_Free(bullet);
        bullet = NULL;
    }
}

void Singleton_FreeEnemy(Singleton * o, int it)
{
    if(o)
    {
        Enemy * enemy = array_get_at(o->enemy, it);
        array_remove_at(o->enemy, it, NULL);
        Enemy_Free(enemy);
        enemy = NULL;
    }
}

void Singleton_FreeExplosion(Singleton * o, int it)
{
    if(o)
    {
        Explosion * explosion = array_get_at(o->explosions, it);
        array_remove_at(o->explosions, it, NULL);
        Explosion_Free(explosion);
        explosion = NULL;
    }
}


void Singleton_Free(Singleton * o)
{
    array_remove_all_free(o->bullets);
    Singleton_FreePlayer(o);
    array_remove_all_free(o->texts);
    array_remove_all_free(o->enemy);
    array_remove_all_free(o->explosions);
    
    SDL_Quit();
    TTF_Quit();
}

int valueAt(Array * array, int at)
{
    Enemy * enemy = array_get_at(array, at);
    return (enemy->spaceship->y + enemy->spaceship->h/2);
}

void swap(Enemy * a, Enemy * b)
{
    Enemy t = *a;
    *a = *b;
    *b = t;
}

int partition (Array * array, int low, int high)
{
    int pivot = valueAt(array, high);
    int i = (low - 1);
    
    for (int j = low; j <= high- 1; j++)
    {
        if (valueAt(array, j) <= pivot)
        {
            i++;
            swap(array_get_at(array, i), array_get_at(array, j));
        }
    }
    swap(array_get_at(array, i + 1), array_get_at(array, high));
    return (i + 1);
}

void Singleton_ZindexOnEnemy(Array * array, int low, int high)
{
    if (low < high)
    {
        int pi = partition(array, low, high);
        
        Singleton_ZindexOnEnemy(array, low, pi - 1);
        Singleton_ZindexOnEnemy(array, pi + 1, high);
    }
}
