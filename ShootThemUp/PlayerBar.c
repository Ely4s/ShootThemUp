//
//  PlayerBar.c
//  ShootThemUp
//
//  Created by El-idrissi Elyas on 21/12/2019.
//  Copyright © 2019 El-idrissi Elyas. All rights reserved.
//

#include "PlayerBar.h"

PlayerBar PlayerBar_New(int x, int y, Singleton * o)
{
    PlayerBar playerBar;

    playerBar.x = x;
    playerBar.y = y;
    
    playerBar.GUI = Sprite_New(playerBar.x, playerBar.y, 1000, 118, "PlayerBar", &o->tm);
    
    playerBar.w = playerBar.GUI.w;
    playerBar.h = playerBar.GUI.h;
    
    playerBar.lifeBar = Sprite_New(playerBar.x + 221, playerBar.y + 76, 382, 24, "BarLife", &o->tm);
    playerBar.shieldLifeBar = Sprite_New(playerBar.x +  221, playerBar.y + 18, 382, 24, "BarShieldLife", &o->tm);
    playerBar.shieldTimeBar = Sprite_New(playerBar.x +  221, playerBar.y + 44, 382, 14, "BarShieldTime", &o->tm);
    playerBar.weaponSecondaryCooldownBar = Sprite_New(playerBar.x +  644, playerBar.y + 10, 12, 96, "BarSecondaryWeaponCooldown", &o->tm);
    playerBar.weaponMainCooldownBar = Sprite_New(playerBar.x +  659, playerBar.y + 10, 12, 96, "BarWeaponMainCooldown", &o->tm);
    playerBar.turretCooldownBar = Sprite_New(playerBar.x +  673, playerBar.y + 10, 12, 96, "BarTurretCooldown", &o->tm);
    
    playerBar.lifeBarSize = playerBar.lifeBar.w;
    playerBar.shieldLifeBarSize = playerBar.shieldLifeBar.w;
    playerBar.shieldTimeBarSize = playerBar.shieldTimeBar.w;
    playerBar.weaponSecondaryCooldownBarSize = playerBar.weaponSecondaryCooldownBar.h;
    playerBar.weaponMainCooldownBarSize = playerBar.weaponMainCooldownBar.h;
    playerBar.turretCooldownBarSize = playerBar.turretCooldownBar.h;
    
    return playerBar;
}

void PlayerBar_Draw(PlayerBar * playerBar, Window * window)
{
    if(playerBar)
    {
        Sprite_Draw(&playerBar->GUI, -90, 0, 0, window);
        Sprite_Draw(&playerBar->lifeBar, -90, 0, 0, window);
        Sprite_Draw(&playerBar->shieldLifeBar, -90, 0, 0, window);
        Sprite_Draw(&playerBar->shieldTimeBar, -90, 0, 0, window);
        Sprite_Draw(&playerBar->weaponSecondaryCooldownBar, 90, playerBar->weaponSecondaryCooldownBar.w/2, playerBar->weaponSecondaryCooldownBarSize/2, window);
        Sprite_Draw(&playerBar->weaponMainCooldownBar, 90, playerBar->weaponMainCooldownBar.w/2, playerBar->weaponMainCooldownBarSize/2, window);
        Sprite_Draw(&playerBar->turretCooldownBar, 90, playerBar->turretCooldownBar.w/2, playerBar->turretCooldownBarSize/2, window);
    }
}


void PlayerBar_Update(PlayerBar * playerBar, Player * player)
{
    if(playerBar)
    {
        
        if(player && player->spaceship)
        {
            playerBar->lifeBar.w = playerBar->lifeBarSize * (player->spaceship->totalLife/player->spaceship->totalLifeMax);
            playerBar->lifeBar.wFrame = playerBar->lifeBar.w;
            
            if(player->spaceship->shield)
            {
                playerBar->shieldLifeBar.w = playerBar->shieldLifeBarSize * (player->spaceship->shield->life/player->spaceship->shield->lifeMax);
                playerBar->shieldLifeBar.wFrame = playerBar->shieldLifeBar.w;
                
                if(player->spaceship->shield->isActivated)
                {
                    playerBar->shieldLifeBar.w = playerBar->shieldLifeBarSize * (player->spaceship->shield->life/player->spaceship->shield->lifeMax);
//                    playerBar->shieldLifeBar.wFrame = playerBar->shieldLifeBar.w;
                    
                    playerBar->shieldTimeBar.w = playerBar->shieldTimeBarSize * (player->spaceship->shield->lifeTime/player->spaceship->shield->lifeTimeMax);
//                    playerBar->shieldTimeBar.wFrame = playerBar->shieldTimeBar.w;
                }
                else
                {
                    playerBar->shieldTimeBar.w = playerBar->shieldTimeBarSize * (1 - (player->spaceship->shield->cooldown/player->spaceship->shield->cooldownMax));
                    playerBar->shieldTimeBar.wFrame = playerBar->shieldTimeBar.w;
                    
                    playerBar->shieldLifeBar.w = playerBar->shieldTimeBarSize * (1 - (player->spaceship->shield->cooldown/player->spaceship->shield->cooldownMax));
                    playerBar->shieldLifeBar.wFrame = playerBar->shieldLifeBar.w;
                }
            }
            else
            {
                playerBar->shieldLifeBar.w = 0;
                playerBar->shieldLifeBar.wFrame = playerBar->shieldLifeBar.w;
            }
            
            if(player->spaceship->weaponSecondaryOne && player->spaceship->weaponSecondaryTwo)
            {
                playerBar->weaponSecondaryCooldownBar.h = playerBar->weaponSecondaryCooldownBarSize * (1 - (player->spaceship->weaponSecondaryOne->cooldown/player->spaceship->weaponSecondaryOne->cooldownMax));
                playerBar->weaponSecondaryCooldownBar.hFrame = playerBar->weaponSecondaryCooldownBar.h;
            }
            else
            {
                playerBar->shieldLifeBar.w = 0;
                playerBar->shieldLifeBar.wFrame = playerBar->shieldLifeBar.w;
                
                playerBar->shieldTimeBar.w = 0;
                playerBar->shieldTimeBar.wFrame = playerBar->shieldTimeBar.w;
            }
            
            if(player->spaceship->weaponMain)
            {
                playerBar->weaponMainCooldownBar.h = playerBar->weaponMainCooldownBarSize * (1 - (player->spaceship->weaponMain->cooldown/player->spaceship->weaponMain->cooldownMax));
                playerBar->weaponMainCooldownBar.hFrame = playerBar->weaponMainCooldownBar.h;
            }
            else
            {
                playerBar->weaponMainCooldownBar.h = 0;
                playerBar->weaponMainCooldownBar.hFrame = playerBar->weaponMainCooldownBar.h;
            }
            
            if(player->spaceship->turret)
            {
                playerBar->turretCooldownBar.h = playerBar->turretCooldownBarSize * (1 - (player->spaceship->turret->cooldown/player->spaceship->turret->cooldownMax));
                playerBar->turretCooldownBar.hFrame = playerBar->turretCooldownBar.h;
            }
            else
            {
                playerBar->turretCooldownBar.h = 0;
                playerBar->turretCooldownBar.hFrame = playerBar->turretCooldownBar.h;
            }
        }
        else
        {
            playerBar->lifeBar.w = 0;
            playerBar->lifeBar.wFrame = playerBar->lifeBar.w;
            
            playerBar->shieldLifeBar.w = 0;
            playerBar->shieldLifeBar.wFrame = playerBar->shieldLifeBar.w;
            
            playerBar->shieldTimeBar.w = 0;
            playerBar->shieldTimeBar.wFrame = playerBar->shieldTimeBar.w;
            
            playerBar->weaponSecondaryCooldownBar.h = 0;
            playerBar->weaponSecondaryCooldownBar.hFrame = playerBar->weaponSecondaryCooldownBar.h;
            
            playerBar->weaponMainCooldownBar.h = 0;
            playerBar->weaponMainCooldownBar.hFrame = playerBar->weaponMainCooldownBar.h;
            
            playerBar->turretCooldownBar.h = 0;
            playerBar->turretCooldownBar.hFrame = playerBar->turretCooldownBar.h;
        }
    }
}
