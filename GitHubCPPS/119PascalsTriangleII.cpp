class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> biCoffN(rowIndex + 1);
        biCoffN[0].push_back(1);
        for (int i = 1; i <= rowIndex; i++) {
            vector<int>& pre = biCoffN[i - 1];
            vector<int>& cur = biCoffN[i];
            cur.push_back(1);
            for (int j = 1; j < i; j++) {
                cur.push_back(pre[j - 1] + pre[j]);
            }
            cur.push_back(1);
        }
        return biCoffN[rowIndex];
    }
};