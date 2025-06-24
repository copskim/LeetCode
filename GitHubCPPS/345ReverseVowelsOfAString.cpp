class Solution {
public:
    string reverseVowels(string s) {
        std::string rs{ s };
        int length = s.size();
        int i, j;
        for (i = 0, j = length - 1; j >= i; ) {
            while (!isVowel(s[i]) && i <= j) i++;
            while (!isVowel(s[j]) && j >= i) j--;
            if (i >= j) break;
            if (s[i] != s[j]) { rs[i] = s[j]; rs[j] = s[i]; }
            i++; j--;
        }
        return rs;
    }
private:
    bool isVowel(char cc) {
        char c = std::tolower(cc);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
};