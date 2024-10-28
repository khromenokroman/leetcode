/*
 148. Sort List
Medium
Topics
Companies
Given the head of a linked list, return the list after sorting it in ascending order.



Example 1:


Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:


Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
Example 3:

Input: head = []
Output: []


Constraints:

The number of nodes in the list is in the range [0, 5 * 104].
-105 <= Node.val <= 105
 */

#include <iostream>
#include <vector>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* sortList(ListNode* head) {
        ListNode* ptr = head;
        ListNode* tmp = new ListNode();
        ListNode* orig = tmp;
        while (ptr) {
            tmp->next = new ListNode(ptr->val);
            tmp = tmp->next;
            ptr = ptr->next;
        }
        orig = orig->next;

        ListNode* ptr22 = orig;
        while (ptr22) {
            ListNode* tmp = orig;
            while (tmp) {
                if (tmp->next) {
                    if (tmp->val > tmp->next->val) {
                        int int_temp = 0;
                        int_temp = tmp->val;
                        tmp->val = tmp->next->val;
                        tmp->next->val = int_temp;
                    }
                }
                tmp = tmp->next;
            }
            ptr22 = ptr22->next;
        }

        ListNode* ptr222 = orig;
        while (ptr222) {
            std::cout << "val: " << ptr222->val << " ";
            ptr222 = ptr222->next;
        }
        std::cout << std::endl;
        return orig;
    }
};

int main() {
    //    ListNode l4{3};
    //    ListNode l3{1, &l4};
    //    ListNode l2{2, &l3};
    //    ListNode l1{4, &l2};
    ListNode l5{4};
    ListNode l4{4, &l5};
    ListNode l3{3, &l4};
    ListNode l2{5, &l3};
    ListNode l1{-1, &l2};

    ListNode* ptr = &l1;
    while (ptr) {
        std::cout << "val: " << ptr->val << " ";
        ptr = ptr->next;
    }
    std::cout << std::endl;

    Solution sol;
    auto list_new = sol.sortList(&l1);

    ListNode* ptr2 = list_new;
    while (ptr2) {
        std::cout << "val: " << ptr2->val << " ";
        ptr2 = ptr2->next;
    }
    std::cout << std::endl;

    return 0;
}