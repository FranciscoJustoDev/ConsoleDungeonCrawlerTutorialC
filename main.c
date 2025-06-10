#include "engine.h"

char *weapon_names[] = {
    "Sword",
    "Axe",
    "Club"};

char *armor_names[] = {
    "Chestplate",
    "Leggings",
    "Helmet"};

char *potion_names[] = {
    "Health Potion",
    "Attack Potion"};

void check_values(Player player);
void fighting(Player player, Room *current_room);

int current_level = 1;
int game_running = 1;


int main(int argc, char *argv[]){
    srand(time(NULL));
    printf("Console game!\n");
    Room *current_room;

    Player player;
    strcpy(player.name, "Player");
    player.health = 100;
    player.max_health = 100;
    player.attack = 5;
    player.weapon_slot = NO_ITEM;
    player.armor_slot = NO_ITEM;
    player.potion_slot = NO_ITEM;
    player.inventory_len = 0;
    
    while(game_running){
        current_room = create_room(current_level);
        
        if(current_room->type == ROOM_FIGHTING){
            check_values(player);
            fighting(player, current_room);
        }else if(current_room->type == ROOM_TREASURE){
            int rand_num = rand() % 3;
            if(rand_num == 0){
                player.weapon_slot = give_weapon();
                printf("You got a %s!\n", weapon_names[player.weapon_slot]);
            }else if(rand_num == 1){
                player.armor_slot = give_armor();
                printf("You got a %s!\n", armor_names[player.armor_slot]);
            }else if(rand_num == 2){
                player.potion_slot = give_potion();
                printf("You got a %s!\n", potion_names[player.potion_slot]);
            }
        }else if(current_room->type == ROOM_RESTING){
            int health = player.max_health / (current_level + 2);
            player.health += health;
            if(player.health > player.max_health){
                player.health = player.max_health;
            }
            printf("You recovered %d of your health back!\n", health);
            getchar();
        }

        destroy_room(current_room);
        current_level++;
    }
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

void fighting(Player player, Room *current_room){
    int enemies_left = 1;
    while(enemies_left){
        printf("Level: -%d\n", current_level);
        printf("Health: %d\n", player.health);
        printf("Attack: %d\n", player.attack);
        printf("Weapon slot: %s\n", weapon_names[player.weapon_slot]);
        printf("\n");
        printf("-----------------\n");
        printf("Room name: %s\n", current_room->name);
        printf("Room type: %d\n", current_room->type);
        for(int i = 0; i < current_room->enemies_len; i++){
            printf("Enemy: %s\n", current_room->enemies[i].name);
        }
        printf("-----------------\n");
        char user_input[INPUT_BUFFER_MAX];
        if(scanf("%31s", user_input) != 1){    
            fprintf(stderr, "user_input_error!\n");
            continue;
        }

        printf("Options\n");
        printf("attack\n");
        printf("use\n");
        printf("quit\n");
        if(strcmp(user_input, "quit") == 0){
            game_running = 0;
            break;
        }else if(strcmp(user_input, "attack") == 0){
            printf("Attacking\n");
        }else if(strcmp(user_input, "use") == 0){
            printf("Using\n");
        }
    }
}