#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    string pw;
    while (cin >> pw) {
        if (pw.size() < 8) {
            cout << "NG" << endl;
            continue;
        }
        int a = 0;
        int A = 0;
        int num = 0;
        int _ = 0;
        unordered_set<string> hashSet;
        bool valid = true;
        for (int i = 0; i < pw.size(); i++) {
            if (pw[i] >= 'a' && pw[i] <= 'z') a = 1;
            else if (pw[i] >= 'A' && pw[i] <= 'Z') A = 1;
            else if (pw[i] >= '0' && pw[i] <= '9') num = 1;
            else _ = 1;
            if (i < pw.size() - 2) {
                string s = pw.substr(i, 3);
                if (hashSet.count(s)) {
                    valid = false;
                    continue;
                }
                hashSet.insert(s);
            }
        }

        cout << (valid && a + A + num + _ >= 3 ? "OK" : "NG") << endl;
    }
}
// 64 位输出请用 printf("%lld")
