#include <iostream>
using namespace std;

// Function to display the Tic-Tac-Toe board
void display_board(char board[3][3]) {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << endl;
        cout << "-------------" << endl;
    }
}

// Function to check for a win
bool check_win(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Function to check for a draw
bool check_draw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char players[2] = {'X', 'O'};
    int player_turn = 0;
    bool game_over = false;
    char play_again;

    do {
        int row, col;
        display_board(board);
        cout << "Player " << players[player_turn] << ", enter your move (row and column): ";
        cin >> row >> col;

        if (board[row][col] == ' ') {
            board[row][col] = players[player_turn];
            if (check_win(board, players[player_turn])) {
                display_board(board);
                cout << "Player " << players[player_turn] << " wins!" << endl;
                game_over = true;
            } else if (check_draw(board)) {
                display_board(board);
                cout << "It's a draw!" << endl;
                game_over = true;
            }
            player_turn = 1 - player_turn; // switch players
        } else {
            cout << "Cell already occupied. Try again!" << endl;
        }

        if (game_over) {
            cout << "Do you want to play again? (y/n): ";
            cin >> play_again;
            if (play_again == 'y' || play_again == 'Y') {
                // Reset the game
                game_over = false;
                player_turn = 0;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        board[i][j] = ' ';
                    }
                }
            } else {
                break;
            }
        }
    } while (true);

    return 0;
}
