#include <iostream>
using namespace std;

struct ListNode
{
    int m_nKey;
    ListNode* m_pNext;
};

int main() {
    int n = 0;
    while (cin >> n) {
        ListNode* head = new ListNode{};
        ListNode* ptr = head;
        for (int i = 0; i < n; i++) {
            ListNode* node = new ListNode{};
            cin >> node->m_nKey;
            ptr->m_pNext = node;
            ptr = ptr->m_pNext;
        }
        int k = 0;
        cin >> k;
        ptr = head;
        ListNode* ans = nullptr;
        for (int i = 0; i < k; i++) {
            if (ptr == nullptr) {
                return 0;
            }
            ptr = ptr->m_pNext;
        }
        ans = head;
        while (ptr != nullptr) {
            ptr = ptr->m_pNext;
            ans = ans->m_pNext;
        }
        cout << ans->m_nKey << endl;
    }

}
// 64 位输出请用 printf("%lld")