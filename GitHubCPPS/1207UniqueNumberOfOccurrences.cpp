
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> occBrd;
        sort(arr.begin(), arr.end());
        int occCnt = 0;
        for (int i = 0; i < arr.size(); i++) {
            occCnt++;
            if ((i + 1) >= arr.size()) {
                if (occBrd.find(occCnt) != occBrd.end()) return false;
            }
            else if (arr[i] != arr[i + 1]) {
                if (occBrd.find(occCnt) != occBrd.end()) return false;
                occBrd[occCnt]++;
                occCnt = 0;
            }
        }

        return true;
    }
};