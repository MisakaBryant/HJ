#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    string key, s;
    cin >> key >> s;
    key += "abcdefghijklmnopqrstuvwxyz";
    unordered_set<char> hashSet;
    string table = "";
    for (char c : key) {
        if (!hashSet.count(c)) {
            table += c;
            hashSet.insert(c);
        }
    }
    for (char c : s) {
        cout << table[c - 'a'];
    }
}
// 64 位输出请用 printf("%lld")
