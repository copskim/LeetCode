class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        for (int i = 0; i < words.size(); i++) {
            int ri = (startIndex + i) % n;
            int li = startIndex - i; if (li < 0) li += n;
            if (words[ri] == target) return i;
            if (words[li] == target) return i;
        }
        return -1;
    }
};