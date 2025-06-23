
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ents = height.size();
        int capa_max = 0;
        int l_end = 0, r_end = ents - 1;
        while (l_end < r_end) {
            int lhgt = height[l_end];
            int rhgt = height[r_end];
            int hgt = lhgt > rhgt ? rhgt : lhgt;
            int width = r_end - l_end;
            int capa = hgt * width;
            if (capa > capa_max) capa_max = capa;
            rhgt > lhgt ? l_end++ : r_end--;
        }
        return capa_max;
    }
};