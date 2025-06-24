
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> niMap;
        for (int i = 0; i < nums.size(); i++) {
            if (niMap.count(target - nums[i]))
                return { niMap[target - nums[i]], i };
            niMap[nums[i]] = i;
        }
        return {};
    }
};