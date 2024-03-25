#include <iostream>
using namespace std;

int main() {
    string s;
    while (cin >> s) {
        bool over = false;
        int p = 0;
        while (!over) {
            string out;
            for (int i = 0; i < 8; i ++) {
                if (p == s.size() - 1) over = true;
                out += p < s.size() ? s[p++] : '0';
            }
            cout << out << endl;
        }
    }
    return 0;
}
// 64 位输出请用 printf("%lld")
