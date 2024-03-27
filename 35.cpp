#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a;
    cin >> a;
    vector<vector<int>> ans(a, vector<int>(a, -1));
    int num = 1;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j <= i; j++) {
            ans[i - j][j] = num++;
        }
    }
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a - i; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
}
// 64 位输出请用 printf("%lld")
