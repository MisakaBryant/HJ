#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        vector<int> cnt(26, 0);
        for (auto c : s) {
            cnt[c - 'a']++;
        }
        sort(cnt.begin(), cnt.end(), greater<int>());
        int ans = 0;
        int beauty = 26;
        for (auto i : cnt) {
            if (i == 0) break;
            ans += i * beauty--;
        }
        cout << ans << endl;
    }
}
// 64 位输出请用 printf("%lld")
