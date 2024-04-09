#include <functional>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    int n, s;
    cin >> n >> s;
    multimap<int, string, less<>> up;
    multimap<int, string, greater<>> down;
    for (int i = 0; i < n; i++) {
        string name;
        int point;
        cin >> name >> point;
        if (s) {
            up.insert({point, name});
        } else {
            down.insert({point, name});
        }
    }
    if (s) {
        for (auto p : up) {
            cout << p.second << " " << p.first << endl;
        }
    } else {
        for (auto p : down) {
            cout << p.second << " " << p.first << endl;
        }
    }
}
// 64 位输出请用 printf("%lld")
