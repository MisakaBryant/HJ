#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    string s;
    cin >> s;
    unordered_map<char, int> hashMap;
    for (auto c : s) {
        hashMap[c]++;
    }
    int min = 0x3f3f3f3f;
    for (auto p : hashMap) {
        if (min > p.second) {
            min = p.second;
        }
    }
    for (auto it = s.begin(); it != s.end(); ) {
        if (hashMap[*it] == min) {
            s.erase(it);
        } else {
            it++;
        }
    }
    cout << s;
}
// 64 位输出请用 printf("%lld")