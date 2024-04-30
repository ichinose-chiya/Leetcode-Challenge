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
