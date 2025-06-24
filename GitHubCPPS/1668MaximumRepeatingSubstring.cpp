class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int n = sequence.size(); int wl = word.size();
        map<int, int> streak;
        int npos, pos = 0;
        while ((npos = sequence.find(word, pos)) != string::npos) {
            if (npos == pos) {
                if (streak.count(pos)) {
                    if (pos + wl <= n) {
                        streak[pos + wl] = streak[pos] + 1;
                        streak.erase(pos);
                    }
                }
                else {
                    streak[pos + wl] = 1;
                }
            }
            pos++;
        }
        if (streak.size() == 0) return 0;
        auto maxpair = max_element(streak.begin(), streak.end(),
            [](const auto& a, const auto& b) { return a.second < b.second; });
        return maxpair->second;
    }
};