# [Leetcode_01-two-sum](https://leetcode.cn/problems/two-sum/)

### Description

Given an array of integers `nums` and an integer `target`, return *indices of the two numbers such that they add up to `target`*.

You may assume that each input would have ***exactly\* one solution**, and you may not use the *same* element twice.

You can return the answer in any order.

 

**Example 1:**

```
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
```

**Example 2:**

```
Input: nums = [3,2,4], target = 6
Output: [1,2]
```

**Example 3:**

```
Input: nums = [3,3], target = 6
Output: [0,1]
```

 

**Constraints:**

- `2 <= nums.length <= 104`
- `-109 <= nums[i] <= 109`
- `-109 <= target <= 109`
- **Only one valid answer exists.**

 

**Follow-up:** Can you come up with an algorithm that is less than `O(n2) `time complexity?

### Solution

The easiest way to solve that is to make the traversal on the `nums`, adding two numbers with different index and checking for whether the result is equal to the `target`, which will lead to a `O(n2)` complexity in time and a `O(1)` complexity in space because it doesn't require any extra memory.

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int arr_size = nums.size();

        /* brute-force */
        for (int i = 0; i < arr_size; i++) {
            for (int j = i + 1; j < arr_size; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }

        /* not found */
        return {};
    }
};
```

Though the code can pass the check, high complexity is surely not what we expect. So it comes to the time for optimization now. To optimize the algorithm, the universal way is to trade the space for time. 

Note that what we really want to find is a set of `{nums[i], nums[j]}` that satisfy both the `i != j` and `nums[i] + nums[j] == target`, we can record every `nums[i]` we've just met while doing the traversal, and calculate the `target - nums[record]` to see whether it's equal to every `nums[i]` we're walking on, which leads to only the `O(N)` complexity in time and a `O(N)` complexity in space for extra storage.

It's easy to find out that the **hash table** is just the one can help us do the record. Here comes my final solution:


```cpp
#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        int arr_size = nums.size();

        /* use map to optimize */
        for (int i = 0; i < arr_size; i++) {
            if (map.find(target - nums[i]) == map.end()) {
                map[nums[i]] = i;
            } else {
                return {map[target - nums[i]], i};
            }
        }

        /* not found */
        return {};
    }
};
```
