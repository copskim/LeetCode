
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x < 10) return true;
        int ldeci = 1e9;
        while ((x / ldeci) == 0) ldeci /= 10;
        int rdeci = 10;
        int rx = x;
        while (ldeci >= rdeci) {
            int ldgt = (rx / ldeci) % 10;
            int rdgt = (rx % rdeci) / (rdeci / 10);
            if (ldgt != rdgt) return false;
            ldeci /= 10;
            rdeci *= 10;
        }
        return true;
    }
};