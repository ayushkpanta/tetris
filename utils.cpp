#include "utils.h"
#include <iostream>
using namespace std;


void transpose(int matrix[BLOCK_DIM][BLOCK_DIM], int transpose[BLOCK_DIM][BLOCK_DIM]) {
    for (int y = 0; y < BLOCK_DIM; y++) {
        for (int x = 0; x < BLOCK_DIM; x++){
            transpose[y][x] = matrix[y][x];
        }
    }
}

void row_flip(int matrix[BLOCK_DIM][BLOCK_DIM]) {
    for (int y = 0; y < BLOCK_DIM; y++) {
        for (int x = 0; x < BLOCK_DIM / 2; x++){
            int temp = matrix[y][x];
            matrix[y][x] = matrix[y][BLOCK_DIM - 1 - x];
            matrix[y][BLOCK_DIM - 1 - x] = temp;
        }
    }
}

void col_flip(int matrix[BLOCK_DIM][BLOCK_DIM]) {
    for (int x = 0; x < BLOCK_DIM; x++) {
        for (int y = 0; y < BLOCK_DIM / 2; y++){
            int temp = matrix[y][x];
            matrix[y][x] = matrix[BLOCK_DIM - 1 -y][x];
            matrix[BLOCK_DIM - 1 -y][x] = temp;
        }
    }
}

// void print_tetromino(int matrix[BLOCK_DIM][BLOCK_DIM]) {
//     for (int y = 0; y < BLOCK_DIM; y++) {
//             for (int x = 0; x < BLOCK_DIM; x++) {
//                 cout << matrix[y][x] << " ";
//             }
//         cout << endl;
//     }
// }

// void print_board(int matrix[BOARD_HEIGHT][BOARD_WIDTH]) {
//         for (int y = 0; y < BOARD_HEIGHT; y++) {
//             for (int x = 0; x < BOARD_WIDTH; x++) {
//                 cout << matrix[y][x] << " ";
//             }
//         cout << endl;
//     }
// }

// template <int ROWS, int COLS>
// void print_matrix(int (&matrix)[ROWS][COLS]) {
//         for (int y = 0; y < ROWS; y++) {
//             for (int x = 0; x < COLS; x++) {
//                 cout << matrix[y][x] << " ";
//             }
//         cout << endl;
//     }
// }