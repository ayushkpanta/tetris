#ifndef UTILS_H
#define UTILS_H

const int BLOCK_DIM = 4;

void transpose(int matrix[BLOCK_DIM][BLOCK_DIM], int transpose[BLOCK_DIM][BLOCK_DIM]);
void row_flip(int matrix[BLOCK_DIM][BLOCK_DIM]);
void col_flip(int matrix[BLOCK_DIM][BLOCK_DIM]);
void print_tetromino(int matrix[BLOCK_DIM][BLOCK_DIM]);

#endif