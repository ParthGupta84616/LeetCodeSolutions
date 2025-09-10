class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        if (image[sr][sc] == color)
            return image;
        int originalColor =image[sr][sc];
        queue<pair<int, int>> pq;
        pq.push({sr, sc});
        int m = image.size();
        int n = image[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        while (!pq.empty()) {
            int newSr = pq.front().first;
            int newSc = pq.front().second;
            image[newSr][newSc] = color;
            pq.pop();
            if (newSr + 1 < image.size()) {
                if (image[newSr + 1][newSc] == originalColor &&
                    !visited[newSr + 1][newSc]) {
                    pq.push({newSr + 1, newSc});
                    visited[newSr + 1][newSc] = true;
                }
            }

            if (newSr - 1 >= 0) {
                if (image[newSr - 1][newSc] == originalColor &&
                    !visited[newSr - 1][newSc]) {
                    pq.push({newSr - 1, newSc});
                    visited[newSr - 1][newSc] = true;
                }
            }

            if (newSc + 1 < image[0].size()) {
                if (image[newSr][newSc + 1] == originalColor &&
                    !visited[newSr][newSc + 1]) {
                    pq.push({newSr, newSc + 1});
                    visited[newSr][newSc + 1] = true;
                }
            }

            if (newSc - 1 >= 0) {
                if (image[newSr][newSc - 1] == originalColor &&
                    !visited[newSr][newSc - 1]) {
                    pq.push({newSr, newSc - 1});
                    visited[newSr][newSc - 1] = true;
                }
            }
        }
        return image;
    }
};