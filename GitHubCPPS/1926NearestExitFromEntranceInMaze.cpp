class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        queue<pair<int, int>> q;
        q.emplace(entrance[0], entrance[1]);
        maze[entrance[0]][entrance[1]] = '+';
        int steps = 1;
        while (!q.empty()) {
            for (int k = q.size(); k > 0; --k) {
                auto [i, j] = q.front();
                q.pop();
                int x = i - 1, y = j;

                if (x >= 0 && maze[x][y] == '.') {
                    if (x == 0 || x == m - 1 || y == 0 || y == n - 1) return steps;
                    maze[x][y] = '+'; q.emplace(x, y);
                }
                x = i; y = j - 1;
                if (y >= 0 && maze[x][y] == '.') {
                    if (x == 0 || x == m - 1 || y == 0 || y == n - 1) return steps;
                    maze[x][y] = '+'; q.emplace(x, y);
                }
                x = i + 1; y = j;
                if (x < m && maze[x][y] == '.') {
                    if (x == 0 || x == m - 1 || y == 0 || y == n - 1) return steps;
                    maze[x][y] = '+'; q.emplace(x, y);
                }
                x = i; y = j + 1;
                if (y < n && maze[x][y] == '.') {
                    if (x == 0 || x == m - 1 || y == 0 || y == n - 1) return steps;
                    maze[x][y] = '+'; q.emplace(x, y);
                }
            }
            steps++;
        }
        return -1;
    }
};