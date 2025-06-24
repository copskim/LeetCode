class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> pairs(n);
        for (int i = 0; i < n; ++i) pairs[i] = { nums2[i], nums1[i] };
        sort(pairs.begin(), pairs.end(), [](const auto& a, const auto& b) {
            return a.first > b.first; });
        priority_queue<int, vector<int>, greater<int>> q;
        long long result = 0, sum = 0;
        for (auto& [first, second] : pairs) {
            sum += second;
            q.push(second);
            if (q.size() == k) {
                if (result < sum * first) result = sum * first;
                sum -= q.top();
                q.pop();
            }
        }
        return result;
    }
};