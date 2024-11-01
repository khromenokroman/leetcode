/*
445. Add Two Numbers II
Medium
Topics
Companies
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first
and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.



Example 1:


Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]
Example 2:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]
Example 3:

Input: l1 = [0], l2 = [0]
Output: [0]


Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.


Follow up: Could you solve it without reversing the input lists?
 */

#include <iostream>
#include <stack>


struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void print_list(ListNode*list){
    ListNode * prt = list;
    while (prt) {
        std::cout << prt->val << " ";
        prt = prt->next;
    }
    std::cout << std::endl;
}

class Solution {
   public:
    ListNode* reverse_list(ListNode* list) {
        ListNode* answer = nullptr;
        while (list) {
            ListNode* node = list;
            list = list->next;
            node->next = answer;
            answer = node;
        }
        return answer;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto list1 = reverse_list(l1);
        print_list(list1);
        auto list2 = reverse_list(l2);
        print_list(list2);
        ListNode result(0);
        ListNode* cur = &result;
        int overflow = 0;

        while (true) {
            if (list1 == nullptr && list2 == nullptr) {
                if(overflow){
                    cur->next = new ListNode(overflow);
                }
                break;
            } else if (list1 == nullptr && list2 != nullptr) {
                int sum = list2->val + overflow;
                if (overflow) {
                    overflow = 0;
                }
                cur->next = new ListNode(sum % 10);
                cur = cur->next;
                overflow = sum / 10;
                list2 = list2->next;
            }else if (list2 == nullptr && list1 != nullptr) {
                int sum = list1->val + overflow;
                if (overflow) {
                    overflow = 0;
                }
                cur->next = new ListNode(sum % 10);
                cur = cur->next;
                overflow = sum / 10;
                list1 = list1->next;
            }else{
                int sum = list1->val +list2->val+ overflow;
                if (overflow) {
                    overflow = 0;
                }
                cur->next = new ListNode(sum % 10);
                cur = cur->next;
                overflow = sum / 10;
                list2 = list2->next;
                list1 = list1->next;
            }
        }
        print_list(result.next);
        return reverse_list(result.next);
    }
};

int main() {
    auto l1 = new ListNode(7);
    auto l2 = new ListNode(2);
    auto l3 = new ListNode(4);
    auto l4 = new ListNode(3);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;

    auto t1 = new ListNode(5);
    auto t2 = new ListNode(6);
    auto t3 = new ListNode(4);
    t1->next = t2;
    t2->next = t3;

    Solution sol;
    auto sum_list = sol.addTwoNumbers(l1, t1);
    print_list(sum_list);
    return 0;
}