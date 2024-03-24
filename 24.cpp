#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    vector<int> height(n);
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }
    vector<int> dp_h(n, 1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (height[j] < height[i]) {
                dp_h[i] = max(dp_h[j] + 1, dp_h[i]);
            }
        }
    }
    vector<int> dp_l(n, 1);
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (height[j] < height[i]) {
                dp_l[i] = max(dp_l[j] + 1, dp_l[i]);
            }
        }
    }
    int max_dp = 0;
    for (int i = 0; i < n; i++) {
        max_dp = max(max_dp, dp_h[i] + dp_l[i] - 1);
    }
    cout << n - max_dp;
}
// 64 位输出请用 printf("%lld")