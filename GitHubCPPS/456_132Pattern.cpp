class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<pair<int, int>> s;
        int iMin = 0, iMax = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[iMin]) {
                if (iMin != iMax) s.push({ iMin,iMax });
                iMin = i; iMax = i;
            }
            else if (nums[i] < nums[iMax]) {
                if (nums[i] > nums[iMin]) {
                    return true;
                }
            }
            else if (nums[i] > nums[iMax]) {
                if (!s.size()) iMax = i;
                else {
                    while (s.size()) {
                        auto [iN, iX] = s.top();
                        if (nums[i] < nums[iN]) {
                            iMax = i;
                            break;
                        }
                        else if (nums[i] < nums[iX]) {
                            if (nums[i] > nums[iN]) {
                                return true;
                            }
                            break; //nums[i] == nums[iN]
                        }
                        else if (nums[i] < nums[iX])
                            ;
                        else {
                            s.pop();
                            iMax = i;
                        }
                    }
                }
            }
        }
        return false;
    }
};