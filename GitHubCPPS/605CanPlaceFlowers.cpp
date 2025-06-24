class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int numAdjHole{};
        int tnumAdjHole{};
        int numholes = flowerbed.size();
        int i, planted;
        for (i = 0; i < numholes; i++) {
            planted = flowerbed[i];
            if (planted == 0) {
                numAdjHole++;
                //end exception
                if (i == (numholes - 1)) {
                    if (numAdjHole == numholes) tnumAdjHole = (numholes + 1) / 2;
                    else tnumAdjHole += numAdjHole / 2;
                    numAdjHole = 0;
                }
            }
            if (planted == 1) {
                //begin exception
                if (numAdjHole == i) tnumAdjHole += numAdjHole / 2;
                else tnumAdjHole += (numAdjHole - 1) / 2;
                numAdjHole = 0;
            }
            if (tnumAdjHole >= n) return true;
        }
        return false;
    }
};