#include<iostream>
#include<vector>
using namespace std;

void MatrixMultiply(const vector<vector<int>> &m1, const vector<vector<int>> &m2) {
    size_t m = m1.size();
    size_t n = m2.size();
    size_t z = m2[0].size();
    for (auto i = 0; i < m; ++i) {
        for (auto j = 0; j < z; ++j) {
            int tmp = 0;
            for (auto k = 0; k < n; ++k) {
                tmp += (m1[i][k] * m2[k][j]);
            }
            cout << tmp << " ";
        }
        cout << endl;
    }
}

int main() {
    int m, n, z;
    cin >> m >> n >> z;
    vector<vector<int>> m1(m, vector<int> (n, 0));
    vector<vector<int>> m2(n, vector<int> (z, 0));
    for (auto i = 0; i < m; ++i) {
        for (auto j = 0; j < n; ++j) {
            cin >> m1[i][j];
        }
    }
    for (auto i = 0; i < n; ++i) {
        for (auto j = 0; j < z; ++j) {
            cin >> m2[i][j];
        }
    }
    MatrixMultiply(m1, m2);
    return 0;
}
