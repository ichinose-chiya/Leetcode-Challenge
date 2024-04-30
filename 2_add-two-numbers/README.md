# [Leetcode-02_add-two-numbers](https://leetcode.com/problems/add-two-numbers/description/)

### Description

You are given two **non-empty** linked lists representing two non-negative integers. The digits are stored in **reverse order**, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/10/02/addtwonumber1.jpg)

```
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
```

**Example 2:**

```
Input: l1 = [0], l2 = [0]
Output: [0]
```

**Example 3:**

```
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
```

 

**Constraints:**

- The number of nodes in each linked list is in the range `[1, 100]`.
- `0 <= Node.val <= 9`
- It is guaranteed that the list represents a number that does not have leading zeros.

### Solution

It's a very easy question, as we can simply do the traversal on both linked-lists together and add their value together as well as the carry number of last result of adding, which can be set to 0 ast the beginning.

If these linked-lists have different lengths, we can just continue to do the traversal on the longer one and just add the carry number only. So here comes my solution:

```cpp
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

        if (l1 == nullptr || l2 == nullptr)
        {
            goto copy_left;
        }

        while (l1 != nullptr && l2 != nullptr)
        {
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
        while (left != nullptr)
        {
            curr = new ListNode(left->val + carry);
            carry = curr->val / 10;
            curr->val %= 10;
            *last = curr;
            last = &curr->next;
            left = left->next;
        }

        while (carry != 0)
        {
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
```
