#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, m;
    cin >> N >> m;
    vector<int> v(m + 1);
    vector<int> p(m + 1);
    vector<int> q(m + 1);
    vector<vector<int>> annex(m + 1);
    for (int i = 1; i < m + 1; i++) {
        cin >> v[i] >> p[i] >> q[i];
        if (q[i] > 0) annex[q[i]].push_back(i);
    }
    vector<vector<int>> dp(m + 1, vector<int>(N + 1, 0));
    for (int i = 1; i < m + 1; i++) {
        if (q[i] > 0) {
            for (int j = 0; j < N + 1; j++) {
                dp[i][j] = dp[i - 1][j];
            }
            continue;
        }
        for (int j = 0; j < N + 1; j++) {
            dp[i][j] = dp[i - 1][j];    // 都不买
            if (j - v[i] >= 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + v[i] * p[i]);    // 买主件
            }
            if (annex[i].size() >= 1 && j - v[i] - v[annex[i][0]] >= 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i] - v[annex[i][0]]] + v[i] * p[i] + v[annex[i][0]] * p[annex[i][0]]); // 主件 + 附件1
            }
            if (annex[i].size() >= 2) {
                if (j - v[i] - v[annex[i][1]] >= 0) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i] - v[annex[i][1]]] + v[i] * p[i] + v[annex[i][1]] * p[annex[i][1]]); // 主件 + 附件2
                }
                if (j - v[i] - v[annex[i][0]] - v[annex[i][1]] >= 0) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i] - v[annex[i][0]] - v[annex[i][1]]] + v[i] * p[i] + v[annex[i][0]] * p[annex[i][0]] + v[annex[i][1]] * p[annex[i][1]]); // 主件 + 附件1 + 附件2
                }
            }
        }
    }
    int ans = 0;
    for (int j = 0; j < N + 1; j++) {
        ans = max(ans, dp[m][j]);
    }
    cout << ans;
}
// 64 位输出请用 printf("%lld")
