class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ti = 0;
        int sl = s.size();
        int tl = t.size();
        for (int si = 0; si < sl; si++) {
            while (ti < tl && t[ti] != s[si]) ti++;
            if (ti == tl) return false;
            ti++;
        }
        return true;

    }
};