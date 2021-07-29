//
//  Play.c
//  ShootThemUp
//
//  Created by El-idrissi Elyas on 26/11/2019.
//  Copyright © 2019 El-idrissi Elyas. All rights reserved.
//
//---------------------[]--------------------//
//-------------------------------------------[]-------------------------------------------//

#include "Play.h"

void Play_Update(Play * play, Singleton * o)
{
    //----------------------------------[Init New Elements]-----------------------------------//
    
    //---------------------[Enemies]--------------------//
    
    if(play->summonedEnemy < play->enemyPerLevel && !play->inMenuDead)
    {
        if((Utils_Random_Int(0, 200) == 0 || array_size(o->enemy) == 0) && array_size(o->enemy) < 15 && play->summonedEnemy < play->enemyPerLevel)
        {
            Singleton_AddEnemy(o, LevelManager_NewEnemy(o, EnemyNormal, play->level - 1));
            play->summonedEnemy += 1;
        }
        if(Utils_Random_Int(0, 1000) == 0  && array_size(o->enemy) < play->enemyPerLevel && play->summonedEnemy < play->enemyPerLevel)
        {
            int nbr = Utils_Random_Int(3, 5);
            for(int i = 0; i < nbr && play->summonedEnemy < play->enemyPerLevel; i++)
            {
                Singleton_AddEnemy(o, LevelManager_NewEnemy(o, EnemySoldier, play->level - 1));
                play->summonedEnemy += 1;
            }
        }
        if(Utils_Random_Int(0, 400) == 0 && play->summonedEnemy < play->enemyPerLevel)
        {
            int type = Utils_Random_Int(1, 5);
            Singleton_AddEnemy(o, LevelManager_NewEnemy(o, type, play->level - 1));
            play->summonedEnemy += 1;
        }
    }
    
    //-----------------------------------[Update Elements]------------------------------------//
    
    Star_Generate(o, false);
    Star_UpdateAll(o);
    
    //---------------------[Bullets]--------------------//
    for(int i = 0; i < array_size(o->bullets); i++)
    {
        Bullet * bullet = array_get_at(o->bullets, i);
        
        if(bullet)
        {
            Bullet_InMovePosUpdate(bullet);
            
            if(Bullet_IsOutOff(bullet, 0, 0, o->window.w, o->window.h))
            {
                Singleton_FreeBullet(o, i);
                bullet = NULL;
                i--;
            }
        }
    }
    
    //---------------------[Players]--------------------//
    
    if(o->player && o->player->spaceship)
    {
        Spaceship_Update(o->player->spaceship, PLAYER, o);
        Player_ActionOnSpaceship(o->player, o->event.KeyStates, o);
        Player_AutoActionOnSpaceship(o->player, o);
    }

    //---------------------[Enemies]--------------------//
    
    Singleton_ZindexOnEnemy(o->enemy, 0, (int)(array_size(o->enemy) - 1));
    
    for(int i = 0; i < array_size(o->enemy); i++)
    {
        Enemy * enemy = array_get_at(o->enemy, i);
        
        if(enemy && enemy->spaceship)
        {
            Spaceship_Update(enemy->spaceship, ENEMY, o);
            Enemy_AutoActionOnSpaceship(enemy, o);
            
            if(enemy->spaceship->y > o->window.h || enemy->spaceship->x + enemy->spaceship->w < 0 || enemy->spaceship->x > o->window.h)
            {
                if(o->player->spaceship)
                {
                    Spaceship_SetDamage(o->player->spaceship, enemy->spaceship->totalLife);
                    
                    if(Spaceship_GotNoLife(o->player->spaceship))
                    {
                        Singleton_AddExplosion(o, Explosion_New((o->player->spaceship->w + o->player->spaceship->h), 0, o->player->spaceship->x + o->player->spaceship->w/2, o->player->spaceship->y + o->player->spaceship->h/2, NOTEAM, &o->tm));
                        
                        Spaceship_Free(o->player->spaceship);
                        o->player->spaceship = NULL;
                        play->inMenuDead = true;
                    }
                }
                
                Singleton_FreeEnemy(o, i);
                enemy = NULL;
                i--;
                
                if(!Spaceship_GotNoLife(o->player->spaceship))
                {
                    o->player->missed += 1;
                    play->destroyedEnemy += 1;
                }
            }
        }
    }
    
    //--------------------[Explosions]-------------------//
    for(int i = 0; i < array_size(o->explosions); i++)
    {
        Explosion * explosion = array_get_at(o->explosions, i);
        
        if(explosion)
        {
            Explosion_Anime(explosion);
            if(Sprite_IsAnimationEnd(&explosion->sprite))
            {
                Singleton_FreeExplosion(o, i);
                explosion = NULL;
                i--;
            }
        }
    }
    
    //--------------------------------------[Collision]---------------------------------------//
    
    //-----[Bullets]-----//
    for(int i1 = 0; i1 < array_size(o->bullets); i1++)
    {
        //-----[Players Bullets WITH Enemies SpaceShips]-----//
        for(int i2 = 0; i2 < array_size(o->enemy); i2++)
        {
            Bullet * bullet = array_get_at(o->bullets, i1);
            Enemy * enemy = array_get_at(o->enemy, i2);
            
            if(bullet && bullet->teamType == PLAYER && enemy && enemy->spaceship)
            {
                //--[If no Shield AND collision with Spaceship]--//
                if(!Shield_isActivated(enemy->spaceship->shield) && Utils_Collision_isBulletInCollisionWithSpaceship(bullet, enemy->spaceship))
                {
                    Singleton_AddExplosion(o, Explosion_New(20, 0, bullet->x + bullet->w/2, bullet->y + bullet->h/2, NOTEAM, &o->tm));
                    
                    //--[If Bullet no Effect]--//
                    if(bullet->effectType == NoBulletEffect)
                    {
                        Spaceship_SetDamage(enemy->spaceship, bullet->damage);
                        
                        if(Spaceship_GotNoLife(enemy->spaceship))
                        {
                            Singleton_AddExplosion(o, Explosion_New((enemy->spaceship->w + enemy->spaceship->h), 0, enemy->spaceship->x + enemy->spaceship->w/2, enemy->spaceship->y + enemy->spaceship->h/2, NOTEAM, &o->tm));
                            
                            Singleton_FreeEnemy(o, i2);
                            enemy = NULL;
                            i2--;

                            o->player->score += 1;
                            play->destroyedEnemy += 1;
                            play->destroyedEnemyByPlayer +=1;
                        }
                    }
                    //--[If Bullet ExplosiveEffect]--//
                    if(bullet->effectType == ExplosiveEffect)
                    {
                        Explosion * explosion = Explosion_New(400, bullet->damage, bullet->x + bullet->w/2, bullet->y + bullet->h/2, PLAYER, &o->tm);
                        
                        for(int i3 = 0; i3 < array_size(o->enemy); i3++)
                        {
                            Enemy * enemy2 = array_get_at(o->enemy, i3);
                            
                            if(enemy2 && enemy2->spaceship && Utils_Collision_isExplosionInCollisionWithSpaceship(explosion, enemy2->spaceship))
                            {
                                Spaceship_SetDamage(enemy2->spaceship, bullet->damage);
                                
                                if(Spaceship_GotNoLife(enemy2->spaceship))
                                {
                                    Singleton_AddExplosion(o, Explosion_New((enemy2->spaceship->w + enemy2->spaceship->h), 0, enemy2->spaceship->x + enemy2->spaceship->w/2, enemy2->spaceship->y + enemy2->spaceship->h/2, NOTEAM, &o->tm));
                                    
                                    Singleton_FreeEnemy(o, i3);
                                    enemy2 = NULL;
                                    i3--;
                                    i2--;
                                
                                    o->player->score += 1;
                                    play->destroyedEnemy += 1;
                                    play->destroyedEnemyByPlayer +=1;
                                }
                            }
                        }
                        Singleton_AddExplosion(o, explosion);
                    }
                    
                    Singleton_FreeBullet(o, i1);
                    bullet = NULL;
                    i1--;
                }
                //--[If Shield] AND collision with Shield]--//
                else if(Shield_isActivated(enemy->spaceship->shield) && Utils_Collision_isBulletInCollisionWithShield(bullet, enemy->spaceship->shield))
                {
                    Singleton_AddExplosion(o, Explosion_New(20, 0, bullet->x + bullet->w/2, bullet->y + bullet->h/2, NOTEAM, &o->tm));
                    
                    //--[If Bullet no Effect]--//
                    if(bullet->effectType == NoBulletEffect)
                    {
                        Shield_AddDamage(enemy->spaceship->shield, bullet->damage);
                    }
                    //--[If Bullet ExplosiveEffect]--//
                    if(bullet->effectType == ExplosiveEffect)
                    {
                        Explosion * explosion = Explosion_New(400, bullet->damage, bullet->x + bullet->w/2, bullet->y + bullet->h/2, PLAYER, &o->tm);
                        
                        for(int i3 = 0; i3 < array_size(o->enemy); i3++)
                        {
                            Enemy * enemy2 = array_get_at(o->enemy, i3);
                            
                            if(enemy2 && enemy2->spaceship && Utils_Collision_isExplosionInCollisionWithShield(explosion, enemy2->spaceship->shield))
                            {
                                Shield_AddDamage(enemy2->spaceship->shield, explosion->damage);
                            }
                        }
                        Singleton_AddExplosion(o, explosion);
                    }
                    
                    Singleton_FreeBullet(o, i1);
                    bullet = NULL;
                    i1--;
                    
                }
            }
        }
        
        //-----[Enemies Bullets WITH Players SpaceShips]-----//
        
        Bullet * bullet = array_get_at(o->bullets, i1);
        
        if(bullet && bullet->teamType == ENEMY && o->player && o->player->spaceship)
        {
            //--[If no Shield AND collision with Spaceship]--//
            if(!Shield_isActivated(o->player->spaceship->shield) && Utils_Collision_isBulletInCollisionWithSpaceship(bullet, o->player->spaceship))
            {
                Singleton_AddExplosion(o, Explosion_New(20, 0, bullet->x + bullet->w/2, bullet->y + bullet->h/2, NOTEAM, &o->tm));
                
                //--[If Bullet no Effect]--//
                if(bullet->effectType == NoBulletEffect)
                {
                    Spaceship_SetDamage(o->player->spaceship, bullet->damage);
                    
                    if(Spaceship_GotNoLife(o->player->spaceship))
                    {
                        Singleton_AddExplosion(o, Explosion_New((o->player->spaceship->w + o->player->spaceship->h), 0, o->player->spaceship->x + o->player->spaceship->w/2, o->player->spaceship->y + o->player->spaceship->h/2, NOTEAM, &o->tm));
                        
                        Spaceship_Free(o->player->spaceship);
                        o->player->spaceship = NULL;
                        play->inMenuDead = true;
                    }
                }
                //--[If Bullet ExplosiveEffect]--//
                if(bullet->effectType == ExplosiveEffect)
                {
                    Explosion * explosion = Explosion_New(400, bullet->damage, bullet->x + bullet->w/2, bullet->y + bullet->h/2, ENEMY, &o->tm);

                    if(o->player && o->player->spaceship && Utils_Collision_isExplosionInCollisionWithSpaceship(explosion, o->player->spaceship))
                    {
                        Spaceship_SetDamage(o->player->spaceship, bullet->damage);
                        
                        if(Spaceship_GotNoLife(o->player->spaceship))
                        {
                            Singleton_AddExplosion(o, Explosion_New((o->player->spaceship->w + o->player->spaceship->h), 0, o->player->spaceship->x + o->player->spaceship->w/2, o->player->spaceship->y + o->player->spaceship->h/2, NOTEAM, &o->tm));
                            
                            Spaceship_Free(o->player->spaceship);
                            o->player->spaceship = NULL;
                            play->inMenuDead = true;
                        }
                    }
                    
                    Singleton_AddExplosion(o, explosion);
                }
                
                Singleton_FreeBullet(o, i1);
                bullet = NULL;
                
                i1--;
            }
            //--[If Shield] AND collision with Shield]--//
            else if(Shield_isActivated(o->player->spaceship->shield) && Utils_Collision_isBulletInCollisionWithShield(bullet, o->player->spaceship->shield))
            {
                Singleton_AddExplosion(o, Explosion_New(20, 0, bullet->x + bullet->w/2, bullet->y + bullet->h/2, NOTEAM, &o->tm));
                
                //--[If Bullet no Effect]--//
                if(bullet->effectType == NoBulletEffect)
                {
                    Shield_AddDamage(o->player->spaceship->shield, bullet->damage);
                }
                //--[If Bullet ExplosiveEffect]--//
                if(bullet->effectType == ExplosiveEffect)
                {
                    Explosion * explosion = Explosion_New(400, bullet->damage, bullet->x + bullet->w/2, bullet->y + bullet->h/2, ENEMY, &o->tm);
                    
                    if(o->player && o->player->spaceship && Utils_Collision_isExplosionInCollisionWithShield(explosion, o->player->spaceship->shield))
                    {
                        Shield_AddDamage(o->player->spaceship->shield, explosion->damage);
                    }
                    
                    Singleton_AddExplosion(o, explosion);
                }
                
                Singleton_FreeBullet(o, i1);
                bullet = NULL;
                i1--;
                
            }
        }
    }
    
    if(Event_IsMouseDown(&o->event))
    {
        if(Utils_Collision_AABB(o->play.buttonPause.x, o->play.buttonPause.y, o->play.buttonPause.w, o->play.buttonPause.h, o->event.Xmouse, o->event.Ymouse, 4, 4))
        {
            play->inMenuPause = true;
        }
    }
    
    if(play->inMenuDead)
    {
        MenuDead_Update(&o->menuDead, o);
    }
    if(play->isNextLevelMessage)
    {
        play->nextLevelMessageTimeLife -= 0.1;
        
        if(play->nextLevelMessageTimeLife <= 0)
        {
            play->nextLevelMessageTimeLife = PRIVATE_Play_nextLevelMessageTimeLife;
            play->isNextLevelMessage = false;
        }
    }
    
    Play_CheckForNextLevel(play, o);
}

void Play_Draw(Play * play, Singleton * o)
{
    Sprite_Draw(&play->background, -90, 0, 0,&o->window);
    Star_DrawAll(o);
    
    Player_DrawSpaceship(o->player, &o->window, o);
    
    for(int i = 0; i < array_size(o->enemy); i++)
    {
        Enemy * enemy = array_get_at(o->enemy, i);
        Enemy_DrawSpaceship(enemy, &o->window, o);
    }
    
    for(int i = 0; i < array_size(o->bullets); i++)
    {
        Bullet_Draw(array_get_at(o->bullets, i), &o->window);
    }
    
    for(int i = 0; i < array_size(o->explosions); i++)
    {
        Explosion_Draw(array_get_at(o->explosions, i), &o->window);
    }
    
    PlayerBar_Update(&o->playerBar, o->player);
    PlayerBar_Draw(&o->playerBar, &o->window);
    
    if(play->inMenuDead)
    {
        MenuDead_Draw(&o->menuDead, &o->window, o->player, &o->tm, o);
    }
    
    char str[1024];
    memset(str, 0, sizeof str);
    sprintf(str, "%d", o->play.level);
    Text_Draw(str, o->window.w - 70,  play->yPlayerBar + 45, TextRight, 30, "PixelFont", Utils_Color_Get(255, 255, 255), &o->window, &o->tm);

    memset(str, 0, sizeof str);
    sprintf(str, "%d%%", (int)(((float)o->play.summonedEnemy/(float)o->play.enemyPerLevel)*100.0));
    Text_Draw(str, 794,  play->yPlayerBar + 50, TextRight, 20, "PixelFont", Utils_Color_Get(255, 255, 255), &o->window, &o->tm);
    
    memset(str, 0, sizeof str);
    sprintf(str, "%lld", o->player->argent);
    Text_Draw(str, 150,  play->yPlayerBar + 53, TextRight, 19, "PixelFont", Utils_Color_Get(255, 255, 255), &o->window, &o->tm);
    
    if(play->isNextLevelMessage)
    {
        if(play->level == 1)
        {
            memset(str, 0, sizeof str);
            sprintf(str, "Level %d", play->level);
            Text_Draw(str, o->menuDead.background.x + o->menuDead.background.w/2, o->menuDead.background.y + 130, TextCenter, 60, "PixelFont", Utils_Color_Get(255, 80, 80), &o->window, &o->tm);
        }
        else
        {
            memset(str, 0, sizeof str);
            sprintf(str, "LEVEL %d SUCCESSED",  o->play.levelOld);
            Text_Draw(str, o->menuDead.background.x + o->menuDead.background.w/2, o->menuDead.background.y + 50, TextCenter, 45, "PixelFont", Utils_Color_Get(255, 255, 255), &o->window, &o->tm);
        
            memset(str, 0, sizeof str);
            sprintf(str, "%d kill | %d missed", play->destroyedEnemyByPlayerOld, play->destroyedEnemyOld - play->destroyedEnemyByPlayerOld);
            Text_Draw(str, o->menuDead.background.x + o->menuDead.background.w/2, o->menuDead.background.y + 130, TextCenter, 30, "PixelFont", Utils_Color_Get(255, 255, 255), &o->window, &o->tm);
        
            memset(str, 0, sizeof str);
            sprintf(str, "Level %d",  o->play.levelOld + 1);
            Text_Draw(str, o->menuDead.background.x + o->menuDead.background.w/2, o->menuDead.background.y + 190, TextCenter, 60, "PixelFont", Utils_Color_Get(255, 80, 80), &o->window, &o->tm);
        }
    }
    
    Sprite_Draw(&play->barTop, -90, play->barTop.x, play->barTop.y, &o->window);
    Sprite_Draw(&play->barBottom, -90, play->barBottom.x, play->barBottom.y, &o->window);
    Sprite_Draw(&play->buttonPause, -90, play->buttonPause.x, play->buttonPause.y, &o->window);
    
    Sprite coeur = Sprite_New(4 , o->window.h - 4 - 8, 0, 0, "coeur", &o->tm);
    Sprite_Draw(&coeur, -90, 0, 0, &o->window);
}

void Play_SetPlayerSpaceshipPosInDefault(Play * play, Spaceship * spaceship)
{
    Spaceship_SetPos(spaceship, play->xPlayerSpaceship - spaceship->w/2, play->yPlayerSpaceship - spaceship->h - 60);
}

void Play_Reset(Singleton * o)
{
    o->player->score = 0;
    o->play.level = 1;
    o->play.destroyedEnemy = 0;
    o->play.summonedEnemy = 0;
    o->play.destroyedEnemyByPlayer = 0;
    o->play.inMenuDead = false;
    o->play.isNextLevelMessage = true;
    
    if(!o->player->spaceship)
    {
        o->player->spaceship = Spaceship_New(o->player->equipedEquipement[0], 0, 0, o->player->equipedEquipement[0], o->player->equipedEquipement[1], o->player->equipedEquipement[2], o->player->equipedEquipement[3], o->player->equipedEquipement[4], o->player->equipedEquipement[5], o->player->equipedEquipement[6], o);
        Play_SetPlayerSpaceshipPosInDefault(&o->play, o->player->spaceship);
    }
    
    Play_DestroyedAllEnemy(o);
    Play_DestroyedAllBullet(o);
    Star_FreeAll(o);
    Star_Generate(o, true);
}

void Play_DestroyedAllEnemy(Singleton * o)
{
    for(int i = 0; i < array_size(o->enemy); i++)
    {
        Singleton_FreeEnemy(o, i);
        i--;
    }
}

void Play_DestroyedAllBullet(Singleton * o)
{
    for(int i = 0; i < array_size(o->bullets); i++)
    {
        Singleton_FreeBullet(o, i);
        i--;
    }
}


void Play_CheckForNextLevel(Play * play, Singleton * o)
{
    if(play->summonedEnemy == play->enemyPerLevel && play->destroyedEnemy == play->enemyPerLevel && o->player->spaceship)
    {
        o->player->spaceship->totalLife += (float)o->player->spaceship->totalLifeMax / 3.0;
        if(o->player->spaceship->totalLife > o->player->spaceship->totalLifeMax) o->player->spaceship->totalLife = o->player->spaceship->totalLifeMax;
        
        o->player->argent += (11.9312*powf(1.02871, (float)play->level) - 2.26)*((float)o->play.destroyedEnemyByPlayer/(float)o->play.summonedEnemy);
        
        play->levelOld = play->level;
        o->play.destroyedEnemyOld = o->play.destroyedEnemy;
        o->play.summonedEnemyOld = o->play.summonedEnemy;
        o->play.destroyedEnemyByPlayerOld = o->play.destroyedEnemyByPlayer;
        
        play->level += 1;
        o->play.destroyedEnemy = 0;
        o->play.summonedEnemy = 0;
        o->play.destroyedEnemyByPlayer = 0;
        play->isNextLevelMessage = true;
    }
}
