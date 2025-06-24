class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return(vector<string>{});
        vector<string> ds29{ "","",
            //2      3      4      5      6      7       8      9
            "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        int n = 1;
        for (int i = 0; i < digits.size(); i++) {
            int ndx = digits[i] - '0';
            n *= ds29[ndx].size();
        }
        vector<string> result; result.resize(n);
        int freq = n;
        for (int i = 0; i < digits.size(); i++) {
            int ndx = digits[i] - '0';
            string& s = ds29[ndx];
            int sz = ds29[ndx].size();
            freq /= sz;
            for (int j = 0; j < n;) {
                for (int k = 0; k < freq; k++, j++)
                    result[j] += s[(j / freq) % sz];
            }
        }
        return result;
    }
};