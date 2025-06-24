class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        for (int i = 0; i < s.size(); i++) {
            int iv = 26 - (s[i] - 'a');
            iv *= (i + 1);
            sum += iv;
        }
        return sum;
    }
};