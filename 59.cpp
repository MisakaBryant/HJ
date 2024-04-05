#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
    string s;
    cin >> s;
    unordered_map<char, int> hashMap;
    unordered_set<char> wasted;
    for (int i = 0; i < s.size(); i++) {
        if (wasted.count(s[i])) continue;
        if (hashMap.count(s[i])) {
            hashMap.erase(s[i]);
            wasted.insert(s[i]);
            continue;
        }
        hashMap[s[i]] = i;
    }
    if (hashMap.empty()) {
        cout << -1 << endl;
        return 0;
    }
    char ans = -1;
    int min = 0x3f3f3f3f;
    for (auto p : hashMap) {
        if (p.second < min) {
            min = p.second;
            ans = p.first;
        }
    }
    cout << ans << endl;
}
// 64 位输出请用 printf("%lld")