class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowest = INT_MAX, maxprofit = 0;
        for (int price : prices) {
            if (price < lowest) lowest = price;
            else {
                if (maxprofit < price - lowest) maxprofit = price - lowest;
            }
        }
        return maxprofit;
    }
};