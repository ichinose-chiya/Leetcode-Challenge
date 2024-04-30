### Description

Given a string s, find the length of the longest substring without repeating characters.

Example 1:

> Input: s = "abcabcbb"
> 
> Output: 3
> 
> Explanation: The answer is "abc", with the length of 3.


Example 2:

> Input: s = "bbbbb"
> 
> Output: 1
> 
> Explanation: The answer is "b", with the length of 1.

Example 3:

> Input: s = "pwwkew"
> 
> Output: 3
> 
> Explanation: The answer is "wke", with the length of 3.
> 
> Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

- `0 <= s.length <= 5 * 104`
- `s` consists of English letters, digits, symbols and spaces.

### Solution

To figure out the max length of potential substrings in a given string, the easiest way we may think of is to enumerate all of the possible substrings that can be existed in the target, which can be done simply by an `O(N^2)` algorithm that treats every localtion `i` in the target string as a start point and to numerate all the following position as `j`, resulting in making substring as `[i,...,j]`.

While the substring is getting longer, we count the existance of each character at the same time by simly using a table to do so at the very beginnig of each loop. Thus we could have a solution like this:

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0;

        for (int i = 0; i < s.length(); i++)
        {
            int current_length = 0;
            bool alpha_table[256];

            for (int j = 0; j < 256; j++)
            {
                alpha_table[j] = false;
            }

            for (int j = i; j < s.length(); j++)
            {
                if (alpha_table[s[j]] == false)
                {
                    alpha_table[s[j]] = true;
                    current_length++;
                }
                else
                {
                    break;
                }
            }

            if (current_length > max_len)
            {
                max_len = current_length;
            }
        }

        return max_len;
    }
};
```

However, an `O(N^2)` algorithm seems not good, so can we get it optimized?