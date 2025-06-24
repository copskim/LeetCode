class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;
        string t = goal + goal;
        if (t.find(s) != string::npos) return true;
        return false;
    }
};