class Solution {
public:
    std::vector<bool> kidsWithCandies(std::vector<int>& candies, int extraCandies) {
        std::vector<bool> result{};
        result.reserve(candies.size());

        int max_val = *std::max_element(candies.begin(), candies.end());

        for (int candy : candies) {
            if (candy + extraCandies >= max_val) result.push_back(true);
            else result.push_back(false);
        }
        return result;
    }
};