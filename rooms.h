#ifndef ROOMS_H
#define ROOMS_H

#include "engine.h"

#define ROOM_NAME_BUFFER_MAX 16
#define ROOM_MAX_ENEMIES 3

typedef enum {
    ROOM_FIGHTING,
    ROOM_TREASURE,
    ROOM_RESTING,
    ROOM_COUNT
} RoomTypeID;

typedef struct {
    char name[ROOM_NAME_BUFFER_MAX];
    RoomTypeID type;
    Enemy *enemies;
    int enemies_len;
} Room;

Room *create_room(int current_level);
void destroy_room(Room *room);

#endif