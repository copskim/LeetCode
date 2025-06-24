class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                traverse(isConnected, visited, i, n);
                provinces++;
            }
        }
        return provinces;
    }
private:
    void traverse(vector<vector<int>>& graph, vector<bool>& visited, int city, int n) {
        queue<int> q;
        q.push(city);
        visited[city] = true;
        while (!q.empty()) {
            int cn = q.front(); q.pop();
            for (int j = 0; j < n; j++) {
                if (graph[cn][j] == 1 && !visited[j]) {
                    visited[j] = true;
                    q.push(j);
                }
            }

        }
    }
};