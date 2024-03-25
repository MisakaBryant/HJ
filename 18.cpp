#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

bool judge_ip(string ip) {
    int j = 0;
    istringstream iss(ip);
    string seg;
    while (getline(iss, seg, '.'))
        if (++j > 4 || seg.empty() || stoi(seg) > 255)
            return false;
    return j == 4;
}

bool is_private(string ip) {
    istringstream iss(ip);
    string seg;
    vector<int> v;
    while (getline(iss, seg, '.')) v.push_back(stoi(seg));
    if (v[0] == 10) return true;
    if (v[0] == 172 && (v[1] >= 16 && v[1] <= 31)) return true;
    if (v[0] == 192 && v[1] == 168) return true;
    return false;
}

bool is_mask(string ip) {
    istringstream iss(ip);
    string seg;
    unsigned b = 0;
    while (getline(iss, seg, '.')) b = (b << 8) + stoi(seg);
    if (!b) return false;
    b = ~b + 1;
    if (b == 1) return false;
    if ((b & (b - 1)) == 0) return true;
    return false;
}

int main() {
    string input;
    int a = 0, b = 0, c = 0, d = 0, e = 0, err = 0, p = 0;
    while (cin >> input) {
        istringstream is(input);
        string add;
        vector<string> v;
        while (getline(is, add, '~')) v.push_back(add);
        int begin = stoi(v[0].substr(0, v[0].find_first_of('.')));
        if (begin == 0 || begin == 127) continue;
        if (!judge_ip(v[1]) || !is_mask(v[1])) err++;
        else {
            if (!judge_ip(v[0])) err++;
            else {
                int first = stoi(v[0].substr(0, v[0].find_first_of('.')));
                if (is_private(v[0])) p++;
                if (first > 0 && first < 127) a++;
                else if (first > 127 && first < 192) b++;
                else if (first > 191 && first < 224) c++;
                else if (first > 223 && first < 240) d++;
                else if (first > 239 && first < 256) e++;
            }
        }
    }
    cout << a << " " << b << " " << c << " " << d << " " << e << " " << err << " "
         << p << endl;
    return 0;
}
