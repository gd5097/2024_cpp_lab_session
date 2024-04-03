#include "game.h"
#include "console/console.h"
#include <string>

Game::Game(){

}

void Game::draw(){
    console::clear();
    console::drawBox(0, 0, 11, 21);



}

void Game::update(){
    handle_input();

}

bool Game::shouldExit(){
    return false;
}

void Game::handle_input(){
    if(console::key(console::K_ESC)){        
        exit(1);
    }
    if(console::key(console::K_LEFT)){
        console::log("test");
    }
}