#include <stdio.h> 

// Function to draw the game board
void drawBoard(char board[3][3]) {
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---------\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---------\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

// Function to check if a player has won
int checkWin(char board[3][3], char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return 1;
    }

    return 0;
}

int main() {
    char board[3][3] = { { '1', '2', '3' }, { '4', '5', '6' }, { '7', '8', '9' } };
    char player = 'X';

    while (1) {
        drawBoard(board);

        printf("Player %c's turn. Enter move: ", player);
        int move;
        scanf("%d", &move);

        if (move < 1 || move > 9) {
            printf("Invalid move. Please enter a number between 1 and 9.\n");
            continue;
        }

        int row = (move - 1) / 3;
        int col = (move - 1) % 3;

        if (board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = player;
        } else {
            printf("Invalid move. That spot is already taken.\n");
            continue;
        }

        if (checkWin(board, player)) {
            printf("Player %c wins!\n", player);
            drawBoard(board);
            break;
        }

        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}