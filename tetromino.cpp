#include "tetromino.h"
#include <string>

Tetromino::Tetromino(int size, std::string shape){
    size_ = size;
    
    for(int row = 0; row < size; row++){
        for(int col = 0; col < size; col++){
            shape_[row][col] = 
        }
    }

}

Tetromino Tetromino::I(4, "XXXXOOOOXXXXXXXX");
Tetromino Tetromino::O(2, "OOOO");
Tetromino Tetromino::T(3, "XOXOOOXXX");
Tetromino Tetromino::S(3, "XXXXOOOOX");
Tetromino Tetromino::Z(3, "XXXOOXXOO");
Tetromino Tetromino::J(3, "OXXOOOXXX");
Tetromino Tetromino::L(3, "XXOOOOXXX");

void Tetromino::drawAt(int x, int y){

}