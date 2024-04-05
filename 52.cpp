#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int l1 = s1.size();
    int l2 = s2.size();
    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0x3f3f3f));
    for (int i = 0; i <= l1; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= l2; j++) {
        dp[0][j] = j;
    }
    for (int i = 1; i <= l1; i++) {
        for (int j = 1; j <= l2; j++) {
            dp[i][j] = min(dp[i][j], min(dp[i-1][j], dp[i][j-1])+1);
            dp[i][j] = min(dp[i][j], dp[i-1][j-1] + (s1[i-1] == s2[j-1] ? 0 : 1));
        }
    }
    cout << dp[l1][l2] << endl;
}
// 64 位输出请用 printf("%lld")