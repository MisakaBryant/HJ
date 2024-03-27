#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] >= 'a' && s1[i] <= 'z') {
            s1[i] = (s1[i] - 'a' + 1)%26 + 'A';
        } else if (s1[i] >= 'A' && s1[i] <= 'Z') {
            s1[i] = (s1[i] - 'A' + 1)%26 + 'a';
        } else {
            s1[i] = (s1[i] - '0' + 1)%10 + '0';
        }
    }
    for (int i = 0; i < s2.size(); i++) {
        if (s2[i] >= 'a' && s2[i] <= 'z') {
            s2[i] = (s2[i] - 'a' + 25)%26 + 'A';
        } else if (s2[i] >= 'A' && s2[i] <= 'Z') {
            s2[i] = (s2[i] - 'A' + 25)%26 + 'a';
        } else {
            s2[i] = (s2[i] - '0' + 9)%10 + '0';
        }
    }
    cout << s1 << endl;
    cout << s2 << endl;
}
// 64 位输出请用 printf("%lld")
