#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, 0));
    for (int j = 0; j <= b; j++) {
        dp[0][j] = 1;
    }
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            dp[i][j] = dp[i][j-1];
            if (i-j>=0) {
                dp[i][j] += dp[i-j][j];
            }
        }
    }
    cout << dp[a][b] << endl;
}
// 64 位输出请用 printf("%lld")