#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n , m;
    cin >> n >> m;
    vector<vector<int>> dp(m+1, vector<int>(n+1, 1));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    cout << dp[m][n] << endl;
}
// 64 位输出请用 printf("%lld")
