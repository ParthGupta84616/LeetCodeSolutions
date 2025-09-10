class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        queue<pair<int, int>> pq;
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == 0 || i == m - 1 || j == 0 || j == n - 1) &&
                    grid[i][j] == 1) {
                    visit[i][j] = true;
                    pq.push({i, j});
                }
                if (grid[i][j] == 1)
                    count++;
            }
        }
        while (!pq.empty()) {
            int R = pq.front().first;
            int C = pq.front().second;
            pq.pop();

            if (R + 1 < m && !visit[R + 1][C] && grid[R + 1][C] == 1) {
                visit[R + 1][C] = true;
                pq.push({R + 1, C});
            }
            if (R - 1 >= 0 && !visit[R - 1][C] && grid[R - 1][C] == 1) {
                visit[R - 1][C] = true;
                pq.push({R - 1, C});
            }
            if (C + 1 < n && !visit[R][C + 1] && grid[R][C + 1] == 1) {
                visit[R][C + 1] = true;
                pq.push({R, C + 1});
            }
            if (C - 1 >= 0 && !visit[R][C - 1] && grid[R][C - 1] == 1) {
                visit[R][C - 1] = true;
                pq.push({R, C - 1});
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visit[i][j])
                    count--;
            }
        }
        return count;
    }
};