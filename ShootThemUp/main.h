//
//  main.h
//  ShootThemUp
//
//  Created by El-idrissi Elyas on 04/12/2019.
//  Copyright © 2019 El-idrissi Elyas. All rights reserved.
//
//-------------------------------------------[]-------------------------------------------//
#ifndef main_h
#define main_h

#include <time.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>

#include "Hashmap.h"
#include "map.h"
#include "array.h"

static bool DEBUG_SPRITE_BOX = 0;
static bool DEBUG_SPACESHIP_BOX = 0;

static bool DEBUG_TEXTURE_LOAD = 0;

typedef enum TeamType {NOTEAM, PLAYER, ENEMY} TeamType;

//----------------------------------------[Sprite]----------------------------------------//

typedef struct Sprite
{
    char textureId[1024];
    SDL_Texture * texture;
    
    float x;
    float y;
    int h;
    int w;
    
    int hFrame;
    int wFrame;
    
    float xOffSet;
    float yOffSet;
    
    float indexFrame;
    int maxFrame;
    
} Sprite;

//----------------------------------------[Utils]-----------------------------------------//

typedef struct Utils Utils;
typedef struct Timer
{
    float begin;
    float end;
    
} Timer;

//----------------------------------------[PointF]----------------------------------------//

typedef struct PointF
{
    float x;
    float y;
    
} PointF;

//-----------------------------------------[Body]-----------------------------------------//

typedef enum BodyType {NoBody, BodyTier1, BodyTier2, BodyTier3, BodyTier4, BodyTier5} BodyType;
typedef struct Body
{
    BodyType type;
    
    float x;
    float y;
    int w;
    int h;
    
    float angle;
    
    PointF slotPos;
    
    Sprite sprite;
    
    float lifeMax;
    float life;
    
} Body;

//----------------------------------------[Reactor]---------------------------------------//

typedef enum ReactorType {NoReactor, ReactorTier1, ReactorTier2, ReactorTier3, ReactorTier4, ReactorTier5} ReactorType;
typedef struct Reactor
{
    ReactorType type;
    
    float x;
    float y;
    
    int w;
    int h;
    
    float angle;
    
    PointF slotPos;
    
    Sprite sprite;
    Sprite spriteFlame;
    
    float lifeMax;
    float life;
    float speed;
    
    
} Reactor;

//----------------------------------------[Weapon]----------------------------------------//

typedef enum WeaponType {NoWeapon, WeaponTier1, WeaponTier2, WeaponTier3, WeaponTier4, WeaponTier5} WeaponType;
typedef struct Weapon
{
    WeaponType type;
    
    float x;
    float y;
    int w;
    int h;
    
    float angle;
    
    PointF slotPos;
    PointF slotPosBullet;
    
    Sprite sprite;
    
    float lifeMax;
    float life;
    float cooldownMax;
    float cooldown;
    float damage;
    float speedBullet;
    
} Weapon;

//-----------------------------------------[Turret]----------------------------------------//

typedef enum TurretType {NoTurret, TurretTier1, TurretTier2, TurretTier3, TurretTier4, TurretTier5} TurretType;
typedef struct Turret
{
    TurretType type;
    float x;
    float y;
    int w;
    int h;
    
    float angle;
    
    PointF slotPos;
    
    Sprite sprite;
    
    void * cible;
    
    bool isManual;
    float speedRotation;
    float lifeMax;
    float life;
    float cooldownMax;
    float cooldown;
    float damage;
    float speedBullet;
    
} Turret;

//-----------------------------------------[Shied]----------------------------------------//

typedef enum ShieldType {NoShield, ShieldTier1, ShieldTier2, ShieldTier3, ShieldTier4, ShieldTier5} ShieldType;
typedef enum ShieldEffectType {NoShieldEffectPercentageEffect, ReductionEffect, InvincibilityEffect} ShieldEffectType;
typedef struct Shield
{
    ShieldType type;
    float x;
    float y;
    int w;
    int h;
    
    float angle;
    
    PointF slotPos;
    
    Sprite sprite;
    
    bool isActivated;
    float lifeMax;
    float life;
    float cooldownMax;
    float cooldown;
    float lifeTimeMax;
    float lifeTime;
    
} Shield;

//-----------------------------------------[Bullet]-----------------------------------------//

typedef enum BulletType {NoBullet, BulletMainWeapon, BulletSecondaryWeapon, BulletTurret, BulletMainWeaponSpe, BulletSecondaryWeaponSpe, BulletTurretSpe} BulletType;
typedef enum BulletEffectType {NoBulletEffect, ExplosiveEffect} BulletEffectType;

typedef struct Bullet
{
    BulletType type;
    
    TeamType teamType;
    
    char id[1024];
    
    float x;
    float y;
    int w;
    int h;
    
    float angle;
    
    BulletEffectType effectType;
    float damage;
    float speed;
    float timeLife;
    
    Sprite sprite;
    Sprite spriteFlame;
    
} Bullet;

//---------------------------------------[Explosion]--------------------------------------//

typedef struct Explosion
{
    TeamType teamType;
    
    float x;
    float y;
    int w;
    int h;
    
    float damage;
    
    Sprite sprite;
    
} Explosion;

//---------------------------------------[Spaceship]--------------------------------------//

typedef struct SpaceshipSlot
{
    PointF spaceshipPos;
    
    PointF reactorPos;
    PointF reactorSecondaryOnePos;
    PointF reactorSecondaryTwoPos;
    
    PointF weaponMainPos;
    PointF weaponSecondaryOnePos;
    PointF weaponSecondaryTwoPos;
    
    PointF turretPos;
    
} SpaceshipSlot;

typedef enum SpaceshipType {NoSpaceship, SpaceshipTier1, SpaceshipTier2, SpaceshipTier3, SpaceshipTier4, SpaceshipTier5} SpaceshipType;
typedef struct Spaceship
{
    SpaceshipType type;
    
    float x;
    float y;
    int w;
    int h;
    
    float angle;
    
    SpaceshipSlot slotsPos;
    
    float totalLifeMax;
    float totalLife;
    
    Body * body;
    
    Reactor * reactor;
    Reactor * reactorSecondaryOne;
    Reactor * reactorSecondaryTwo;
    
    Weapon * weaponMain;
    Weapon * weaponSecondaryOne;
    Weapon * weaponSecondaryTwo;
    
    Shield * shield;
    
    Turret * turret;
    
    Sprite blackSmock;
    
} Spaceship;

//----------------------------------------[Player]----------------------------------------//

typedef struct Player
{
    char id[1024];
    
    int missed;
    int score;
    long long int argent;
    
    int buyedEquipement[7][5];
    int equipedEquipement[7];
    
    Spaceship * spaceship;
    
} Player;

//-----------------------------------------[Enemy]----------------------------------------//

typedef enum EnemyType {EnemyNormal, EnemyTank, EnemyScout, EnemySniper, EnemyArtificer, EnemyTurret, EnemySoldier} EnemyType;

typedef struct Enemy
{
    char id[1024];
    
    int chanceWeaponMain;
    int chanceWeaponSecondary;
    int chanceTurret;
    
    EnemyType enemyType;
    
    Spaceship * spaceship;
    
} Enemy;

//----------------------------------------[Event]-----------------------------------------//

typedef struct Event
{
    SDL_Event e;
    const Uint8 * KeyStates;
    bool mouseCanClick;
    int Xmouse;
    int Ymouse;
    int mouseCooldown;
    
} Event;

//-----------------------------------------[Text]-----------------------------------------//
typedef enum TextAlign {TextCenter, TextLeft, TextRight} TextAlign;

typedef struct Text
{
    float x;
    float y;
    int w;
    int h;
    
    char str[1024];
    int fontSize;
    char fontKey[1024];
    TTF_Font * font;
    SDL_Color color;
    
} Text;

//----------------------------------------[Window]----------------------------------------//

typedef struct Window
{
    SDL_Window * window;
    SDL_Renderer * renderer;
    char title[1024];
    int w;
    int h;
    SDL_Color defaultColor;
    
} Window;

//-----------------------------------------[Play]-----------------------------------------//

typedef struct Play
{
    int xPlayerSpaceship;
    int yPlayerSpaceship;
    
    int xPlayerBar;
    int yPlayerBar;
    
    bool inMenuDead;
    bool inMenuPause;
    
    float nextLevelMessageTimeLife;
    bool isNextLevelMessage;
    
    int level;
    
    int summonedEnemy;
    int destroyedEnemy;
    int destroyedEnemyByPlayer;
    
    int levelOld;
    int summonedEnemyOld;
    int destroyedEnemyOld;
    int destroyedEnemyByPlayerOld;
    
    int enemyPerLevel;
    
    Sprite barTop;
    Sprite barBottom;
    Sprite buttonPause;
    
    Sprite background;
    
} Play;


//-----------------------------------------[Game]-----------------------------------------//

typedef enum GameSection {ShopPhase, PlayPhase} GameSection;

typedef struct Game
{
    bool isRunning;
    float fps;
    
    GameSection gamePhase;
    
} Game;

//--------------------------------------[PlayerBar]---------------------------------------//

typedef struct PlayerBar
{
    float x;
    float y;
    int w;
    int h;
    
    Sprite GUI;
    
    float lifeBarSize;
    float shieldTimeBarSize;
    float shieldLifeBarSize;
    float weaponMainCooldownBarSize;
    float weaponSecondaryCooldownBarSize;
    float turretCooldownBarSize;
    
    Sprite lifeBar;
    Sprite shieldTimeBar;
    Sprite shieldLifeBar;
    Sprite weaponMainCooldownBar;
    Sprite weaponSecondaryCooldownBar;
    Sprite turretCooldownBar;
    
} PlayerBar;

//--------------------------------------[MenuPause]--------------------------------------//

typedef struct MenuPause
{
    float x;
    float y;
    
    float timeLeft;
    
    Sprite background;
    Sprite resume;
    Sprite restart;
    Sprite quit;
    
} MenuPause;

//--------------------------------------[MenuDead]---------------------------------------//

typedef struct MenuDead
{
    float x;
    float y;
    
    Sprite background;
    Sprite retry;
    Sprite shop;
    Sprite quit;
    
} MenuDead;

//--------------------------------------[Shop]---------------------------------------//

typedef struct ShopCase
{
    float x;
    float y;
    
    int w;
    int h;
    
    Sprite content;
    
    int xCase;
    int yCase;
    
} ShopCase;

typedef struct Shop
{
    Sprite background;
    
    int xSpaceshipPreview;
    int ySpaceshipPreview;
    int wSpaceshipPreview;
    int hSpaceshipPreview;
    
    int xSpaceshipInfo;
    int ySpaceshipInfo;
    
    int xStartEquipementEquipedCase;
    int yStartEquipementEquipedCase;
    int xOffEquipementEquiped;
    int yOffEquipementEquiped;
    int yOffBodyEquiped;
    
    int xStartBuyableCase;
    int yStartBuyableCase;
    int xOffBuyableCase;
    int yOffBuyableCase;
    
    int xStartBuyableInfo;
    int yStartBuyableInfo;
    
    int xStartBuyableInfoTitle;
    int yStartBuyableInfoTitle;
    
    int wCaseLittle;
    int hCaseLittle;
    
    int xMoney;
    int yMoney;
    
    Array * buyableCases;
    Array * equipementCases;
    
    Spaceship * spaceshipShop;
    
    int xCaseSelected;
    int yCaseSelected;
    
    Sprite buttonEquipeBuy;
    Sprite buttonPlay;
    Sprite buttonCancel;
    Sprite selectedCase;
    
    int equipedNewEquipement[7];
    int priceEquipement[7][5];
    
    char nameEquipement[7][1024];
    
} Shop;

//-------------------------------------[LevelManager]-------------------------------------//

typedef struct LevelManager
{
    int level;
    float multiLife;
    float multiSpeed;
    float multiDefault;
    int levelUnit;
    
} LevelManager;

//------------------------------------[TextureManager]------------------------------------//

typedef struct SpriteSheet
{
    bool isAnimated;
    int wFrame;
    int hFrame;
    int nbrOfFrame;
    
    SDL_Texture * texture;
    
} SpriteSheet;

typedef map_t(SpriteSheet) SpriteSheets;
typedef map_t(TTF_Font *) Fonts;

typedef struct TextureManager
{
    SpriteSheets allSpriteSheet;
    Fonts allFont;
    
} TextureManager;

//------------------------------------[PatternManager]------------------------------------//

typedef map_t(SpaceshipSlot) SpaceshipSlotsPatterns;
typedef map_t(Body) BodyPatterns;
typedef map_t(Weapon) WeaponPatterns;
typedef map_t(Reactor) ReactorPatterns;
typedef map_t(Turret) TurretPatterns;
typedef map_t(Shield) ShieldPatterns;
typedef map_t(Bullet) BulletPatterns;

typedef struct PatternManager
{
    SpaceshipSlotsPatterns allspaceshipSlotPatterns;
    
    BodyPatterns allBodyPatterns;
    
    ReactorPatterns allReactorPatterns;
    
    WeaponPatterns allWeaponPatterns;
    WeaponPatterns allWeaponSecondaryPatterns;
    
    TurretPatterns allTurretPatterns;
    
    ShieldPatterns allShieldPatterns;
    
    BulletPatterns allBulletPatterns;
    
    
    float body_Life[5];
    
    float reactor_Life[5];
    float reactor_Speed[5];
    
    float weaponM_Life[5];
    float weaponM_Damage[5];
    float weaponM_SpeedBullet[5];
    float weaponM_Cooldown[5];
    
    float weaponS_Life[5];
    float weaponS_Damage[5];
    float weaponS_SpeedBullet[5];
    float weaponS_Cooldown[5];
    
    float turret_Life[5];
    float turret_Damage[5];
    float turret_SpeedBullet[5];
    float turret_Cooldown[5];
    float turret_SpeedRotation[5];
    
    float shield_Life[5];
    float shield_LifeTime[5];
    float shield_Cooldown[5];
    
} PatternManager;

//---------------------------------[CompatibilityManager]---------------------------------//

typedef map_t(SpaceshipType) HashMap_SpaceshipTypeCompatible;

typedef map_t(WeaponType) HashMap_WeaponTypeCompatible;
typedef map_t(HashMap_WeaponTypeCompatible) HashMap_SpaceshipTypeWithWeaponType;
typedef map_t(HashMap_SpaceshipTypeCompatible) HashMap_WeaponTypeWithSpaceshipType;

typedef map_t(BodyType) HashMap_BodyTypeCompatible;
typedef map_t(HashMap_BodyTypeCompatible) HashMap_SpaceshipTypeWithBodyType;
typedef map_t(HashMap_SpaceshipTypeCompatible) HashMap_BodyTypeWithSpaceshipType;

typedef map_t(ReactorType) HashMap_ReactorTypeCompatible;
typedef map_t(HashMap_ReactorTypeCompatible) HashMap_SpaceshipTypeWithReactorType;
typedef map_t(HashMap_SpaceshipTypeCompatible) HashMap_ReactorTypeWithSpaceshipType;

typedef map_t(ShieldType) HashMap_ShieldTypeCompatible;
typedef map_t(HashMap_ShieldTypeCompatible) HashMap_SpaceshipTypeWithShieldType;
typedef map_t(HashMap_SpaceshipTypeCompatible) HashMap_ShieldTypeWithSpaceshipType;

typedef map_t(BulletType) HashMap_BulletTypeCompatible;
typedef map_t(HashMap_BulletTypeCompatible) HashMap_WeaponTypeWithBulletType;
typedef map_t(HashMap_WeaponTypeCompatible) HashMap_BulletTypeWithWeaponType;

typedef struct CompatibilityManager
{
    HashMap_SpaceshipTypeWithWeaponType spaceshipWithWeapon;
    HashMap_WeaponTypeWithSpaceshipType weaponWithSpaceship;
    
    HashMap_SpaceshipTypeWithBodyType spaceshipWithBody;
    HashMap_BodyTypeWithSpaceshipType bodyWithSpaceship;
    
    HashMap_SpaceshipTypeWithReactorType spaceshipWithReactor;
    HashMap_ReactorTypeWithSpaceshipType reactorWithSpaceship;
    
    HashMap_SpaceshipTypeWithShieldType spaceshipWithShield;
    HashMap_ShieldTypeWithSpaceshipType shieldWithSpaceship;
    
    HashMap_WeaponTypeWithBulletType weaponWithBullet;
    HashMap_BulletTypeWithWeaponType bulletWithWeapon;
    
} CompatibilityManager;

typedef struct Star
{
    int x;
    int y;
    int size;
    
} Star;

//---------------------------------------[Singleton]--------------------------------------//

typedef struct Singleton
{
    Window window;
    Game game;
    Play play;
    TextureManager tm;
    PatternManager pm;
    LevelManager lm;
    
    Event event;
    
    Player * player;
    Array * bullets;
    Array * texts;
    Array * enemy;
    Array * explosions;
    Array * starsFar;
    Array * starsMidway;
    Array * starsNear;
    
    PlayerBar playerBar;
    Shop shop;
    MenuDead menuDead;
    MenuPause menuPause;
    
} Singleton;

#endif /* main_h */
