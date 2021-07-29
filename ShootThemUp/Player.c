//
//  Player.c
//  ShootThemUp
//
//  Created by El-idrissi Elyas on 01/12/2019.
//  Copyright © 2019 El-idrissi Elyas. All rights reserved.
//

#include "Player.h"
#include "Bullet.h"

Player * Player_NewDefault(float x, float y)
{
    Player * player = malloc(sizeof(Player));
    
    sprintf(player->id, "%s-%d", PRIVATE_Player_ID, PRIVATE_Player_INSTANCE);
    
    player->spaceship = NULL;
    player->argent = 9600;
    player->score = 0;
    player->missed = 0;
    
    memset(player->buyedEquipement, 0, sizeof player->buyedEquipement);
    memset(player->equipedEquipement, 0, sizeof player->equipedEquipement);
    
    player->buyedEquipement[0][0] = 1;
    player->buyedEquipement[1][0] = 1;
    player->buyedEquipement[2][0] = 1;
    player->buyedEquipement[3][0] = 1;
    player->buyedEquipement[4][0] = 1;
    player->buyedEquipement[5][0] = 1;
    player->buyedEquipement[6][0] = 1;
    
    player->equipedEquipement[0] = 1;
    player->equipedEquipement[1] = 1;
    player->equipedEquipement[2] = 1;
    player->equipedEquipement[3] = 1;
    player->equipedEquipement[4] = 1;
    player->equipedEquipement[5] = 1;
    player->equipedEquipement[6] = 1;
    
    PRIVATE_Player_INSTANCE++;
    
    return player;
}

void Player_ActionOnSpaceship(Player * player, const Uint8 * eventList, Singleton * o)
{
    if(player && player->spaceship && eventList && o)
    {
        int x = 0;
        int y = 0;

        if(eventList[SDL_SCANCODE_A]) x -= 1;
        if(eventList[SDL_SCANCODE_D]) x += 1;

        if(!(x == 0 && y == 0))
        {
            Spaceship_Move(player->spaceship, cos(atan2(y, x)), sin(atan2(y, x)));
            Spaceship_SetPosIfOutOf(player->spaceship, 0 - player->spaceship->w/3 , 0, o->window.w  + player->spaceship->w/3, o->window.h);
        }

        if(eventList[SDL_SCANCODE_SPACE])
        {
            Weapon_Shoot(player->spaceship->weaponMain, PLAYER, BulletMainWeapon, o);
        }
        if(eventList[SDL_SCANCODE_K])
        {
            Weapon_Shoot(player->spaceship->weaponSecondaryOne, PLAYER, BulletSecondaryWeapon, o);
            Weapon_Shoot(player->spaceship->weaponSecondaryTwo, PLAYER, BulletSecondaryWeapon, o);
        }
        if(eventList[SDL_SCANCODE_L])
        {
            Shield_Activation(player->spaceship->shield);
        }

        if(Spaceship_GetLife(player->spaceship)/Spaceship_GetLifeMax(player->spaceship) <= PRIVATE_Spaceship_ratioToSmock)
        {
            if(Spaceship_GetLife(player->spaceship)/Spaceship_GetLifeMax(player->spaceship) <= 50.0/100.0) Sprite_Anime(&player->spaceship->blackSmock, 0.2);
        }

    }
}

void Player_AutoActionOnSpaceship(Player * player, Singleton * o)
{
    if(player && player->spaceship)
    {
        Turret_Shoot(player->spaceship->turret, player->spaceship, PLAYER, BulletTurret, o);
    }
}

void Player_DrawSpaceship(Player * player, Window * window,Singleton * o)
{
    if(player && window)
    {
        if(player->spaceship)
        {
            Spaceship_Draw(player->spaceship, window, o);
        }
    }
}

void Player_SetSpaceship(Player * player, Spaceship * spaceship)
{
    if(player && spaceship)
    {
        player->spaceship = spaceship;
    }
}


void Player_Free(Player * player)
{
    if(player)
    {
        if(player->spaceship) Spaceship_Free(player->spaceship);
        free(player); player = NULL;
    }
}
