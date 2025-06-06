#include "engine.h"

char *weapon_names[] = {
    "Sword",
    "Axe",
    "Club"};

void check_values(Player player);

int main(int argc, char *argv[]){
    srand(time(NULL));
    printf("Console game!\n");
    Room *current_room;
    int current_level = 1;

    Player player;
    strcpy(player.name, "Player");
    player.health = 100;
    player.max_health = 100;
    player.attack = 5;
    player.weapon_slot = NO_ITEM;
    player.armor_slot = NO_ITEM;
    player.potion_slot = NO_ITEM;

    player.weapon_slot = give_weapon();

    while(1){
        player.health = player.max_health;
        current_room = create_room(current_level);
        printf("Level: -%d\n", current_level);
        printf("Health: %d\n", player.health);
        printf("Attack: %d\n", player.attack);
        printf("Weapon slot: %s\n", weapon_names[player.weapon_slot]);
        printf("\n");
        printf(LINE_TEXT);
        printf("Room name: %s\n", current_room->name);
        printf("Room type: %d\n", current_room->type);
        if(current_room->type == ROOM_FIGHTING){
            check_values(player);
            int enemies_left = 1;
            while(enemies_left){
                printf("Level: -%d\n", current_level);
                printf("Health: %d\n", player.health);
                printf("Attack: %d\n", player.attack);
                printf("Weapon slot: %s\n", weapon_names[player.weapon_slot]);
                printf("\n");
                printf(LINE_TEXT);
                printf("Room name: %s\n", current_room->name);
                printf("Room type: %d\n", current_room->type);
                for(int i = 0; i < current_room->enemies_len; i++){
                    printf("Enemy: %s\n", current_room->enemies[i].name);
                }
                printf(LINE_TEXT);
                char user_input[INPUT_BUFFER_MAX];
                scanf("%s", &user_input);

                printf("Options\n");
                printf("attack\n");
                printf("use\n");
                printf("quit\n");
                if(strcmp(user_input, "quit") == 0){
                    break;
                }else if(strcmp(user_input, "attack")){
                    //
                }else if(strcmp(user_input, "use")){
                    //
                }
            }
        }
        printf(LINE_TEXT);
        char user_input[INPUT_BUFFER_MAX];
        scanf("%s", &user_input);

        if(strcmp(user_input, "quit") == 0){
            break;
        }

        destroy_room(current_room);
        current_level++;
    }

    destroy_room(current_room);
    return 0;
}

void check_values(Player player){
    if(player.armor_slot != NO_ITEM){
        if(player.armor_slot == ARMOR_CHESTPLATE){
            player.health += 50;
        }else if(player.armor_slot == ARMOR_LEGGINGS){
            player.health += 30;
        }else if(player.armor_slot == ARMOR_HELMET){
            player.health += 20;
        }
    }
}