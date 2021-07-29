//
//  Shop.h
//  ShootThemUp
//
//  Created by El-idrissi Elyas on 22/12/2019.
//  Copyright © 2019 El-idrissi Elyas. All rights reserved.
//

#ifndef Shop_h
#define Shop_h

#include "main.h"
#include "Sprite.h"
#include "Spaceship.h"
#include "Utils.h"
#include "Game.h"

Shop Shop_New(Singleton * o);

void Shop_InitShopEquipement(Shop * shop, Singleton * o);
void Shop_ApplyShopEquipementOnSpaceship(Shop * shop, Singleton * o);
void Shop_UpdateSpaceshipPreview(Shop * shop, Singleton * o);
void Shop_UpdateEquipement(Shop * shop, Singleton * o);
void Shop_UpdateSelectedBuyable(Shop * shop, Singleton * o);
void Shop_UpdateBoughtAndEquiped(Shop * shop, Singleton * o);
void Shop_UpdateCheckForExit(Shop * shop, Singleton * o);
void Shop_SetSpaceshipPlayer(Shop * shop, Singleton * o, bool isNew);
void Shop_Update(Shop * shop, Singleton * o);

void Shop_DrawBackground(Shop * shop, Singleton * o);
void Shop_DrawSpaceshipPreview(Shop * shop, Singleton * o);
void Shop_DrawSpaceshipInfo(Shop * shop, Singleton * o);
void Shop_DrawEquipement(Shop * shop, Singleton * o);
void Shop_DrawBuyable(Shop * shop, Singleton * o);
void Shop_DrawBuyableInfo(Shop * shop, Singleton * o);
void Shop_DrawButtons(Shop * shop, Singleton * o);
void Shop_DrawMoney(Shop * shop, Singleton * o);
void Shop_Draw(Shop * shop, Singleton * o);

#endif /* Shop_h */
