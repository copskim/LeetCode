class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        unordered_map<string, pair<int, int>> cmap;
        int vndx = 0;
        for (vector<string> sta : responses) {
            for (string st : sta) {
                if (cmap.count(st)) {
                    if (cmap[st].first == vndx) continue;
                }
                cmap[st].second++; //count
                cmap[st].first = vndx; //marking this as counted
            }
            vndx++; //next vector
        }
        string highestStr{}; int highestCnt = 0;
        for (auto it = cmap.begin(); it != cmap.end(); it++) {
            if (it->second.second > highestCnt) {
                highestCnt = it->second.second;
                highestStr = it->first;
            }
            else if (it->second.second == highestCnt) {
                highestStr = min(highestStr, it->first);
            }
        }
        return highestStr;
    }
};