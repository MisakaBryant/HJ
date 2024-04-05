#include <iostream>
#include <string>
#include <stack>

using namespace std;

string s;
stack<double> nums;
stack<char> symbols;

double cal(char symbol, double a, double b) {
    if (symbol == '+') {
        return a + b;
    } else if (symbol == '-') {
        return a - b;
    } else if (symbol == '*') {
        return a * b;
    } else {
        return a / b;
    }
}

int main() {
    cin >> s;
    bool negative = false;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') { // nums
            int num = s[i] - '0';
            i++;
            while (s[i] >= '0' && s[i] <= '9') {
                num *= 10;
                num += s[i] - '0';
                i++;
            }
            i--;
            if (negative) {
                num = -num;
                negative = false;
            }
            nums.push(num);
        } else if (s[i] == '+' || s[i] == '-') {
            if (s[i] == '-' && (i - 1 < 0 || (!(s[i - 1] >= '0' && s[i - 1] <= '9') && s[i - 1] != '}' && s[i - 1] != ']' && s[i - 1] != ')'))) { // 负号
                negative = true;
            } else {
                while (!symbols.empty() && symbols.top() != '(' && symbols.top() != '[' && symbols.top() != '{') {
                    char last = symbols.top();
                    symbols.pop();
                    double b = nums.top();
                    nums.pop();
                    double a = nums.top();
                    nums.pop();
                    nums.push(cal(last, a, b));
                }
                symbols.push(s[i]);
            }
        } else if (s[i] == '*' || s[i] == '/') {
            while (!symbols.empty() && (symbols.top() == '*' || symbols.top() == '/')) {
                char last = symbols.top();
                symbols.pop();
                double b = nums.top();
                nums.pop();
                double a = nums.top();
                nums.pop();
                nums.push(cal(last, a, b));
            }
            symbols.push(s[i]);
        } else if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            symbols.push(s[i]);
        } else {
            while (!symbols.empty() && symbols.top() != '(' && symbols.top() != '[' && symbols.top() != '{') {
                char last = symbols.top();
                symbols.pop();
                double b = nums.top();
                nums.pop();
                double a = nums.top();
                nums.pop();
                nums.push(cal(last, a, b));
            }
            symbols.pop();
        }
    }
    while (!symbols.empty()) {
        char last = symbols.top();
        symbols.pop();
        double b = nums.top();
        nums.pop();
        double a = nums.top();
        nums.pop();
        nums.push(cal(last, a, b));
    }
    cout << nums.top() << endl;
}
// 64 位输出请用 printf("%lld")
