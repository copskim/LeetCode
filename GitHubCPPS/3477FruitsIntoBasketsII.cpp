class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<int>b(baskets);
        int placedCnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (b[j] >= fruits[i]) {
                    b[j] = 0;
                    placedCnt++;
                    break;
                }
            }
        }
        return n - placedCnt;
    }
};