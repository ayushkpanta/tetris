#ifndef UTILS_H
#define UTILS_H

#include <iostream>
using namespace std;

const int BLOCK_DIM = 4;
const int BOARD_WIDTH = 12;
const int BOARD_HEIGHT = 22;

void transpose(char matrix[BLOCK_DIM][BLOCK_DIM], char transpose[BLOCK_DIM][BLOCK_DIM]);
void row_flip(char matrix[BLOCK_DIM][BLOCK_DIM]);
void col_flip(char matrix[BLOCK_DIM][BLOCK_DIM]);
// void print_tetromino(int matrix[BLOCK_DIM][BLOCK_DIM]);
// void print_board(int matrix[BOARD_HEIGHT][BOARD_WIDTH]);
template <int ROWS, int COLS>
void print_matrix(char (&matrix)[ROWS][COLS]) {
        for (int y = 0; y < ROWS; y++) {
            for (int x = 0; x < COLS; x++) {
                cout << matrix[y][x] << ' ';
            }
        cout << endl;
    }
}

#endif