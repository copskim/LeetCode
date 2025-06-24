class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> r{ asteroids };
        for (int ri = 0, li = -1; ri < n; ri++) {
            if (r[ri] < 0) {
                if (li < 0) continue;
                li = ri - 1;
                while (li >= 0) {
                    if (r[li] == 0) { li--; continue; }
                    if (r[li] < 0) break;
                    if (abs(r[ri]) == r[li]) {
                        //                        cout << "li ri : " << li << " " << ri << endl;
                        r[li] = 0;
                        r[ri] = 0;
                        break;
                    }
                    else if (abs(r[ri]) > r[li]) {
                        r[li] = 0;
                        li--;
                    }
                    else {
                        r[ri] = 0;
                        break;
                    }
                }
            }
            else li = ri;
        }
        int remCnt = 0;
        vector<int> retv(n, 0);
        for (int i = 0; i < n; i++) {
            //            cout << r[i] << " " << endl;
            if (r[i] != 0) retv[remCnt++] = r[i];
            //            cout << remCnt << " " << endl;
        }
        retv.resize(remCnt);
        return(retv);
    }
};