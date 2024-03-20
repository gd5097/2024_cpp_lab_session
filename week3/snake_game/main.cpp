#include <iostream>
#include <string>
#include <stdlib.h>
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

int snake_pos_x = START_POSITION_X;
int snake_pos_y = START_POSITION_Y;
string test_string;



int tick = 0;

void update_tick();
void update();
void draw();
void draw_wall();
void check_input();
void update_snake_unit_vector(int x, int y);

int main(){
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
    snake_pos_x += snake_unit_vector[0] * MOVE_DISTANCE;
    snake_pos_y += snake_unit_vector[1] * MOVE_DISTANCE;
}

void draw(){
    draw_wall();
    console::draw(snake_pos_x, snake_pos_y, "●");
    console::draw(2, 24, test_string);
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