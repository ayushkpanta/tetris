#include <iostream>
#include <ncurses.h>
#include <array>
#include <unioqu>
using namespace std;

// uses ncurses
#define UP_ARROW          72
#define DOWN_ARROW        80
#define RIGHT_ARROW       75
#define LEFT_ARROW        77
#define CLOCKWISE         44 // "."
#define COUNTER_CLOCKWISE 46 // ","
#define QUIT              113 // "q"
#define DROP              109 // "m"

const int BLOCK_DIM = 4;

class Tetromino {
    int** shape;
    int x_pos = 3;
    int y_pos = 0;
    bool moving = false; // true when start rendering (false after collision)

    public:

        // void render() {
        // }

        // link with clock later
        void tick_move() {
            y_pos += 1
        }

        void player_move(int input) {
            if (input == DOWN_ARROW) {
                y_pos += 1
            }
            else if (input == RIGHT_ARROW) {
                x_pos += 1
            }
            else if (input == LEFT_ARROW) {
                x_pos -= 1
            }
        }

        // void drop() {
        // }

        void rotate(int matrix) {

            // transpose matrix
            int transposed[BLOCK_DIM][BLOCK_DIM] = {};
            transposed = transpose(matrix, transposed);

            // swap rows or columns
            if (input == CLOCKWISE) {

            }
            else if (input == COUNTER_CLOCKWISE) {

            }
        }

}


int** transpose(int matrix[BLOCK_DIM][BLOCK_DIM], int transpose[BLOCK_DIM][BLOCK_DIM];) {
    for (int y = 0; y < BLOCK_DIM; y++) {
        for (int x = 0; x < BLOCK_DIM; x++){
            transpose[y][x] = matrix[y][x];
        }
    }
    return transpose;
}

class O_Block : public Tetromino {
    public:
        O_Block() {
            shape = {{0,1,1,0},
                     {0,1,1,0},
                     {0,0,0,0},
                     {0,0,0,0}}
        }
}
class I_Block : public Tetromino {
    public:
        I_Block() {
            shape = {{1,1,1,1},
                     {0,0,0,0},
                     {0,0,0,0},
                     {0,0,0,0}}
        }
}
class S_Block : public Tetromino {
    public:
        S_Block() {
            shape = {{0,0,1,1},
                     {1,1,0,0},
                     {0,0,0,0},
                     {0,0,0,0}}
        }
}
class Z_Block : public Tetromino {
    public:
        Z_Block() {
            shape = {{1,1,0,0},
                     {0,0,1,1},
                     {0,0,0,0},
                     {0,0,0,0}}
        }
}
class L_Block : public Tetromino {
    public:
        L_Block() {
            shape = {{1,1,1,0},
                     {1,0,0,0},
                     {0,0,0,0},
                     {0,0,0,0}}
        }
}
class J_Block : public Tetromino {
    public:
        J_Block() {
            shape = {{1,1,1,0},
                     {0,0,1,0},
                     {0,0,0,0},
                     {0,0,0,0}}
        }
}
class T_Block : public Tetromino {
    public:
        T_Block() {
            shape = {{1,1,1,0},
                     {0,1,0,0},
                     {0,0,0,0},
                     {0,0,0,0}}
        }
}


// dynamically allocated, will need to delete objects in game loop...

std::unique_ptr<Tetromino> generateTetromino() {

    std::array<char> shapes{'O','I','S','Z','L','J','T'};
    char shape = shapes[rand() % shapes.size()];

    Tetromino block;
    unique_ptr<Tetromino> ptr;

    switch(shape) {
        case 'O':
            ptr = std::make_unique<O_Block>();
            break;
        case 'I':
            ptr = std::make_unique<I_Block>();
            break;
        case 'S':
            ptr = std::make_unique<S_Block>();
            break;
        case 'Z':
            ptr = std::make_unique<Z_Block>();
            break;
        case 'L':
            ptr = std::make_unique<L_Block>();
            break;
        case 'J':
            ptr = std::make_unique<J_Block>();
            break;
        case 'T':
            ptr = std::make_unique<T_Block>();
            break;
    }

    std::cout << shape;
    return ptr;
}