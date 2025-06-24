class Solution {
public:
    string reverseStr(string s, int k) {
        int sndx = 0;
        for (sndx = 0; sndx < s.size(); ) {
            int rlen = k;
            if (sndx + rlen > s.size()) rlen = s.size() - sndx;
            reverse(s.begin() + sndx, s.begin() + sndx + rlen);
            sndx += 2 * k;
        }
        return s;
    }
};