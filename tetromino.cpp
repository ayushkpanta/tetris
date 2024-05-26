#include <iostream>
#include <ncurses.h>
#include <array>
#include "utils.h"
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

class Tetromino {
    protected:
        int shape[BLOCK_DIM][BLOCK_DIM];
        int x_pos;
        int y_pos;
        bool moving;

    public:
        Tetromino() : x_pos(3), y_pos(0), moving(false) {}

        virtual ~Tetromino() = default;

        // void render() {
        // }

        // link with clock later
        void tick_move() {
            y_pos += 1;
        }

        void player_move(int input) {
            if (input == DOWN_ARROW) {
                y_pos += 1;
            }
            else if (input == RIGHT_ARROW) {
                x_pos += 1;
            }
            else if (input == LEFT_ARROW) {
                x_pos -= 1;
            }
        }

        // void drop() {
        // }

        void rotate(int input) {

            int transposed[BLOCK_DIM][BLOCK_DIM] = {};
            transpose(shape, transposed);
            std::copy(&transposed[0][0], &transposed[0][0] + BLOCK_DIM * BLOCK_DIM, &shape[0][0]);

            if (input == CLOCKWISE) {
                row_flip(shape);
            }
            else if (input == COUNTER_CLOCKWISE) {
                col_flip(shape);
            }
        }

        void print_shape() {
            print_matrix(shape);
        }

};

class O_Block : public Tetromino {
    public:
        O_Block() {
            int sub_shape[BLOCK_DIM][BLOCK_DIM] = {{0,1,1,0},
                                                   {0,1,1,0},
                                                   {0,0,0,0},
                                                   {0,0,0,0}};
            std::copy(&sub_shape[0][0], &sub_shape[0][0] + BLOCK_DIM * BLOCK_DIM, &shape[0][0]);
        }
};

class I_Block : public Tetromino {
    public:
        I_Block() {
            int sub_shape[BLOCK_DIM][BLOCK_DIM] = {{1,1,1,1},
                                                   {0,0,0,0},
                                                   {0,0,0,0},
                                                   {0,0,0,0}};
            std::copy(&sub_shape[0][0], &sub_shape[0][0] + BLOCK_DIM * BLOCK_DIM, &shape[0][0]);
        }
};

class S_Block : public Tetromino {
    public:
        S_Block() {
            int sub_shape[BLOCK_DIM][BLOCK_DIM] = {{0,1,1,0},
                                                   {1,1,0,0},
                                                   {0,0,0,0},
                                                   {0,0,0,0}};
            std::copy(&sub_shape[0][0], &sub_shape[0][0] + BLOCK_DIM * BLOCK_DIM, &shape[0][0]);
        }
};

class Z_Block : public Tetromino {
    public:
        Z_Block() {
            int sub_shape[BLOCK_DIM][BLOCK_DIM] = {{1,1,0,0},
                                                   {0,1,1,0},
                                                   {0,0,0,0},
                                                   {0,0,0,0}};
            std::copy(&sub_shape[0][0], &sub_shape[0][0] + BLOCK_DIM * BLOCK_DIM, &shape[0][0]);
        }
};

class L_Block : public Tetromino {
    public:
        L_Block() {
            int sub_shape[BLOCK_DIM][BLOCK_DIM] = {{0,0,1,0},
                                                   {1,1,1,0},
                                                   {0,0,0,0},
                                                   {0,0,0,0}};
            std::copy(&sub_shape[0][0], &sub_shape[0][0] + BLOCK_DIM * BLOCK_DIM, &shape[0][0]);
        }
};

class J_Block : public Tetromino {
    public:
        J_Block() {
            int sub_shape[BLOCK_DIM][BLOCK_DIM] = {{1,0,0,0},
                                                   {1,1,1,0},
                                                   {0,0,0,0},
                                                   {0,0,0,0}};
            std::copy(&sub_shape[0][0], &sub_shape[0][0] + BLOCK_DIM * BLOCK_DIM, &shape[0][0]);
        }
};

class T_Block : public Tetromino {
    public:
        T_Block() {
            int sub_shape[BLOCK_DIM][BLOCK_DIM] = {{1,1,1,0},
                                                   {0,1,0,0},
                                                   {0,0,0,0},
                                                   {0,0,0,0}};
            std::copy(&sub_shape[0][0], &sub_shape[0][0] + BLOCK_DIM * BLOCK_DIM, &shape[0][0]);
        }
};


// dynamically allocated, will need to delete objects in game loop...

std::unique_ptr<Tetromino> generateTetromino() {

    std::array<char, 7> shapes = {'O','I','S','Z','L','J','T'};
    char shape = shapes[rand() % shapes.size()];
    unique_ptr<Tetromino> ptr;

    switch(shape) {
        case 'O':
            ptr = std::unique_ptr<O_Block>(new O_Block());
            break;
        case 'I':
            ptr = std::unique_ptr<I_Block>(new I_Block());
            break;
        case 'S':
            ptr = std::unique_ptr<S_Block>(new S_Block());
            break;
        case 'Z':
            ptr = std::unique_ptr<Z_Block>(new Z_Block());
            break;
        case 'L':
            ptr = std::unique_ptr<L_Block>(new L_Block());
            break;
        case 'J':
            ptr = std::unique_ptr<J_Block>(new J_Block());
            break;
        case 'T':
            ptr = std::unique_ptr<T_Block>(new T_Block());
            break;
    }

    std::cout << shape;
    return ptr;
}

// int main() {

//     std::srand(static_cast<unsigned>(std::time(nullptr)));
//     cout << "\n";
//     std::unique_ptr<Tetromino> block = generateTetromino();
//     cout << "\n\n";
//     block->print_shape();


//     block->rotate(CLOCKWISE);
//     cout << "\n\n";
//     block->print_shape();

//     block->rotate(COUNTER_CLOCKWISE);
//     cout << "\n\n";
//     block->print_shape();

//     block->rotate(COUNTER_CLOCKWISE);
//     cout << "\n\n";
//     block->print_shape();


//     return 0;


// }

// clang++ -o tetris tetromino.cpp utils.cpp && ./tetris