#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

int main() {
    int n, k;
    while (cin >> n >> k) {
        vector<int> vec(n);
        for (int i = 0; i < n; ++i)
            cin >> vec[i];
        partial_sort(vec.begin(), vec.begin() + k, vec.end());
        copy(vec.begin(), vec.begin() + k, ostream_iterator<int>(cout, " "));
        cout << endl;
    }
}
