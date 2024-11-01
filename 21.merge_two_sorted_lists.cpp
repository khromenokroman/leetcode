/*
 21. Merge Two Sorted Lists
Easy
Topics
Companies
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.



Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]


Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.
 */

#include <iostream>
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode fake_result(0);
        ListNode* cur_pos = &fake_result;

        while (true) {
            if (list1 == nullptr) {
                cur_pos->next = list2;
                return fake_result.next;
            } else if (list2 == nullptr) {
                cur_pos->next = list1;
                return fake_result.next;
            } else {
                if (list1->val < list2->val) {
                    cur_pos->next = list1;
                    cur_pos = list1;
                    list1 = list1->next;
                } else {
                    cur_pos->next = list2;
                    cur_pos = list2;
                    list2 = list2->next;
                }
            }
        }
    }
};
int main() {
    auto l1 = new ListNode(1);
    auto l2 = new ListNode(2);
    auto l3 = new ListNode(4);
    l1->next = l2;
    l2->next = l3;

    auto t1 = new ListNode(1);
    auto t2 = new ListNode(3);
    auto t3 = new ListNode(5);
    t1->next = t2;
    t2->next = t3;

    Solution sol;
    auto merged_list = sol.mergeTwoLists(l1, t1);
    while (merged_list) {
        std::cout << merged_list->val << " ";
        merged_list = merged_list->next;
    }
    std::cout << std::endl;
    return 0;
}