class Solution {
public:
    int minimumChairs(string s) {
        int chairs = 0;
        int maxchairs = 0;
        for (char c : s) {
            if (c == 'E') {
                chairs++;
                if (maxchairs < chairs) maxchairs = chairs;
            }
            else if (c == 'L') chairs--;
        }
        return maxchairs;
    }
};