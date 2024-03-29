#include<iostream>
#include<string>
using namespace std;
int main() {
    string str;
    while (getline(cin, str)) {
        int a = 0, b = 0, c = 0, d = 0;
        for (const auto item : str) {
            if (isalpha(item))
                ++a;
            else if (isspace(item))
                ++b;
            else if (isdigit(item))
                ++c;
            else if (ispunct(item))
                ++d;
        }
        cout << a << endl << b << endl << c << endl << d << endl;
    }
    return 0;
}

