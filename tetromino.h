// #ifndef TETROMINO_H
// #define TETROMINO_H

// #include <iostream>
// #include <ncurses.h>
// #include <memory>
// #include <array>
// #include "utils.h"
// #include "tetromino.h"

// // uses ncurses
// #define UP_ARROW          72
// #define DOWN_ARROW        80
// #define RIGHT_ARROW       75
// #define LEFT_ARROW        77
// #define CLOCKWISE         44 // "."
// #define COUNTER_CLOCKWISE 46 // ","
// #define QUIT              113 // "q"
// #define DROP              109 // "m"

// class Tetromino {
//     protected:
//         char shape[BLOCK_DIM][BLOCK_DIM];
//         int x_pos;
//         int y_pos;
//         bool moving;

//     public:
//         Tetromino();
//         virtual ~Tetromino() = default;

//         // void render();
//         void tick_move();
//         void player_move(int input);
//         void rotate(int input);
//         void print_shape() const;
// };


// class O_Block : public Tetromino {
//     public:
//         O_Block();
// };

// class I_Block : public Tetromino {
//     public:
//         I_Block();
// };

// class S_Block : public Tetromino {
//     public:
//         S_Block();
// };

// class Z_Block : public Tetromino {
//     public:
//         Z_Block();
// };

// class L_Block : public Tetromino {
//     public:
//         L_Block();
// };

// class J_Block : public Tetromino {
//     public:
//         J_Block();
// };

// class T_Block : public Tetromino {
//     public:
//         T_Block();
// };

// std::unique_ptr<Tetromino> generateTetromino();

// #endif // TETROMINO_H
