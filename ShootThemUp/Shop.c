//
//  Shop.c
//  ShootThemUp
//
//  Created by El-idrissi Elyas on 22/12/2019.
//  Copyright © 2019 El-idrissi Elyas. All rights reserved.
//

#include "Shop.h"

Shop Shop_New(Singleton * o)
{
    Shop shop;
    
    shop.priceEquipement[0][0] = 100;
    shop.priceEquipement[0][1] = 200;
    shop.priceEquipement[0][2] = 400;
    shop.priceEquipement[0][3] = 800;
    shop.priceEquipement[0][4] = 1600;
    
    shop.priceEquipement[1][0] = 35;
    shop.priceEquipement[1][1] = 65;
    shop.priceEquipement[1][2] = 135;
    shop.priceEquipement[1][3] = 265;
    shop.priceEquipement[1][4] = 535;
    
    shop.priceEquipement[2][0] = 65;
    shop.priceEquipement[2][1] = 135;
    shop.priceEquipement[2][2] = 265;
    shop.priceEquipement[2][3] = 535;
    shop.priceEquipement[2][4] = 1065;
    
    shop.priceEquipement[3][0] = 100;
    shop.priceEquipement[3][1] = 200;
    shop.priceEquipement[3][2] = 400;
    shop.priceEquipement[3][3] = 800;
    shop.priceEquipement[3][4] = 1600;
    
    
    shop.priceEquipement[4][0] = 100;
    shop.priceEquipement[4][1] = 200;
    shop.priceEquipement[4][2] = 400;
    shop.priceEquipement[4][3] = 800;
    shop.priceEquipement[4][4] = 1600;
    
    shop.priceEquipement[5][0] = 100;
    shop.priceEquipement[5][1] = 200;
    shop.priceEquipement[5][2] = 400;
    shop.priceEquipement[5][3] = 800;
    shop.priceEquipement[5][4] = 1600;
    
    shop.priceEquipement[6][0] = 100;
    shop.priceEquipement[6][1] = 200;
    shop.priceEquipement[6][2] = 400;
    shop.priceEquipement[6][3] = 800;
    shop.priceEquipement[6][4] = 1600;
    
    sprintf(shop.nameEquipement[0], "Body");
    sprintf(shop.nameEquipement[1], "Main Reactor");
    sprintf(shop.nameEquipement[2], "Secondary Reactors");
    sprintf(shop.nameEquipement[3], "Main Weapon");
    sprintf(shop.nameEquipement[4], "Rocket Luncher");
    sprintf(shop.nameEquipement[5], "Turret");
    sprintf(shop.nameEquipement[6], "Shield");
    
    shop.background = Sprite_New(0, 0, o->window.w,  o->window.h, "ShopBackground", &o->tm);
    
    shop.xSpaceshipPreview = 22;
    shop.ySpaceshipPreview = 93;
    shop.wSpaceshipPreview = 318;
    shop.hSpaceshipPreview = 318;
    
    shop.xSpaceshipInfo = 382;
    shop.ySpaceshipInfo = 66;
    
    shop.xStartEquipementEquipedCase = 613;
    shop.yStartEquipementEquipedCase = 64;
    shop.xOffEquipementEquiped = 22;
    shop.yOffEquipementEquiped = 16;
    shop.yOffBodyEquiped = 30;
    
    shop.xStartBuyableCase = 297;
    shop.yStartBuyableCase = 705;
    shop.xOffBuyableCase = 42;
    shop.yOffBuyableCase = 78;
    
    shop.xStartBuyableInfoTitle = 292;
    shop.yStartBuyableInfoTitle = 535;
    
    shop.xStartBuyableInfo = shop.xStartBuyableInfoTitle + 310;
    shop.yStartBuyableInfo = shop.yStartBuyableInfoTitle + 3;
    
    shop.wCaseLittle = 60;
    shop.hCaseLittle = 60;
    
    shop.xMoney = 816;
    shop.yMoney = 386;
    
    array_new(&shop.buyableCases);
    array_new(&shop.equipementCases);

    shop.buttonEquipeBuy = Sprite_New(0, 0, 10, 10, "ButtonBig", &o->tm);
    shop.selectedCase = Sprite_New(0, 0, 10, 10, "SelectedCase", &o->tm);
    
    shop.buttonPlay = Sprite_New(0, 0, 10, 10, "ButtonPlay", &o->tm);
    shop.buttonPlay.x = 901;
    shop.buttonPlay.y = 268;
    
    shop.buttonCancel = Sprite_New(0, 0, 10, 10, "ButtonCancel", &o->tm);
    shop.buttonCancel.x = 901;
    shop.buttonCancel.y = 129;
    
    shop.spaceshipShop = Spaceship_New(1, 0, 0, 1, 0, 0, 0, 0, 0, 0, o);
    
    char type[7][1024] = {"spaceship", "reactor", "reactor", "weaponMain", "weaponSecondary", "turret", "shield"};
    
    for(int y = 0; y < 8; y++)
    {
        for(int x = 0; x < 5; x++)
        {
            
            ShopCase * buyableCase = malloc(sizeof(ShopCase));
            
            char textureId[1024];
            
            sprintf(textureId, "%s_tier_%d_idle", type[y], x+1);
            
            Sprite sprite = Sprite_New(shop.xStartBuyableCase + x*shop.xOffBuyableCase + x*shop.wCaseLittle + shop.wCaseLittle/2, shop.yStartBuyableCase + y*shop.yOffBuyableCase + y*shop.hCaseLittle + shop.hCaseLittle/2, 0, 0, textureId, &o->tm);
            
            
            float biggestSize = (sprite.w > sprite.h) ? sprite.w : sprite.h;
            
            float wMulti = ( ((float)(shop.wCaseLittle - 20)/(float)biggestSize) > 1) ? 1 : (float)(shop.wCaseLittle - 20)/(float)biggestSize;
            float hMulti = ( ((float)(shop.hCaseLittle - 20)/(float)biggestSize) > 1) ? 1 : (float)(shop.hCaseLittle - 20)/(float)biggestSize;
            
            buyableCase->x = sprite.x - shop.wCaseLittle/2;
            buyableCase->y = sprite.y - shop.hCaseLittle/2;
            buyableCase->w = shop.wCaseLittle;
            buyableCase->h = shop.hCaseLittle;
            
            buyableCase->xCase = x;
            buyableCase->yCase = y;
            
            sprite.w = sprite.w * wMulti;
            sprite.h = sprite.h * hMulti;
            
            Sprite_SetPos(&sprite, sprite.x - sprite.w/2, sprite.y - sprite.h/2);
            
            buyableCase->content = sprite;
            
            array_add_at(shop.buyableCases, buyableCase, array_size(shop.buyableCases));
        }
    }

    int yOff = 0;

    for(int y = 0; y < 3; y++)
    {
        for(int x = 0; x < 3; x++)
        {
            if(y == 1 && x == 0)
            {
                yOff = shop.yOffBodyEquiped;
            }
            if(!(x == 0 && y == 0) && !(x == 2 && y == 0))
            {
                ShopCase * equipementCase = malloc(sizeof(ShopCase));

                equipementCase->x = shop.xStartEquipementEquipedCase + x*shop.xOffEquipementEquiped + x*shop.wCaseLittle;
                equipementCase->y = shop.yStartEquipementEquipedCase + y*shop.yOffEquipementEquiped + y*shop.hCaseLittle;
                equipementCase->y += yOff;
                equipementCase->w = shop.wCaseLittle;
                equipementCase->h = shop.hCaseLittle;

                array_add_at(shop.equipementCases, equipementCase, array_size(shop.equipementCases));
                
                
            }
        }
    }
    return shop;
}

void Shop_UpdateSpaceshipPreview(Shop * shop, Singleton * o)
{
    SpaceshipType spaceshipType = shop->equipedNewEquipement[0];
    BodyType bodyType = shop->equipedNewEquipement[0];
    ReactorType reactorMType = shop->equipedNewEquipement[1];
    ReactorType reactorSType = shop->equipedNewEquipement[2];
    WeaponType weaponMType = shop->equipedNewEquipement[3];
    WeaponType weaponSType = shop->equipedNewEquipement[4];
    TurretType turretType = shop->equipedNewEquipement[5];
    ShieldType shieldType = shop->equipedNewEquipement[6];
    
    shop->spaceshipShop->type = spaceshipType;
    Spaceship_SetBody(shop->spaceshipShop, bodyType, &o->pm);
    Spaceship_SetReactor(shop->spaceshipShop, reactorMType, &o->pm);
    Spaceship_SetReactorSecondary(shop->spaceshipShop, reactorSType, &o->pm);
    Spaceship_SetMainWeapon(shop->spaceshipShop, weaponMType, &o->pm);
    Spaceship_SetWeaponSecondary(shop->spaceshipShop, weaponSType, &o->pm);
    Spaceship_SetTurret(shop->spaceshipShop, turretType, &o->pm);
    Spaceship_SetShield(shop->spaceshipShop, shieldType, &o->pm);
    
    Spaceship_SetLifeMax(shop->spaceshipShop, true);
    
    Spaceship_SetPos(shop->spaceshipShop, shop->xSpaceshipPreview + shop->wSpaceshipPreview/2 - shop->spaceshipShop->w/2, shop->ySpaceshipPreview + shop->hSpaceshipPreview/2 - shop->spaceshipShop->h/2);
}

void Shop_UpdateEquipement(Shop * shop, Singleton * o)
{
    if(shop->spaceshipShop)
    {
        ShopCase * equipementCase1 = array_get_at(shop->equipementCases, 0);
        ShopCase * equipementCase2 = array_get_at(shop->equipementCases, 1);
        ShopCase * equipementCase3 = array_get_at(shop->equipementCases, 2);
        ShopCase * equipementCase4 = array_get_at(shop->equipementCases, 3);
        ShopCase * equipementCase5 = array_get_at(shop->equipementCases, 4);
        ShopCase * equipementCase6 = array_get_at(shop->equipementCases, 5);
        ShopCase * equipementCase7 = array_get_at(shop->equipementCases, 6);
        
        ShopCase * buyableCase;
        buyableCase = array_get_at(shop->buyableCases, Utils_2DTabPosTo1D(0, shop->equipedNewEquipement[0] - 1, 5));
        equipementCase1->content = buyableCase->content;
        buyableCase = array_get_at(shop->buyableCases, Utils_2DTabPosTo1D(1, shop->equipedNewEquipement[1] - 1, 5));
        equipementCase2->content = buyableCase->content;
        buyableCase = array_get_at(shop->buyableCases, Utils_2DTabPosTo1D(2, shop->equipedNewEquipement[2] - 1, 5));
        equipementCase3->content = buyableCase->content;
        buyableCase = array_get_at(shop->buyableCases, Utils_2DTabPosTo1D(3, shop->equipedNewEquipement[3] - 1, 5));
        equipementCase4->content = buyableCase->content;
        buyableCase = array_get_at(shop->buyableCases, Utils_2DTabPosTo1D(4, shop->equipedNewEquipement[4] - 1, 5));
        equipementCase5->content = buyableCase->content;
        buyableCase = array_get_at(shop->buyableCases, Utils_2DTabPosTo1D(5, shop->equipedNewEquipement[5] - 1, 5));
        equipementCase6->content = buyableCase->content;
        buyableCase = array_get_at(shop->buyableCases, Utils_2DTabPosTo1D(6, shop->equipedNewEquipement[6] - 1, 5));
        equipementCase7->content = buyableCase->content;
        
        for(int i = 0; i < array_size(shop->equipementCases); i++)
        {
            ShopCase * buyableCase = array_get_at(shop->equipementCases, i);
            
            buyableCase->content.x = buyableCase->x;
            buyableCase->content.y = buyableCase->y;
            
            float biggestSize = (buyableCase->content.w > buyableCase->content.h) ? buyableCase->content.w : buyableCase->content.h;
            
            float wMulti = ( ((float)(shop->wCaseLittle - 20)/(float)biggestSize) > 1) ? 1 : (float)(shop->wCaseLittle - 20)/(float)biggestSize;
            float hMulti = ( ((float)(shop->hCaseLittle - 20)/(float)biggestSize) > 1) ? 1 : (float)(shop->hCaseLittle - 20)/(float)biggestSize;
            
            buyableCase->content.w = buyableCase->content.w * wMulti;
            buyableCase->content.h = buyableCase->content.h * hMulti;
            
            Sprite_SetPos(&buyableCase->content, buyableCase->content.x - buyableCase->content.w/2 + shop->wCaseLittle/2, buyableCase->content.y - buyableCase->content.h/2 + shop->hCaseLittle/2);
        }
    }
}

void Shop_UpdateSelectedBuyable(Shop * shop, Singleton * o)
{
    for(int i = 0; i < array_size(o->shop.buyableCases); i++)
    {
        ShopCase * buyableCase = array_get_at(o->shop.buyableCases, i);
        
        if(Event_IsMouseDown(&o->event))
        {
            if(Utils_Collision_AABB(buyableCase->x, buyableCase->y, buyableCase->w, buyableCase->h, o->event.Xmouse, o->event.Ymouse, 4, 4))
            {
                shop->xCaseSelected = buyableCase->yCase;
                shop->yCaseSelected = buyableCase->xCase;
                
                shop->buttonEquipeBuy.x = shop->xStartBuyableInfo + 220;
                shop->buttonEquipeBuy.y = shop->yStartBuyableInfo + 10;
                
                ShopCase * selectedCase = array_get_at(shop->buyableCases, Utils_2DTabPosTo1D(buyableCase->yCase,  buyableCase->xCase, 5));
                
                shop->selectedCase.x = selectedCase->x - 12;
                shop->selectedCase.y = selectedCase->y - 16;
            }
        }
    }
}

void Shop_UpdateBoughtAndEquiped(Shop * shop, Singleton * o)
{
    if(shop->xCaseSelected != -1 && shop->yCaseSelected != -1)
    {
        if(Event_IsMouseDown(&o->event))
        {
            if(Utils_Collision_AABB(shop->buttonEquipeBuy.x, shop->buttonEquipeBuy.y, shop->buttonEquipeBuy.w, shop->buttonEquipeBuy.h, o->event.Xmouse, o->event.Ymouse, 4, 4))
            {
                
                if(shop->xCaseSelected == 0 && o->player->buyedEquipement[shop->xCaseSelected][shop->yCaseSelected] == 0 && o->player->argent - o->shop.priceEquipement[shop->xCaseSelected][shop->yCaseSelected] >= 0)
                {
                    o->player->buyedEquipement[shop->xCaseSelected][shop->yCaseSelected] = 1;
                    o->player->argent -= o->shop.priceEquipement[shop->xCaseSelected][shop->yCaseSelected];
                    Spaceship_SetBody(shop->spaceshipShop, shop->yCaseSelected +1, &o->pm);
                    shop->equipedNewEquipement[0] = shop->yCaseSelected + 1;
                }
                else if (shop->xCaseSelected == 0 && o->player->buyedEquipement[shop->xCaseSelected][shop->yCaseSelected] == 1)
                {
                    Spaceship_SetBody(shop->spaceshipShop, shop->yCaseSelected +1, &o->pm);
                    shop->equipedNewEquipement[0] = shop->yCaseSelected + 1;
                }
                
                if(shop->xCaseSelected == 1 && o->player->buyedEquipement[shop->xCaseSelected][shop->yCaseSelected] == 0 && o->player->argent - o->shop.priceEquipement[shop->xCaseSelected][shop->yCaseSelected] >= 0)
                {
                    o->player->buyedEquipement[shop->xCaseSelected][shop->yCaseSelected] = 1;
                    o->player->argent -= o->shop.priceEquipement[shop->xCaseSelected][shop->yCaseSelected];
                    Spaceship_SetReactor(shop->spaceshipShop, shop->yCaseSelected +1, &o->pm);
                    shop->equipedNewEquipement[1] = shop->yCaseSelected + 1;
                }
                else if (shop->xCaseSelected == 1 && o->player->buyedEquipement[shop->xCaseSelected][shop->yCaseSelected] == 1)
                {
                    Spaceship_SetReactor(shop->spaceshipShop, shop->yCaseSelected + 1, &o->pm);
                    shop->equipedNewEquipement[1] = shop->yCaseSelected + 1;
                }
                
                if(shop->xCaseSelected == 2 && o->player->buyedEquipement[shop->xCaseSelected][shop->yCaseSelected] == 0 && o->player->argent - o->shop.priceEquipement[shop->xCaseSelected][shop->yCaseSelected] >= 0)
                {
                    o->player->buyedEquipement[shop->xCaseSelected][shop->yCaseSelected] = 1;
                    o->player->argent -= o->shop.priceEquipement[shop->xCaseSelected][shop->yCaseSelected];
                    Spaceship_SetReactorSecondary(shop->spaceshipShop, shop->yCaseSelected +1, &o->pm);
                    shop->equipedNewEquipement[2] = shop->yCaseSelected + 1;
                }
                else if (shop->xCaseSelected == 2 && o->player->buyedEquipement[shop->xCaseSelected][shop->yCaseSelected] == 1)
                {
                    Spaceship_SetReactorSecondary(shop->spaceshipShop, shop->yCaseSelected +1, &o->pm);
                    shop->equipedNewEquipement[2] = shop->yCaseSelected + 1;
                }
                
                if(shop->xCaseSelected == 3 && o->player->buyedEquipement[shop->xCaseSelected][shop->yCaseSelected] == 0 && o->player->argent - o->shop.priceEquipement[shop->xCaseSelected][shop->yCaseSelected] >= 0)
                {
                    o->player->buyedEquipement[shop->xCaseSelected][shop->yCaseSelected] = 1;
                    o->player->argent -= o->shop.priceEquipement[shop->xCaseSelected][shop->yCaseSelected];
                    Spaceship_SetMainWeapon(shop->spaceshipShop, shop->yCaseSelected +1, &o->pm);
                    shop->equipedNewEquipement[3] = shop->yCaseSelected + 1;
                }
                else if (shop->xCaseSelected == 3 && o->player->buyedEquipement[shop->xCaseSelected][shop->yCaseSelected] == 1)
                {
                    Spaceship_SetMainWeapon(shop->spaceshipShop, shop->yCaseSelected +1, &o->pm);
                    shop->equipedNewEquipement[3] = shop->yCaseSelected + 1;
                }
                
                if(shop->xCaseSelected == 4 && o->player->buyedEquipement[shop->xCaseSelected][shop->yCaseSelected] == 0 && o->player->argent - o->shop.priceEquipement[shop->xCaseSelected][shop->yCaseSelected] >= 0)
                {
                    o->player->buyedEquipement[shop->xCaseSelected][shop->yCaseSelected] = 1;
                    o->player->argent -= o->shop.priceEquipement[shop->xCaseSelected][shop->yCaseSelected];
                    Spaceship_SetWeaponSecondary(shop->spaceshipShop, shop->yCaseSelected +1, &o->pm);
                    shop->equipedNewEquipement[4] = shop->yCaseSelected + 1;
                }
                else if (shop->xCaseSelected == 4 && o->player->buyedEquipement[shop->xCaseSelected][shop->yCaseSelected] == 1)
                {
                    Spaceship_SetWeaponSecondary(shop->spaceshipShop, shop->yCaseSelected +1, &o->pm);
                    shop->equipedNewEquipement[4] = shop->yCaseSelected + 1;
                }
                
                if(shop->xCaseSelected == 5 && o->player->buyedEquipement[shop->xCaseSelected][shop->yCaseSelected] == 0 && o->player->argent - o->shop.priceEquipement[shop->xCaseSelected][shop->yCaseSelected] >= 0)
                {
                    o->player->buyedEquipement[shop->xCaseSelected][shop->yCaseSelected] = 1;
                    o->player->argent -= o->shop.priceEquipement[shop->xCaseSelected][shop->yCaseSelected];
                    Spaceship_SetTurret(shop->spaceshipShop, shop->yCaseSelected +1, &o->pm);
                    shop->equipedNewEquipement[5] = shop->yCaseSelected + 1;
                }
                else if (shop->xCaseSelected == 5 && o->player->buyedEquipement[shop->xCaseSelected][shop->yCaseSelected] == 1)
                {
                    Spaceship_SetTurret(shop->spaceshipShop, shop->yCaseSelected +1, &o->pm);
                    shop->equipedNewEquipement[5] = shop->yCaseSelected + 1;
                }
                
                if(shop->xCaseSelected == 6 && o->player->buyedEquipement[shop->xCaseSelected][shop->yCaseSelected] == 0 && o->player->argent - o->shop.priceEquipement[shop->xCaseSelected][shop->yCaseSelected] >= 0)
                {
                    o->player->buyedEquipement[shop->xCaseSelected][shop->yCaseSelected] = 1;
                    o->player->argent -= o->shop.priceEquipement[shop->xCaseSelected][shop->yCaseSelected];
                    Spaceship_SetShield(shop->spaceshipShop, shop->yCaseSelected +1, &o->pm);
                    shop->equipedNewEquipement[6] = shop->yCaseSelected + 1;
                }
                else if (shop->xCaseSelected == 6 && o->player->buyedEquipement[shop->xCaseSelected][shop->yCaseSelected] == 1)
                {
                    Spaceship_SetShield(shop->spaceshipShop, shop->yCaseSelected +1, &o->pm);
                    shop->equipedNewEquipement[6] = shop->yCaseSelected + 1;
                }
                
                Spaceship_SetPos(shop->spaceshipShop, shop->xSpaceshipPreview + shop->wSpaceshipPreview/2 - shop->spaceshipShop->w/2, shop->ySpaceshipPreview + shop->hSpaceshipPreview/2 - shop->spaceshipShop->h/2);
            }
        }
    }
}

void Shop_UpdateCheckForExit(Shop * shop, Singleton * o)
{
    if(Event_IsMouseDown(&o->event))
    {
        if(Utils_Collision_AABB(shop->buttonPlay.x, shop->buttonPlay.y, shop->buttonPlay.w, shop->buttonPlay.h, o->event.Xmouse, o->event.Ymouse, 4, 4))
        {
            Shop_ApplyShopEquipementOnSpaceship(shop, o);
            Shop_SetSpaceshipPlayer(shop, o, true);
            o->game.gamePhase = PlayPhase;
        }
        if(Utils_Collision_AABB(shop->buttonCancel.x, shop->buttonCancel.y, shop->buttonCancel.w, shop->buttonCancel.h, o->event.Xmouse, o->event.Ymouse, 4, 4))
        {
            Shop_SetSpaceshipPlayer(shop, o, false);
            o->game.gamePhase = PlayPhase;
        }
        
    }
}

void Shop_InitShopEquipement(Shop * shop, Singleton * o)
{
    for(int i = 0; i < 7; i++)
    {
        shop->equipedNewEquipement[i] = o->player->equipedEquipement[i];
    }
}

void Shop_ApplyShopEquipementOnSpaceship(Shop * shop, Singleton * o)
{
    for(int i = 0; i < 7; i++)
    {
        o->player->equipedEquipement[i] = shop->equipedNewEquipement[i];
    }
}

void Shop_SetSpaceshipPlayer(Shop * shop, Singleton * o, bool isNew)
{
    if(o->player)
    {
        if(!o->player->spaceship)
        {
            o->player->spaceship = Spaceship_New(SpaceshipTier1, 0, 0, BodyTier1, ReactorTier1, ReactorTier1, WeaponTier1, WeaponTier1, TurretTier1, ShieldTier1, o);
        }
        if(o->player->spaceship)
        {
            if(isNew)
            {
                o->player->spaceship->type = shop->equipedNewEquipement[0];
                Spaceship_SetBody(o->player->spaceship, shop->equipedNewEquipement[0], &o->pm);
                Spaceship_SetReactor(o->player->spaceship, shop->equipedNewEquipement[1], &o->pm);
                Spaceship_SetReactorSecondary(o->player->spaceship, shop->equipedNewEquipement[2], &o->pm);
                Spaceship_SetMainWeapon(o->player->spaceship, shop->equipedNewEquipement[3], &o->pm);
                Spaceship_SetWeaponSecondary(o->player->spaceship, shop->equipedNewEquipement[4], &o->pm);
                Spaceship_SetTurret(o->player->spaceship, shop->equipedNewEquipement[5], &o->pm);
                Spaceship_SetShield(o->player->spaceship, shop->equipedNewEquipement[6], &o->pm);
            }
            else
            {
                o->player->spaceship->type = o->player->equipedEquipement[0];
                Spaceship_SetBody(o->player->spaceship, o->player->equipedEquipement[0], &o->pm);
                Spaceship_SetReactor(o->player->spaceship, o->player->equipedEquipement[1], &o->pm);
                Spaceship_SetReactorSecondary(o->player->spaceship, o->player->equipedEquipement[2], &o->pm);
                Spaceship_SetMainWeapon(o->player->spaceship, o->player->equipedEquipement[3], &o->pm);
                Spaceship_SetWeaponSecondary(o->player->spaceship, o->player->equipedEquipement[4], &o->pm);
                Spaceship_SetTurret(o->player->spaceship, o->player->equipedEquipement[5], &o->pm);
                Spaceship_SetShield(o->player->spaceship, o->player->equipedEquipement[6], &o->pm);
            }
            
            Spaceship_SetLifeMax(o->player->spaceship, true);
            Play_SetPlayerSpaceshipPosInDefault(&o->play, o->player->spaceship);
        }
    }
}

void Shop_Update(Shop * shop, Singleton * o)
{
    Shop_UpdateSelectedBuyable(shop, o);
    Shop_UpdateBoughtAndEquiped(shop, o);
    Shop_UpdateEquipement(shop, o);
    Shop_UpdateSpaceshipPreview(shop, o);
    Shop_UpdateCheckForExit(shop, o);
}

void Shop_DrawBuyableInfo(Shop * shop, Singleton * o)
{
    if(shop)
    {
        char str[1024];

        if(shop->xCaseSelected == 0)
        {
            Body * body = PatternManager_GetBodyPattern(&o->pm, shop->yCaseSelected + 1);
            memset(str, 0, sizeof str);
            sprintf(str, "Life : %d", (int)body->lifeMax);
            Text_Draw(str, shop->xStartBuyableInfo, shop->yStartBuyableInfo, TextLeft, 15, "PixelFont", Utils_Color_Get(255, 255, 255), &o->window, &o->tm);
            Body_Free(body);
        }

        if(shop->xCaseSelected == 1 || shop->xCaseSelected == 2)
        {
            Reactor * reactor = PatternManager_GetReactorPattern(&o->pm, shop->yCaseSelected + 1);

            memset(str, 0, sizeof str);
            sprintf(str, "Life : %d", (int)reactor->lifeMax);
            Text_Draw(str, shop->xStartBuyableInfo, shop->yStartBuyableInfo, TextLeft, 15, "PixelFont", Utils_Color_Get(255, 255, 255), &o->window, &o->tm);

            memset(str, 0, sizeof str);
            sprintf(str, "Speed : %.2f", reactor->speed);
            Text_Draw(str, shop->xStartBuyableInfo, shop->yStartBuyableInfo + 20, TextLeft, 15, "PixelFont", Utils_Color_Get(255, 255, 255), &o->window, &o->tm);
            
            Reactor_Free(reactor);
        }

        if(shop->xCaseSelected == 3)
        {
            Weapon * weapon = PatternManager_GetWeaponPattern(&o->pm, shop->yCaseSelected + 1);

            memset(str, 0, sizeof str);
            sprintf(str, "Life : %d", (int)weapon->lifeMax);
            Text_Draw(str, shop->xStartBuyableInfo, shop->yStartBuyableInfo, TextLeft, 15, "PixelFont", Utils_Color_Get(255, 255, 255), &o->window, &o->tm);

            memset(str, 0, sizeof str);
            sprintf(str, "Damage : %d", (int)weapon->damage);
            Text_Draw(str, shop->xStartBuyableInfo, shop->yStartBuyableInfo + 20, TextLeft, 15, "PixelFont", Utils_Color_Get(255, 255, 255), &o->window, &o->tm);

            memset(str, 0, sizeof str);
            sprintf(str, "Bullet speed : %d", (int)weapon->speedBullet);
            Text_Draw(str, shop->xStartBuyableInfo, shop->yStartBuyableInfo + 40, TextLeft, 15, "PixelFont", Utils_Color_Get(255, 255, 255), &o->window, &o->tm);

            memset(str, 0, sizeof str);
            sprintf(str, "Cooldown : %d", (int)weapon->cooldownMax);
            Text_Draw(str, shop->xStartBuyableInfo, shop->yStartBuyableInfo + 60, TextLeft, 15, "PixelFont", Utils_Color_Get(255, 255, 255), &o->window, &o->tm);
            
            Weapon_Free(weapon);
        }

        if(shop->xCaseSelected == 4)
        {
            Weapon * weapon = PatternManager_GetWeaponSecondaryPattern(&o->pm, shop->yCaseSelected + 1);

            memset(str, 0, sizeof str);
            sprintf(str, "Life : %d", (int)weapon->lifeMax);
            Text_Draw(str, shop->xStartBuyableInfo, shop->yStartBuyableInfo, TextLeft, 15, "PixelFont", Utils_Color_Get(255, 255, 255), &o->window, &o->tm);

            memset(str, 0, sizeof str);
            sprintf(str, "Damage : %d", (int)weapon->damage);
            Text_Draw(str, shop->xStartBuyableInfo, shop->yStartBuyableInfo + 20, TextLeft, 15, "PixelFont", Utils_Color_Get(255, 255, 255), &o->window, &o->tm);

            memset(str, 0, sizeof str);
            sprintf(str, "Bullet speed : %d", (int)weapon->speedBullet);
            Text_Draw(str, shop->xStartBuyableInfo, shop->yStartBuyableInfo + 40, TextLeft, 15, "PixelFont", Utils_Color_Get(255, 255, 255), &o->window, &o->tm);

            memset(str, 0, sizeof str);
            sprintf(str, "Cooldown : %d", (int)weapon->cooldownMax);
            Text_Draw(str, shop->xStartBuyableInfo, shop->yStartBuyableInfo + 60, TextLeft, 15, "PixelFont", Utils_Color_Get(255, 255, 255), &o->window, &o->tm);
            
            Weapon_Free(weapon);
        }

        if(shop->xCaseSelected == 5)
        {
            Turret * turret = PatternManager_GetTurretPattern(&o->pm, shop->yCaseSelected + 1);

            memset(str, 0, sizeof str);
            sprintf(str, "Life : %d", (int)turret->lifeMax);
            Text_Draw(str, shop->xStartBuyableInfo, shop->yStartBuyableInfo, TextLeft, 15, "PixelFont", Utils_Color_Get(255, 255, 255), &o->window, &o->tm);

            memset(str, 0, sizeof str);
            sprintf(str, "Damage : %d", (int)turret->damage);
            Text_Draw(str, shop->xStartBuyableInfo, shop->yStartBuyableInfo + 20, TextLeft, 15, "PixelFont", Utils_Color_Get(255, 255, 255), &o->window, &o->tm);

            memset(str, 0, sizeof str);
            sprintf(str, "Bullet speed : %d", (int)turret->speedBullet);
            Text_Draw(str, shop->xStartBuyableInfo, shop->yStartBuyableInfo + 40, TextLeft, 15, "PixelFont", Utils_Color_Get(255, 255, 255), &o->window, &o->tm);

            memset(str, 0, sizeof str);
            sprintf(str, "Cooldown : %d", (int)turret->cooldown);
            Text_Draw(str, shop->xStartBuyableInfo, shop->yStartBuyableInfo + 60, TextLeft, 15, "PixelFont", Utils_Color_Get(255, 255, 255), &o->window, &o->tm);

            memset(str, 0, sizeof str);
            sprintf(str, "Rotation speed : %d", (int)turret->speedRotation);
            Text_Draw(str, shop->xStartBuyableInfo, shop->yStartBuyableInfo + 80, TextLeft, 15, "PixelFont", Utils_Color_Get(255, 255, 255), &o->window, &o->tm);
            
            Turret_Free(turret);
        }

        if(shop->xCaseSelected == 6)
        {
            Shield * shield = PatternManager_GetShieldPattern(&o->pm, shop->yCaseSelected + 1);

            memset(str, 0, sizeof str);
            sprintf(str, "Life : %d", (int)shield->life);
            Text_Draw(str, shop->xStartBuyableInfo, shop->yStartBuyableInfo, TextLeft, 15, "PixelFont", Utils_Color_Get(255, 255, 255), &o->window, &o->tm);

            memset(str, 0, sizeof str);
            sprintf(str, "Life Time : %d", (int)shield->lifeMax);
            Text_Draw(str, shop->xStartBuyableInfo, shop->yStartBuyableInfo + 20, TextLeft, 15, "PixelFont", Utils_Color_Get(255, 255, 255), &o->window, &o->tm);

            memset(str, 0, sizeof str);
            sprintf(str, "Cooldown : %d", (int)shield->cooldownMax);
            Text_Draw(str, shop->xStartBuyableInfo, shop->yStartBuyableInfo + 40, TextLeft, 15, "PixelFont", Utils_Color_Get(255, 255, 255), &o->window, &o->tm);
            
            Shield_Free(shield);
        }
        
        if(shop->xCaseSelected != -1)
        {
            memset(str, 0, sizeof str);
            sprintf(str, "%s Tier %d", shop->nameEquipement[shop->xCaseSelected], shop->yCaseSelected + 1);
            Text_Draw(str, shop->xStartBuyableInfoTitle, shop->yStartBuyableInfoTitle, TextLeft, 18, "PixelFont", Utils_Color_Get(255, 255, 255), &o->window, &o->tm);
            
            if(o->player->buyedEquipement[shop->xCaseSelected][shop->yCaseSelected] == 0)
            {
                memset(str, 0, sizeof str);
                sprintf(str, "Price : %d Bolts", shop->priceEquipement[shop->xCaseSelected][shop->yCaseSelected]);
                Text_Draw(str, shop->xStartBuyableInfoTitle, shop->yStartBuyableInfoTitle + 30, TextLeft, 18, "PixelFont", Utils_Color_Get(255, 255, 255), &o->window, &o->tm);
            }
        }
        
        for(int i = 0; i < 7; i++)
        {
            memset(str, 0, sizeof str);
            sprintf(str, "%s", shop->nameEquipement[i]);
            Text_Draw(str, shop->xStartBuyableCase - 144, shop->yStartBuyableCase + shop->yOffBuyableCase*i + shop->hCaseLittle*i + 23, TextCenter, 14, "PixelFont", Utils_Color_Get(255, 255, 255), &o->window, &o->tm);
        }
    }
}

void Shop_DrawBackground(Shop * shop, Singleton * o)
{
    Sprite_Draw(&shop->background, -90, 0, 0, &o->window);
}

void Shop_DrawSpaceshipInfo(Shop * shop, Singleton * o)
{
    char str[1024];
    
    memset(str, 0, sizeof str);
    sprintf(str, "Life : %0.f (+%d)", shop->spaceshipShop->totalLifeMax, (int)shop->spaceshipShop->shield->lifeMax);
    Text_Draw(str, shop->xSpaceshipInfo, shop->ySpaceshipInfo, TextLeft, 15, "PixelFont", Utils_Color_Get(255, 255, 255), &o->window, &o->tm);
    
    memset(str, 0, sizeof str);
    sprintf(str, "Speed : %.2f", (float)Spaceship_GetTotalSpeed(shop->spaceshipShop));
    Text_Draw(str, shop->xSpaceshipInfo, shop->ySpaceshipInfo + 20, TextLeft, 15, "PixelFont", Utils_Color_Get(255, 255, 255), &o->window, &o->tm);
    
    memset(str, 0, sizeof str);
    sprintf(str, "Damage/s : %.2f", Spaceship_GetTotalDamagePerSeconde(shop->spaceshipShop));
    Text_Draw(str, shop->xSpaceshipInfo, shop->ySpaceshipInfo + 20*2, TextLeft, 15, "PixelFont", Utils_Color_Get(255, 255, 255), &o->window, &o->tm);
    
    for(int i = 0; i < 7; i ++)
    {
        memset(str, 0, sizeof str);
        sprintf(str, "%s", shop->nameEquipement[i]);
        Text_Draw(str, shop->xSpaceshipInfo, shop->ySpaceshipInfo + 42*i + 70, TextLeft, 15, "PixelFont", Utils_Color_Get(255, 255, 255), &o->window, &o->tm);
        
        memset(str, 0, sizeof str);
        sprintf(str, "- Tier %d", shop->equipedNewEquipement[i]);
        Text_Draw(str, shop->xSpaceshipInfo, shop->ySpaceshipInfo + 42*i + 70 + 18, TextLeft, 15, "PixelFont", Utils_Color_Get(255, 255, 255), &o->window, &o->tm);
    }
}

void Shop_DrawBuyable(Shop * shop, Singleton * o)
{
    for(int i = 0; i < array_size(o->shop.buyableCases); i++)
    {
        ShopCase * buyableCase = array_get_at(o->shop.buyableCases, i);
        Sprite_Draw(&buyableCase->content, -90, 0, 0, &o->window);
    }
    
    if(shop->xCaseSelected != -1 && shop->yCaseSelected != -1)
    {
        Sprite_Draw(&shop->selectedCase, -90, 0, 0, &o->window);
    }
}

void Shop_DrawEquipement(Shop * shop, Singleton * o)
{
    for(int i = 0; i < array_size(o->shop.equipementCases); i++)
    {
        ShopCase * buyableCase = array_get_at(o->shop.equipementCases, i);
        
        Sprite_Draw(&buyableCase->content, -90, 0, 0, &o->window);
    }
}

void Shop_DrawButtons(Shop * shop, Singleton * o)
{
    char str[1024];
    
    if(shop->xCaseSelected != -1 && shop->yCaseSelected != -1)
    {
        Sprite_Draw(&shop->buttonEquipeBuy, -90, 0, 0, &o->window);
        
        if(o->player->buyedEquipement[shop->xCaseSelected][shop->yCaseSelected] == 0)
        {
            memset(str, 0, sizeof str);
            sprintf(str, "Buy");
            Text_Draw(str, shop->buttonEquipeBuy.x + shop->buttonEquipeBuy.w/2, shop->buttonEquipeBuy.y + 20, TextCenter, 25, "PixelFont", Utils_Color_Get(0, 0, 0), &o->window, &o->tm);
        }
        else if(o->player->buyedEquipement[shop->xCaseSelected][shop->yCaseSelected] == 1 && shop->equipedNewEquipement[shop->xCaseSelected] != shop->yCaseSelected + 1)
        {
            memset(str, 0, sizeof str);
            sprintf(str, "Equipe");
            Text_Draw(str, shop->buttonEquipeBuy.x + shop->buttonEquipeBuy.w/2, shop->buttonEquipeBuy.y + 20, TextCenter, 25, "PixelFont", Utils_Color_Get(0, 0, 0), &o->window, &o->tm);
        }
        else
        {
            memset(str, 0, sizeof str);
            sprintf(str, "Equiped");
            Text_Draw(str, shop->buttonEquipeBuy.x + shop->buttonEquipeBuy.w/2, shop->buttonEquipeBuy.y + 20, TextCenter, 25, "PixelFont", Utils_Color_Get(0, 0, 0), &o->window, &o->tm);
        }
    }
    
    Sprite_Draw(&shop->buttonPlay, -90, 0, 0, &o->window);
    Sprite_Draw(&shop->buttonCancel, -90, 0, 0, &o->window);
}

void Shop_DrawSpaceshipPreview(Shop * shop, Singleton * o)
{
    if(shop->spaceshipShop) Spaceship_Draw(shop->spaceshipShop, &o->window, o);
}

void Shop_DrawMoney(Shop * shop, Singleton * o)
{
    char str[1024];
    sprintf(str, "%lld Bolts", o->player->argent);
    Text_Draw(str, shop->xMoney, shop->yMoney - 10, TextRight, 18, "PixelFont", Utils_Color_Get(255, 255, 255), &o->window, &o->tm);
}

void Shop_Draw(Shop * shop, Singleton * o)
{
    if(shop)
    {
        Shop_DrawBackground(shop, o);
        Shop_DrawBuyable(shop, o);
        Shop_DrawEquipement(shop, o);
        Shop_DrawButtons(shop, o);
        Shop_DrawSpaceshipPreview(shop, o);
        Shop_DrawSpaceshipInfo(shop, o);
        Shop_DrawBuyableInfo(shop, o);
        Shop_DrawMoney(shop, o);
        
        Sprite coeur = Sprite_New(4 , o->window.h - 4 - 8, 0, 0, "coeur", &o->tm);
        Sprite_Draw(&coeur, -90, 0, 0, &o->window);
    }
}

