#ifndef PLAYER_H
#define PLAYER_H

#include "engine.h"

#define PLAYER_NAME_BUFFER_MAX 32

typedef struct {
    char name[PLAYER_NAME_BUFFER_MAX];
    int health;
    int max_health;
    int attack;
    WeaponID weapon_slot;
    ArmorID armor_slot;
    PotionID potion_slot;
    int inventory_len;
} Player;

WeaponID give_weapon();
ArmorID give_armor();
PotionID give_potion();

#endif