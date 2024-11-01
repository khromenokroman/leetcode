/*
2. Add Two Numbers
Medium
Topics
Companies
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order,
and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.



Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]


Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode result(0);
        ListNode* cur = &result;
        int overload = 0;

        while (true) {
            if (l1 == nullptr && l2 == nullptr) {
                if (overload){
                    cur->next = new ListNode(1);
                }
                return result.next;
            } else if (l1 == nullptr) {
                int sum = l2->val + overload;
                overload = sum / 10;
                cur->next = new ListNode(sum % 10);
                l2 = l2->next;
                cur = cur->next;
            }else if (l2 == nullptr) {
                int sum = l1->val + overload;
                overload = sum / 10;
                cur->next = new ListNode(sum % 10);
                l1 = l1->next;
                cur = cur->next;
            }else{
                int sum = l1->val + l2->val+ overload;
                overload = sum / 10;
                cur->next = new ListNode(sum % 10);
                l1 = l1->next;
                l2 = l2->next;
                cur = cur->next;
            }
        }
    }
};

int main() {
    auto l1 = new ListNode(9);
    auto l2 = new ListNode(2);
    auto l3 = new ListNode(1);
    l1->next = l2;
    l2->next = l3;

    auto t1 = new ListNode(2);
    auto t2 = new ListNode(3);
    auto t3 = new ListNode(5);
    t1->next = t2;
    t2->next = t3;

    Solution sol;
    auto sum_list = sol.addTwoNumbers(l1, t1);
    while (sum_list) {
        std::cout << sum_list->val << " ";
        sum_list = sum_list->next;
    }
    std::cout << std::endl;
    return 0;
}