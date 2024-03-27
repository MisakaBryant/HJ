#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


bool cmp(char a, char b) {
    if (a >= 'A' && a <= 'Z') {
        a = a - 'A' + 'a';
    }
    if (b >= 'A' && b <= 'Z') {
        b = b - 'A' + 'a';
    }
    return a < b;
}


int main() {
    string s;
    getline(cin, s);
    vector<char> chars;
    for (int i = 0; i < s.size(); i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
            chars.push_back(s[i]);
        }
    }
    stable_sort(chars.begin(), chars.end(), cmp);
    int j = 0;
    for (int i = 0; i < s.size(); i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
            s[i] = chars[j++];
        }
    }
    cout << s;
}
// 64 位输出请用 printf("%lld")
