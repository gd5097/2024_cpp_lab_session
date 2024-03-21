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
#define SCORE_INCREASE_SIZE 10
#define MAX_TAILS ((BOARD_HEIGHT - 2) * (BOARD_WIDTH - 2))

using namespace std;


int snake_unit_vector[2] = {1, 0};

int snake_head_position[2] = {START_POSITION_X, START_POSITION_Y};
int snake_tails_positions[2][MAX_TAILS];
int snake_footprint_buffer[2];
int snake_tail_length = 0;
int apple_position[2];

string test_string;


int game_score = 0;
bool game_over = false;
int tick = 0;

void init();
void update_tick();
void update();
void update_game_score();
void draw();
void draw_wall();
void draw_apple();
void check_input();
void update_snake_unit_vector(int x, int y);
void draw_snake();
bool snake_eat_apple();
void set_apple_position();
void update_snake_position();
bool is_apple_overlap_snake();
void create_apple_position();
void draw_score();
bool is_game_over();
bool collision_with_wall();
bool collision_with_body();
void draw_game_over_banner();

int main(){
    srand(time(NULL));

    init();
    console::init();

    while(true){
        console::clear();

        check_input();
        if(game_over){
            draw();            
            console::wait();
            continue;
        }

        update_tick();
        if(tick == 0){
            update();    
        }
        draw();
        

        console::wait();
    }

    
    return 0;
}

void draw_game_over_banner(){
    string message1 = "YOU LOSE!";
    string message2 = "PRESS \'ENTER\'";
    string message3 =  "TO RESTART";

    console::draw(BOARD_WIDTH/2 - message1.length()/2, BOARD_HEIGHT/2, message1);
    console::draw(BOARD_WIDTH/2 - message2.length()/2, BOARD_HEIGHT/2 + 1, message2);
    console::draw(BOARD_WIDTH/2 - message3.length()/2, BOARD_HEIGHT/2 + 2, message3);
}

void init(){
    set_apple_position();
    tick = 0;
    game_score = 0;
    snake_tail_length = 0;
    game_over = false;
    snake_unit_vector[0] = 1;
    snake_unit_vector[1] = 0;
    snake_head_position[0] = START_POSITION_X;
    snake_head_position[1] = START_POSITION_Y;
}


void set_apple_position(){
    while(true){
        create_apple_position();
        if(!is_apple_overlap_snake()){
            break;
        }
    }
}

void create_apple_position(){
    apple_position[0] = rand() % (BOARD_WIDTH - 2) + 1;
    apple_position[1] = rand() % (BOARD_WIDTH - 2) + 1;    
}

bool is_apple_overlap_snake(){
    if(apple_position[0] == snake_head_position[0] && apple_position[1] == snake_head_position[1]){
        return true;
    }
    return false;
}

void check_input(){
    if(console::key(console::K_NONE)){        
    }
    else if (console::key(console::K_OTHER)){        
    }
    else if (console::key(console::K_ESC)){        
        exit(1);
    }
    else if (console::key(console::K_ENTER)){        
        init();
    }
    else if (console::key(console::K_LEFT)){
        if(!(snake_tail_length > 0 && snake_head_position[0] - 1 == snake_tails_positions[0][0] && snake_head_position[1] == snake_tails_positions[1][0] )){
            update_snake_unit_vector(-1, 0);
        }        
    }
    else if (console::key(console::K_RIGHT)){
        if(!(snake_tail_length > 0 && snake_head_position[0] + 1 == snake_tails_positions[0][0] && snake_head_position[1] == snake_tails_positions[1][0] )){
            update_snake_unit_vector(1, 0);
        }
    }
    else if (console::key(console::K_UP)){
        if(!(snake_tail_length > 0 && snake_head_position[0] == snake_tails_positions[0][0] && snake_head_position[1] - 1 == snake_tails_positions[1][0] )){
            update_snake_unit_vector(0, -1);
        }
    }
    else if (console::key(console::K_DOWN)){
        if(!(snake_tail_length > 0 && snake_head_position[0] == snake_tails_positions[0][0] && snake_head_position[1] + 1 == snake_tails_positions[1][0] )){
            update_snake_unit_vector(0, 1);
        }
    }
}

void update_tick(){

    tick = (tick + 1) % TICK_INTERVAL;
}

void update(){
    
    update_snake_position();
    if(is_game_over()){   
        game_over = true;
    }

    if(snake_eat_apple()){
        set_apple_position();
        snake_tail_length += 1;
        update_game_score();
    }
}

bool is_game_over(){
    if(collision_with_wall() || collision_with_body()){
        return true;
    }
    return false;
}

bool collision_with_body(){
    for(int i = 0; i < snake_tail_length; i++){
        if(snake_head_position[0] == snake_tails_positions[0][i] && snake_head_position[1] == snake_tails_positions[1][i]){            
            return true;
        }
    }
    return false;
}

bool collision_with_wall(){
    if(snake_head_position[0] == 0 || snake_head_position[1] == 0 || snake_head_position[0] == BOARD_WIDTH - 1 || snake_head_position[1] == BOARD_HEIGHT - 1){
        return true;
    }
    return false;
}

void update_snake_position(){
    /* Update tails */
    for(int i = snake_tail_length; i > 0; i--){
        snake_tails_positions[0][i] = snake_tails_positions[0][i - 1];
        snake_tails_positions[1][i] = snake_tails_positions[1][i - 1];
    }
    snake_tails_positions[0][0] = snake_head_position[0];
    snake_tails_positions[1][0] = snake_head_position[1];
    /* Update head */
    snake_head_position[0] += snake_unit_vector[0] * MOVE_DISTANCE;
    snake_head_position[1] += snake_unit_vector[1] * MOVE_DISTANCE;
}

void update_game_score(){
    game_score += SCORE_INCREASE_SIZE;
}

void draw(){
    draw_wall();
    draw_snake();
    draw_apple();
    draw_score();
    if(game_over){
        draw_game_over_banner();
    }
}

void draw_score(){
    string output_string = "Score : " + to_string(game_score);
    console::draw(2, 24, output_string);
}

bool snake_eat_apple(){
    if(snake_head_position[0] == apple_position[0] && snake_head_position[1] == apple_position[1]){
            return true;
        }

    return false;
}

void draw_apple(){
    console::draw(apple_position[0], apple_position[1], "★");
}

void draw_snake(){
    /* Draw head */
    console::draw(snake_head_position[0], snake_head_position[1], "●");
    /* Draw tails */
    for(int i = 0; i < snake_tail_length; i++){
        console::draw(snake_tails_positions[0][i],snake_tails_positions[1][i], "○");
    }
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