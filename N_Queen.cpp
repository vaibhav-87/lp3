#include <bits/stdc++.h>
using namespace std;

bool solutionFound = false;

void print(int **board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(board[i][j]) cout << "Q ";
            else cout << ". ";
        }
        cout << endl;
    }
    cout << "-----------------\n";
}

bool isValid(int **board, int n, int row, int col) {
    for (int i = 0; i < col; i++) {
        if (board[row][i]) 
            return false;
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) 
            return false;
    }
    for (int i = row, j = col; n > i && j >= 0; i++, j--) {
        if (board[i][j]) 
            return false;
    }
    return true;
}

void ninjaQueens(int **board, int n, int currentColumn) {
    if (solutionFound) 
        return;

    if (currentColumn >= n) {
        print(board, n);
        solutionFound = true;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (isValid(board, n, i, currentColumn)) {
            board[i][currentColumn] = 1;
            ninjaQueens(board, n, currentColumn + 1);
            board[i][currentColumn] = 0;
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of the board (n x n): ";
    cin >> n;

    int row, column;
    int **board = new int*[n];
    for (int i = 0; i < n; i++) {
        board[i] = new int[n]();
    }

    cout << "Enter row and column to place the first queen (0-indexed): ";
    cin >> row >> column;

    board[row][column] = 1;
    ninjaQueens(board, n, 1);

    if (!solutionFound) {
        cout << "No solution possible\n";
    }

    for (int i = 0; i < n; i++) {
        delete[] board[i];
    }
    delete[] board;

    return 0;
}