class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<int> anagram;
        for (auto& w : startWords) {
            int bv = 0;
            for (char c : w) bv |= 1 << (c - 'a');
            anagram.insert(bv);
        }
        int anagrams = 0;
        for (auto& w : targetWords) {
            int bv = 0;
            for (char c : w) bv |= 1 << (c - 'a');
            for (char c : w) {
                int pit = bv ^ (1 << (c - 'a'));
                if (anagram.contains(pit)) {
                    anagrams++;
                    break;
                }
            }
        }
        return anagrams;
    }
};