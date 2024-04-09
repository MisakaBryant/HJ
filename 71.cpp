#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    int al = a.size();
    int bl = b.size();
    vector<vector<bool>> dp(al+1, vector<bool>(bl+1, false));
    dp[0][0] = true;
    for (int aptr = 0; aptr < al; aptr++) {
        for (int bptr = 0; bptr < bl; bptr++) {
            if ((toupper(a[aptr]) == toupper(b[bptr]) || (a[aptr] == '?' && (isalnum(b[bptr]) || isalpha(b[bptr]))))) {
                dp[aptr+1][bptr+1] = dp[aptr][bptr];
            } else if (a[aptr] == '*') {
                for (int i = bptr; i <= bl; i++) {
                    dp[aptr+1][i] = dp[aptr+1][i] | dp[aptr][bptr];
                }
            }
        }
    }
    cout << (dp[al][bl] ? "true" : "false") << endl;
}
// 64 位输出请用 printf("%lld")
