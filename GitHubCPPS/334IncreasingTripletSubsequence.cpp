class Solution {
public:
    bool increasingTriplet(std::vector<int>& nums) {
        int smaller = INT_MAX, bigger = INT_MAX;
        for (int value : nums) {
            if (value > bigger) return true;
            if (value > smaller) bigger = value;
            else smaller = value;
        }
        return false;
    }
};