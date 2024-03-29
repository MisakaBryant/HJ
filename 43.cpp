#include <iostream>
#include <vector>

using namespace std;

int N, M;
int m[10][10] = {0};
bool visited[10][10] = {false};

bool dfs(int row, int col, vector<vector<int>>& way) {
    if (row < 0 || row >= N) return false;
    if (col < 0 || col >= M) return false;
    if (visited[row][col]) return false;
    if (m[row][col]) return false;
    visited[row][col] = true;
    vector<vector<int>> t = way;
    t.push_back({row, col});
    if (row == N - 1 && col == M - 1) {
        way = t;
        return true;
    }
    if (dfs(row - 1, col, t)) {
        way = t;
        return true;
    }
    if (dfs(row + 1, col, t)) {
        way = t;
        return true;
    }
    if (dfs(row, col - 1, t)) {
        way = t;
        return true;
    }
    if (dfs(row, col + 1, t)) {
        way = t;
        return true;
    }
    return false;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> m[i][j];
            visited[i][j] = false;
        }
    }
    vector<vector<int>> ans;
    dfs(0, 0, ans);
    for (auto p : ans) {
        cout << '(' << p[0] << ',' << p[1] << ')' << endl;
    }
}
// 64 位输出请用 printf("%lld")
