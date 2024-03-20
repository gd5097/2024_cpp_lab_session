#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "console.h"
#include <vector>

#define TICK_INTERVAL 10
#define BOARD_WIDTH 22
#define BOARD_HEIGHT 22
#define START_POSITION_X 10
#define START_POSITION_Y 10
#define MOVE_DISTANCE 1

using namespace std;


int snake_unit_vector[2] = {1, 0};

int snake_head_position[2] = {START_POSITION_X, START_POSITION_Y};
int apple_position[2];

string test_string;



int tick = 0;

void init();
void update_tick();
void update();
void draw();
void draw_wall();
void check_input();
void update_snake_unit_vector(int x, int y);
void draw_snake();
bool snake_eat_apple();
void set_apple_position();

int main(){
    srand(time(NULL));

    init();
    console::init();


    while(true){
        console::clear();

        check_input();

        

        update_tick();
        if(tick == 0){
            update();    
        }
        draw();

        console::wait();
    }

    
    return 0;
}

void init(){
    set_apple_position();
}

void set_apple_position(){
    apple_position[0] = rand % (BOARD_WIDTH - 2) + 1;
    apple_position[1] = rand % (BOARD_WIDTH - 2) + 1;
}

void check_input(){
    if(console::key(console::K_NONE)){
        test_string = "NONE";
    }
    else if (console::key(console::K_OTHER)){
        test_string = "OTHER";
    }
    else if (console::key(console::K_LEFT)){
        update_snake_unit_vector(-1, 0);
        
    }
    else if (console::key(console::K_RIGHT)){
        update_snake_unit_vector(1, 0);
    }
    else if (console::key(console::K_UP)){
        update_snake_unit_vector(0, -1);
    }
    else if (console::key(console::K_DOWN)){
        update_snake_unit_vector(0, 1);
    }
    else if (console::key(console::K_ESC)){
        test_string = "ESC";
        exit(1);
    }
}

void update_tick(){

    tick = (tick + 1) % TICK_INTERVAL;
}

void update(){
    snake_head_position[0] += snake_unit_vector[0] * MOVE_DISTANCE;
    snake_head_position[1] += snake_unit_vector[1] * MOVE_DISTANCE;

    // if(snake_eat_apple){
        
    // }
}

void draw(){
    draw_wall();
    draw_snake();
    console::draw(2, 24, test_string);
}

bool snake_eat_apple(){

    return true;
}

void draw_snake(){
    console::draw(snake_head_position[0], snake_head_position[1], "●");
}

void draw_wall(){
    for(int i = 0; i < BOARD_WIDTH; i++){
        /* Draw horizon wall */
        console::draw(i, 0, "◼︎");
        console::draw(i, BOARD_HEIGHT - 1, "◼︎");
        /* Draw vertical wall */
        if(i == BOARD_WIDTH - 1){
            // For perfect board draw, doesn't draw last line
            break;
        }
        console::draw(0, i, "◼︎");
        console::draw(BOARD_WIDTH - 1, i, "◼︎");
    }   
}

void update_snake_unit_vector(int x, int y){    
    snake_unit_vector[0] = x;
    snake_unit_vector[1] = y;
}