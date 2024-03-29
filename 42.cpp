#include<bits/stdc++.h>
using namespace std;

string ones[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
string tens[] = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
string twenties[] = { "zero", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
string hundreds[] = { "hundred", "thousand", "million", "billion" };
int ihundreds[] = { (int)1e2, (int)1e3, (int)1e6, (int)1e9, (int)1e12 };

string itoe(long long n) {
    if (n <= 9)return ones[n];
    else if (n < 20)return tens[n % 10];
    else if (n < 1e2)return twenties[n / 10] + (n % 10 ? " " + ones[n % 10] : "");
    else for (int i = 0; i < 4; i++)
            if (n < ihundreds[i + 1])
                return itoe(n / ihundreds[i]) + " "
                       + hundreds[i]
                       + (n % ihundreds[i] ? (i ? " " : " and ") + itoe(n % ihundreds[i]) : "");
    return "";
}

int main() {
    long long n;
    cin >> n;
    cout << itoe(n) << endl;
}
