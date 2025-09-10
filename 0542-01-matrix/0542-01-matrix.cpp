class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> res(mat.size(), vector<int>(mat[0].size(), 0));
        vector<vector<int>> visited(mat.size(),
                                    vector<int>(mat[0].size(), false));
        queue<pair<pair<int, int>, int>> pq;

        int m = mat.size();
        int n = mat[0].size();
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 0) {
                    pq.push({{i, j}, 0});
                    visited[i][j] = true;
                }
            }
        }
        while (!pq.empty()) {
            int R = pq.front().first.first;
            int C = pq.front().first.second;
            int w = pq.front().second;
            pq.pop();
            res[R][C] = w;
            if (R + 1 < m && !visited[R + 1][C]) {
                visited[R + 1][C] = true;
                pq.push({{R + 1, C}, w+1});
            }
            if (R - 1 >= 0 && !visited[R - 1][C]) {
                visited[R - 1][C] = true;
                pq.push({{R - 1, C}, w+1});
            }
            if (C + 1 < n && !visited[R][C + 1]) {
                visited[R][C + 1] = true;
                pq.push({{R, C + 1}, w+1});
            }
            if (C - 1 >= 0 && !visited[R][C - 1]) {
                visited[R][C - 1] = true;
                pq.push({{R, C - 1}, w+1});
            }
        }
        return res;
    }
};