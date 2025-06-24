class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int maxprtime = events[0][1]; int maxprindex = events[0][0];
        for (int i = 0; i < events.size() - 1; i++) {
            int prtime = events[i + 1][1] - events[i][1];
            if (maxprtime < prtime) {
                maxprtime = prtime;
                maxprindex = events[i + 1][0];
            }
            else if (maxprtime == prtime) {
                if (maxprindex > events[i + 1][0]) maxprindex = events[i + 1][0];
            }
        }
        return maxprindex;
    }
};