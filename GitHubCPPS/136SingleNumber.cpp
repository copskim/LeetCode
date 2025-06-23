
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        const int maxents{ 60001 };
        vector<bool> hit(maxents, false);
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int ndx = nums[i] + maxents / 2;
            if (hit[ndx]) hit[ndx] = false;
            else hit[ndx] = true;
        }
        int r = INT_MAX;
        for (int i = 0; i < maxents; i++) {
            if (hit[i]) {
                r = i - maxents / 2;
            }
        }
        return(r);
    }
};

//I failed to think-out the below principle.
//But I shouldn't fail to keep this in my mind.
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int r = 0;
        for (const int num : nums) r ^= num;
        return r;
    }
};