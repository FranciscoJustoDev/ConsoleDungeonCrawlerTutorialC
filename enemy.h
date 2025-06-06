#ifndef ENEMY_H
#define ENEMY_H

#include "engine.h"

#define ENEMY_NAME_BUFFER_MAX 16

typedef struct {
    char name[ENEMY_NAME_BUFFER_MAX];
    int health;
    int attack;
    WeaponID weapon_slot;
    ArmorID armor_slot;
} Enemy;

#endif