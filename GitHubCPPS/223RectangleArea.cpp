class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int areasum = (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1);
        int ox1 = 0, ox2 = 0, oy1 = 0, oy2 = 0;
        //ax1     ax2
        //    bx1     bx2
        if (ax1 <= bx1 && ax2 >= bx1 && ax2 <= bx2) {
            ox1 = bx1; ox2 = ax2;
        }
        //ax1           ax2
        //    bx1  bx2
        else if (ax1 <= bx1 && ax2 >= bx2) {
            ox1 = bx1; ox2 = bx2;
        }
        //     ax1  ax2
        //bx1           bx2
        else if (ax1 >= bx1 && ax2 <= bx2) {
            ox1 = ax1; ox2 = ax2;
        }
        //     ax1       ax2
        //bx1       bx2
        else if (ax1 >= bx1 && ax1 <= bx2 && ax2 >= bx2) {
            ox1 = ax1; ox2 = bx2;
        }
        //ax1 ax2
        //         bx1  bx2
        //         ax1  ax2
        //bx1 bx2
        else { //ax2 < bx1 || ax1 > bx2, disjoint case

        }
        if (ay1 <= by1 && ay2 >= by1 && ay2 <= by2) {
            oy1 = by1; oy2 = ay2;
        }
        else if (ay1 <= by1 && ay2 >= by2) {
            oy1 = by1; oy2 = by2;
        }
        else if (ay1 >= by1 && ay2 <= by2) {
            oy1 = ay1; oy2 = ay2;
        }
        else if (ay1 >= by1 && ay1 <= by2 && ay2 >= by2) {
            oy1 = ay1; oy2 = by2;
        }
        else {

        }
        int areaoverlap = (ox2 - ox1) * (oy2 - oy1);

        return areasum - areaoverlap;
    }
};