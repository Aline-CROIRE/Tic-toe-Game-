#include <iostream>
#include <string>
using namespace std;

// Drawing Board using drawB function
void drawB(char board[3][3]) {
    cout << "-------------\n";
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

// Checking Winner using winnerChecker function
bool winnerChecker(char board[3][3], char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player
            && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player
            && board[2][i] == player)
            return true;
    }
    if (board[0][0] == player && board[1][1] == player
        && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player
        && board[2][0] == player)
        return true;
    return false;
}

int main() {
    // Initializing the board and player names
    char board[3][3] = { { ' ', ' ', ' ' },
                         { ' ', ' ', ' ' },
                         { ' ', ' ', ' ' } };
    char symbol1 = 'X';
    char symbol2 = 'O';
    string player1, player2;

    cout << "Enter First player's name: ";
    cin >> player1;

    cout << "Enter Second player's name: ";
    cin >> player2;

    cout << player1 << " is the first player and will use " << symbol1 << endl;
    cout << player2 << " is the second player and will use " << symbol2 << endl;

    char currentPlayerSymbol = 'X'; // 'X' starts first
    string currentPlayer = player1;

    int row, col;
    cout << "Welcome to Tic-Tac-Toe!\n";

    // Game loop
    for (int turn = 0; turn < 9; turn++) {
        // Draw the board
        drawB(board);

        // Prompt for valid input
        while (true) {
            cout << currentPlayer << ", choose row (0-2) and column (0-2): ";
            cin >> row >> col;

            if (row < 0 || row > 2 || col < 0 || col > 2) {
                cout << "Invalid input. Row and column must be between 0 and 2.\n";
            } else if (board[row][col] != ' ') {
                cout << "Invalid move. Cell already occupied. Try again.\n";
            } else {
                break; // Valid input, exit the loop.
            }
        }

        // Make the move
        board[row][col] = currentPlayerSymbol;

        // Check for a win after making a move
        if (winnerChecker(board, currentPlayerSymbol)) {
            drawB(board);
            cout << currentPlayer << " using " << currentPlayerSymbol << " wins!\n";
            return 0; // Exit the program after a win.
        }

        // Switch to the other player
        if (currentPlayerSymbol == 'X') {
            currentPlayerSymbol = 'O';
            currentPlayer = player2;
        } else {
            currentPlayerSymbol = 'X';
            currentPlayer = player1;
        }
    }

    // End of the game
    drawB(board);

    // Check for a draw
    cout << "It's a draw!\n";

    return 0;
}
