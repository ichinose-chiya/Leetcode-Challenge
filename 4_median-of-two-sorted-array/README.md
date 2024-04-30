# [Leetcode-04_median-of-two-sorted-arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/description/)

### Description

Given two sorted arrays `nums1` and `nums2` of size `m` and `n` respectively, return **the median** of the two sorted arrays.

The overall run time complexity should be `O(log (m+n))`.

 

**Example 1:**

> Input: nums1 = [1,3], nums2 = [2]
> 
> Output: 2.00000
> 
> Explanation: merged array = [1,2,3] and median is 2.

**Example 2:**

> Input: nums1 = [1,2], nums2 = [3,4]
> 
> Output: 2.50000
> 
> Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

Constraints:

- `nums1.length == m`
- `nums2.length == n`
- `0 <= m <= 1000`
- `0 <= n <= 1000`
- `1 <= m + n <= 2000`
- `-10^6 <= nums1[i], nums2[i] <= 10^6`

### Solution

As both the arraies had been sorted, we can just simply use two pointers to do the traversal on each of them together, and the rule for which pointer to be chosen to be moved ahead is to compare the value on the position of the specific array that the pointer points to, giving the smaller one the priority to move firstly. 

While the total length of movement has come to the median point of the total length of the two arraies, we can give out the reult. So here comes my basic solution that is simply implemented like this:

```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total_length = nums1.size() + nums2.size();
        int nr1_position = 0, nr2_position = 0;
        int median_position = total_length / 2;
        bool is_even = (median_position * 2) == total_length;

        if (is_even)
        {
            median_position -= 1;
        }

        while ((nr1_position + nr2_position) < median_position)
        {
            if (nr1_position < nums1.size() && nr2_position < nums2.size())
            {
                if (nums1[nr1_position] < nums2[nr2_position])
                {
                    nr1_position++;
                }
                else
                {
                    nr2_position++;
                }
            }
            else if (nr1_position < nums1.size())
            {
                nr1_position++;
            }
            else
            {
                nr2_position++;
            }
        }

        double result;

        if (nr1_position < nums1.size() && nr2_position < nums2.size())
        {
            if (nums1[nr1_position] < nums2[nr2_position])
            {
                result = nums1[nr1_position];
                nr1_position++;
            }
            else
            {
                result = nums2[nr2_position];
                nr2_position++;
            }
        }
        else if (nr1_position < nums1.size())
        {
            result = nums1[nr1_position];
            nr1_position++;
        }
        else
        {
            result = nums2[nr2_position];
            nr2_position++;
        }

        if (is_even)
        {
            if (nr1_position < nums1.size() && nr2_position < nums2.size())
            {
                if (nums1[nr1_position] < nums2[nr2_position])
                {
                    result += nums1[nr1_position];
                    nr1_position++;
                }
                else
                {
                    result += nums2[nr2_position];
                    nr2_position++;
                }
            }
            else if (nr1_position < nums1.size())
            {
                result += nums1[nr1_position];
                nr1_position++;
            }
            else
            {
                result += nums2[nr2_position];
                nr2_position++;
            }

            result /= 2;
        }

        return result;
    }
};
```
