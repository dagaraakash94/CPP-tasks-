
#include <iostream>
using namespace std;

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

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

bool checkWin(char mark) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == mark &&
            board[i][1] == mark &&
            board[i][2] == mark)
            return true;

        if (board[0][i] == mark &&
            board[1][i] == mark &&
            board[2][i] == mark)
            return true;
    }

    if (board[0][0] == mark &&
        board[1][1] == mark &&
        board[2][2] == mark)
        return true;

    if (board[0][2] == mark &&
        board[1][1] == mark &&
        board[2][0] == mark)
        return true;

    return false;
}

int main() {
    int position;
    char currentPlayer = 'X';

    for (int turn = 0; turn < 9; turn++) {
        displayBoard();

        cout << "Player " << currentPlayer
             << ", choose a position (1-9): ";
        cin >> position;

        if (position < 1 || position > 9 ||
            board[(position - 1) / 3]
                 [(position - 1) % 3] == 'X' ||
            board[(position - 1) / 3]
                 [(position - 1) % 3] == 'O') {
            cout << "Invalid position! Try again.\n";
            turn--;
            continue;
        }

        board[(position - 1) / 3]
             [(position - 1) % 3] = currentPlayer;

        if (checkWin(currentPlayer)) {
            displayBoard();
            cout << "Player " << currentPlayer
                 << " wins!\n";
            return 0;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    displayBoard();
    cout << "It's a draw!\n";

    return 0;
}
