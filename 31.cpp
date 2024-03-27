#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    int l = 0, r = 0;
    vector<string> words;
    while (l < s.size() && (s[l] < 'A' || (s[l] > 'Z' && s[l] < 'a') || s[l] > 'z')) l++;
    r = l;
    while (r < s.size()) {
        while (r < s.size() && ((s[r] >= 'a' && s[r] <= 'z') || (s[r] >= 'A' && s[r] <= 'Z'))) r++;
        words.push_back(s.substr(l, r - l));
        l = ++r;
    }
    reverse(words.begin(), words.end());
    for (auto w : words) {
        cout << w << ' ';
    }
}
// 64 位输出请用 printf("%lld")
