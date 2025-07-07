#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer;

void initializeBoard() {
    // Fill the board with numbers 1-9 for reference
    char num = '1';
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = num++;
}

void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}

bool isMoveValid(int position) {
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;
    return (position >= 1 && position <= 9 && board[row][col] != 'X' && board[row][col] != 'O');
}

void makeMove(int position) {
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;
    board[row][col] = currentPlayer;
}

bool checkWin() {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++)
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||  // row
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer))    // column
            return true;

    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||       // diagonal
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer))         // reverse diagonal
        return true;

    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int main() {
    char playAgain;
    do {
        currentPlayer = 'X';
        initializeBoard();

        bool gameWon = false;
        bool draw = false;

        cout << "Welcome to Tic-Tac-Toe!" << endl;

        while (!gameWon && !draw) {
            displayBoard();

            int move;
            cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            cin >> move;

            while (!isMoveValid(move)) {
                cout << "Invalid move. Try again: ";
                cin >> move;
            }

            makeMove(move);

            gameWon = checkWin();
            if (gameWon) {
                displayBoard();
                cout << "Player " << currentPlayer << " wins!" << endl;
                break;
            }

            draw = checkDraw();
            if (draw) {
                displayBoard();
                cout << "It's a draw!" << endl;
                break;
            }

            switchPlayer();
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!" << endl;
    return 0;
}