#ifndef ENGINE_H
#define ENGINE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// settings
#define INPUT_BUFFER_MAX 32
#define NO_ITEM -1

typedef enum {
    WEAPON_SWORD,
    WEAPON_AXE,
    WEAPON_CLUB,
    WEAPON_COUNT
} WeaponID;

typedef enum {
    ARMOR_CHESTPLATE,
    ARMOR_LEGGINGS,
    ARMOR_HELMET,
    ARMOR_COUNT
} ArmorID;

typedef enum {
    POTION_HEALTH,
    POTION_ATTACK,
    POTION_COUNT
} PotionID;

#include "enemy.h"
#include "rooms.h"
#include "player.h"

#endif