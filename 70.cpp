#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    vector<pair<int, int>> ms;
    for (int i = 0; i < n; i++) {
        int r, c;
        cin >> r >> c;
        ms.push_back({r, c});
    }
    string s;
    cin >> s;
    stack<char> ch;
    stack<char> l;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            l.push(s[i]);
        } else if (s[i] == ')') {
            l.pop();
            int b = ch.top() - 'A';
            ch.pop();
            int a = ch.top() - 'A';
            ch.pop();
            ans += ms[a].first * ms[a].second * ms[b].second;
            ms[a].second = ms[b].second;
            ch.push(a + 'A');
        } else {
            ch.push(s[i]);
        }
    }
    cout << ans << endl;
}
// 64 位输出请用 printf("%lld")
