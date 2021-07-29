//
//  main.c
//  ShootThemUp
//
//  Created by El-idrissi Elyas on 26/11/2019.
//  Copyright © 2019 El-idrissi Elyas. All rights reserved.
//

#include "main.h"
#include "Singleton.h"
#include "Player.h"
#include "Text.h"
#include "TextureManager.h"
#include "Event.h"

int main(int argc, char* argv[])
{
    Singleton o;
    Singleton_InitAll(&o);
    
    Game_Start(&o.game);
    
    while(Game_GetIsRunning(&o.game))
    {
        Utils_Sleep_MsInSleepInit();
        Timer timer = {0};
        Utils_Timer_Start(&timer);
        
        Game_Update(&o.game, &o);
        Game_Draw(&o.game, &o);

        Game_Wait(&o.game, &timer);
    }
    
    Singleton_Free(&o);

    return 0;
}
