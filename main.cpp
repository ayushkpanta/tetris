
#include "utils.h"

int main() {

    char board[BOARD_HEIGHT][BOARD_WIDTH];
    for (int y = 0; y < BOARD_HEIGHT; y++) {
         for (int x = 0; x < BOARD_WIDTH; x++) {
            if (y == 0 || y == BOARD_HEIGHT - 1 || x == 0 || x == BOARD_WIDTH - 1) {
                board[y][x] = '@';
            }
            else {
                board[y][x] = ' ';
            }
         }
    }
    print_matrix(board);

    std::srand(static_cast<unsigned>(std::time(nullptr)));
    cout << "\n";
    std::unique_ptr<Tetromino> block = generateTetromino();
    cout << "\n\n";
    block->print_shape();


    


}