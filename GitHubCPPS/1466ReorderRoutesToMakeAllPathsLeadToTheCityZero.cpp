
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> g(n);
        vector<vector<int>> r(n);

        for (int i = 0; i < connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];
            g[u].push_back(v);
            r[v].push_back(u);
        }

        queue<int> q;
        vector<int> visited(n, 0);
        q.push(0);
        int cnt = 0;

        while (!q.empty()) {
            int curr = q.front(); q.pop();
            visited[curr] = 1;
            for (int i = 0; i < r[curr].size(); i++) {
                if (!visited[r[curr][i]]) {
                    q.push(r[curr][i]);
                }
            }
            for (int i = 0; i < g[curr].size(); i++) {
                if (!visited[g[curr][i]]) {
                    q.push(g[curr][i]);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};