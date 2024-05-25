
// move matrix functions here

#include "utils.h"

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