#include <iostream>
using namespace std;

int sudoku[9][9];

bool check(int row, int col, int n) {
    for (int i = 0; i < 9; i++) {
        if (sudoku[row][i] == n) return false;
        if (sudoku[i][col] == n) return false;
    }
    int x = row / 3 * 3;
    int y = col / 3 * 3;
    for (int i = x; i < x + 3; i++) {
        for (int j = y; j < y + 3; j++) {
            if (sudoku[i][j] == n) return false;
        }
    }
    return true;
}

bool dfs(int n) {
    if (n == 81) return true;
    int row = n / 9;
    int col = n % 9;
    if (sudoku[row][col] == 0) {
        for (int k = 1; k < 10; k++) {
            if (check(row, col, k)) {
                sudoku[row][col] = k;
                if (dfs(n + 1)) {
                    return true;
                } else {
                    sudoku[row][col] = 0;
                    continue;
                }
            }
        }
        return false;
    } else {
        return dfs(n + 1);
    }
}

int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> sudoku[i][j];
        }
    }
    dfs(0);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << sudoku[i][j] << ' ';
        }
        cout << endl;
    }
}
// 64 位输出请用 printf("%lld")

//0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0