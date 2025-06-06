#include "player.h"

WeaponID give_weapon(){
    return (rand() % WEAPON_COUNT);
}

ArmorID give_armor(){
    return (rand() % ARMOR_COUNT);
}

PotionID give_potion(){
    return (rand() % POTION_COUNT);
}