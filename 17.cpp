#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<string> cmds;
    int l = 0, r = 0;
    while (l < s.size()) {
        while (r < s.size() && s[r++] != ';');
        cmds.push_back(s.substr(l, r-l-1));
        l = r;
    }
    int x = 0, y = 0;
    for (auto cmd : cmds) {
        if (cmd.size() > 3 || cmd.size() < 2) continue;
        int n = 0;
        if (cmd.size() >= 2) {
            if (cmd[1] >= '0' && cmd[1] <= '9') {
                n += cmd[1] - '0';
            } else {
                continue;
            }
        }
        if (cmd.size() >= 3) {
            if (cmd[2] >= '0' && cmd[2] <= '9') {
                n *= 10;
                n += cmd[2] - '0';
            } else {
                continue;
            }
        }
        switch (cmd[0]) {
            case 'A': {
                x -= n;
                break;
            }
            case 'D': {
                x += n;
                break;
            }
            case 'W': {
                y += n;
                break;
            }
            case 'S': {
                y -= n;
                break;
            }
            default:
                break;
        }
    }
    cout << x << ',' << y;
}
// 64 位输出请用 printf("%lld")
