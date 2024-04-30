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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res, **last, *curr, *left;
        int carry;

        last = &res;
        carry = 0;

        if (l1 == nullptr || l2 == nullptr) {
            goto copy_left;
        }

        while (l1 != nullptr && l2 != nullptr) {
            curr = new ListNode(l1->val + l2->val + carry);
            carry = curr->val / 10;
            curr->val %= 10;
            *last = curr;
            last = &curr->next;
            l1 = l1->next;
            l2 = l2->next;
        }

copy_left:
        left = (l1 == nullptr ? l2 : l1);
        while (left != nullptr) {
            curr = new ListNode(left->val + carry);
            carry = curr->val / 10;
            curr->val %= 10;
            *last = curr;
            last = &curr->next;
            left = left->next;
        }

        while (carry != 0) {
            curr = new ListNode(carry);
            carry = curr->val / 10;
            curr->val %= 10;
            *last = curr;
            last = &curr->next;
        }

        *last = nullptr;
        return res;
    }
};