class Solution {
public:
    constexpr inline bool is_vowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int maxVowels(string s, int k) {
        int len = s.size();
        int max_vowels = INT_MIN;
        int volcnt = 0;

        //the first subarray
        for (int i = 0; i < k; i++) {
            if (is_vowel(s[i])) volcnt++;
        }
        for (int i = 0; ; i++) {
            if (volcnt > max_vowels) max_vowels = volcnt;
            if (i == len - k) break;
            if (is_vowel(s[i])) volcnt--;
            if (is_vowel(s[i + k])) volcnt++;
        }
        return max_vowels;

    }
};