class Solution {
public:
    set<pair<int, int>> seenIdx;
    vector<long long> islandSum;

    long long findIsland(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() ||
            grid[i][j] == 0 || seenIdx.find({i, j}) != seenIdx.end()) {
            return 0;
        }

        seenIdx.insert({i, j});
        long long sum = grid[i][j];

        long long sumTop = findIsland(grid, i - 1, j);
        long long sumRight = findIsland(grid, i, j + 1);
        long long sumLeft = findIsland(grid, i, j - 1);
        long long sumBottom = findIsland(grid, i + 1, j);

        return sum + sumTop + sumRight + sumLeft + sumBottom;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        long long largeSum = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] != 0 && seenIdx.find({i, j}) == seenIdx.end()) {
                    islandSum.push_back(findIsland(grid, i, j));
                }
            }
        }

        for (int i = 0; i < islandSum.size(); i++) {
            largeSum = max(largeSum ,islandSum[i] );
        }
        return largeSum;
    }
};
