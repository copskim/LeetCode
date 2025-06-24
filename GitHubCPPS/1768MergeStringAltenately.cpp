class Solution {
private:
    string m_str;

public:
    Solution() : m_str("") {}

    string mergeAlternately(string word1, string word2) {
        const int len1 = word1.length();
        const int len2 = word2.length();
        if (len1 < 1 && len2 < 1)
            return("");
        if (m_str.length() < len1 + len2)
            m_str.resize(len1 + len2);
        char* cptr = &m_str[0];
        int j = 0;
        for (int i1 = 0, i2 = 0; i1 < len1 || i2 < len2;) {
            if (i1 < len1)
                cptr[j++] = word1[i1++];
            if (i2 < len2)
                cptr[j++] = word2[i2++];
        }
        return (m_str);
    }
};