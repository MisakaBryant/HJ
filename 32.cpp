#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> dp(n, 1);  // 以s[i]结尾的合法字符串长度，本身可以作为密码
    for (int i = 1; i < n; i++) {
        if (i - 1 - dp[i - 1] >= 0 && s[i - 1 - dp[i - 1]] == s[i]) {
            dp[i] = max(dp[i], dp[i - 1] + 2);
        }
        int l = 1;
        for (int j = i -1; j >= 0; j--) {
            if (s[i] == s[j]) {
                l++;
            } else {
                break;
            }
        }
        dp[i] = max(dp[i], l);
    }
    int ans = 0;
    for (auto a : dp) {
        ans = max(ans, a);
    }
    cout << ans << endl;
}
// 64 位输出请用 printf("%lld")
