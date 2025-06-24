class Solution {
public:
    int guessNumber(int n) {
        int pick = n / 2;
        int lb = 0, rb = n;
        int retv;
        retv = -1;
        while ((retv = guess(pick))) {
            if (retv > 0) lb = pick;
            else if (retv < 0) rb = pick;
            pick = lb + (rb - lb + 1) / 2;
        }
        return pick;
    }
};