#include "game.h"
#include "console/console.h"

Game::Game(){

}

void Game::draw(){
    console::clear();
    console::drawBox(0, 0, 11, 21);



}

void Game::update(){
    
}

bool Game::shouldExit(){
    return false;
}
