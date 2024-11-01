/*
206. Reverse Linked List
Easy
Topics
Companies
Given the head of a singly linked list, reverse the list, and return the reversed list.



Example 1:


Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:


Input: head = [1,2]
Output: [2,1]
Example 3:

Input: head = []
Output: []


Constraints:

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000


Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?
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
    ListNode* reverseList(ListNode* head) {
        ListNode* reverse_list = nullptr;
        while(head){
            ListNode *tmp_node = head;
            head = head->next;
            tmp_node->next = reverse_list;
            reverse_list = tmp_node;
        }
        return reverse_list;
    }
};
int main() {
    auto l1 = new ListNode(1);
    auto l2 = new ListNode(2);
    auto l3 = new ListNode(4);
    l1->next = l2;
    l2->next = l3;


    Solution sol;
    auto reverse_list = sol.reverseList(l1);
    while (reverse_list) {
        std::cout << reverse_list->val << " ";
        reverse_list = reverse_list->next;
    }
    std::cout << std::endl;
    return 0;
}