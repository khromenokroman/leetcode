
/*
83. Remove Duplicates from Sorted List
Easy
Topics
Companies
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the
linked list sorted as well.



Example 1:


Input: head = [1,1,2]
Output: [1,2]
Example 2:


Input: head = [1,1,2,3,3]
Output: [1,2,3]


Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.
 */
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        ListNode* cur = head;
        while (cur != nullptr && cur->next != nullptr) {
            if (cur->val == cur->next->val) {
                ListNode* tmp = cur->next->next;
                delete cur->next;
                cur->next = tmp;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
};

int main() {
    ListNode* l3 = new ListNode(1);
    ListNode* l2 = new ListNode(1, l3);
    ListNode* l1 = new ListNode(1, l2);

    //    ListNode* l3 = new ListNode(2);
    //    ListNode* l2 = new ListNode(1, l3);
    //    ListNode* l1 = new ListNode(1, l2);

    //        ListNode* l5 = new ListNode(3);
    //        ListNode* l4 = new ListNode(3,l5);
    //        ListNode* l3 = new ListNode(2,l4);
    //        ListNode* l2 = new ListNode(1, l3);
    //        ListNode* l1 = new ListNode(1, l2);

    ListNode* cur = l1;
    while (cur) {
        std::cout << cur->val << " ";
        cur = cur->next;
    }
    std::cout << '\n';

    Solution sol;
    ListNode* ptr = sol.deleteDuplicates(l1);

    cur = ptr;
    while (cur) {
        std::cout << cur->val << " ";
        cur = cur->next;
    }
    std::cout << '\n';

    return 0;
}