class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    int kv;
    vector<vector<int>> combinationSum3(int k, int n) {
        ans.clear(); temp.clear();
        kv = k;
        dfs(1, n);
        return ans;
    }
private:
    void dfs(int start, int sum) {
        if (sum == 0 && temp.size() == kv) {
            ans.emplace_back(temp);
            return;
        }
        if (start > 9 || start > sum || temp.size() >= kv) {
            return;
        }
        temp.emplace_back(start);
        dfs(start + 1, sum - start);
        temp.pop_back();
        dfs(start + 1, sum);
    }
};