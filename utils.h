#ifndef UTILS_H
#define UTILS_H

#include <iostream>
using namespace std;

const int BLOCK_DIM = 4;
const int BOARD_WIDTH = 10;
const int BOARD_HEIGHT = 20;

void transpose(int matrix[BLOCK_DIM][BLOCK_DIM], int transpose[BLOCK_DIM][BLOCK_DIM]);
void row_flip(int matrix[BLOCK_DIM][BLOCK_DIM]);
void col_flip(int matrix[BLOCK_DIM][BLOCK_DIM]);
// void print_tetromino(int matrix[BLOCK_DIM][BLOCK_DIM]);
// void print_board(int matrix[BOARD_HEIGHT][BOARD_WIDTH]);
template <int ROWS, int COLS>
void print_matrix(int (&matrix)[ROWS][COLS]) {
        for (int y = 0; y < ROWS; y++) {
            for (int x = 0; x < COLS; x++) {
                cout << matrix[y][x] << " ";
            }
        cout << endl;
    }
}

#endif