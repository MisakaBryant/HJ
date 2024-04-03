#include <iostream>
#include <list>

using namespace std;

int main () {
    int n = 0;
    cin >> n;
    int head = 0;
    cin >> head;
    list<int> l;
    l.push_back(head);
    for (int i = 0; i < n - 1; i++) {
        int v, to;
        cin >> v >> to;
        auto it = l.begin();
        for (; it != l.end(); it++) {
            if (*it == to) {
                l.insert(++it, v);
                break;
            }
        }
    }
    int del = 0;
    cin >> del;
    auto it = l.begin();
    for (; it != l.end(); ) {
        if (*it == del) {
            it = l.erase(it);
        } else {
            cout << *it << " ";
            it++;
        }
    }
    return 0;
}
