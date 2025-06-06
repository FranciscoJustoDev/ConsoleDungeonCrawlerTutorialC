#include "rooms.h"

Room *create_room(int current_level){
    Room *new_room = malloc(sizeof(Room));
    new_room->enemies = NULL;
    new_room->enemies_len = 0;
    new_room->type = rand() % 3;

    if(new_room->type == ROOM_FIGHTING){
        strcpy(new_room->name, "Arena");
        new_room->enemies_len = (rand() % 3) + 1;
        new_room->enemies = malloc(sizeof(Enemy) * new_room->enemies_len);
        for(int e = 0; e < new_room->enemies_len; e++){
            strcpy(new_room->enemies[e].name, "Enemy");
            new_room->enemies[e].health = (100 * current_level) / 10;
            new_room->enemies[e].attack = (2 * current_level) / 5;
        }
    }else if(new_room->type == ROOM_TREASURE){
        strcpy(new_room->name, "Treasure");
    }else if(new_room->type == ROOM_RESTING){
        strcpy(new_room->name, "Bonfire");
    }
    return new_room;
}

void destroy_room(Room *room){
    if(room->type == ROOM_FIGHTING){
        free(room->enemies);
    }
    free(room);
}