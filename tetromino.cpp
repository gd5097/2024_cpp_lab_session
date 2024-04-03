#include "tetromino.h"
#include <string>

Tetromino::Tetromino(int size, std::string shape)
{
    size_ = size;

    for (int i = 0; i < size * size; i++)
    {
        int row = i / size;
        int col = i % size;

        shape_[row][col] = shape[i] == 'O' ? true : false;
    }
}

Tetromino Tetromino::I(4, "XXXXOOOOXXXXXXXX");
Tetromino Tetromino::O(2, "OOOO");
Tetromino Tetromino::T(3, "XOXOOOXXX");
Tetromino Tetromino::S(3, "XXXXOOOOX");
Tetromino Tetromino::Z(3, "XXXOOXXOO");
Tetromino Tetromino::J(3, "OXXOOOXXX");
Tetromino Tetromino::L(3, "XXOOOOXXX");

void Tetromino::drawAt(int x, int y)
{
}