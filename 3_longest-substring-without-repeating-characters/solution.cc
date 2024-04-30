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
