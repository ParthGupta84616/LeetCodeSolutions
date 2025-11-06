class Solution {
public:
    class DSU {
    public:
        vector<int> parent, rank;

        DSU(int n) {
            parent.resize(n + 1);
            rank.resize(n + 1, 1);
            for (int i = 1; i <= n; ++i) {
                parent[i] = i;
            }
        }

        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }

        void unite(int x, int y) {
            int rx = find(x);
            int ry = find(y);
            if (rx == ry) return;

            if (rank[rx] < rank[ry]) {
                parent[rx] = ry;
            } else if (rank[rx] > rank[ry]) {
                parent[ry] = rx;
            } else {
                parent[ry] = rx;
                rank[rx]++;
            }
        }
    };

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        DSU dsu(c);

        for (auto& conn : connections) {
            dsu.unite(conn[0], conn[1]);
        }

        vector<bool> online(c + 1, true);
        unordered_map<int, set<int>> grid;

        for (int i = 1; i <= c; ++i) {
            int root = dsu.find(i);
            grid[root].insert(i);
        }

        vector<int> result;

        for (auto& q : queries) {
            int type = q[0], x = q[1];
            int root = dsu.find(x);

            if (type == 2) {
                if (online[x]) {
                    online[x] = false;
                    grid[root].erase(x);
                }
            } else {
                if (online[x]) {
                    result.push_back(x);
                } else {
                    if (grid[root].empty()) {
                        result.push_back(-1);
                    } else {
                        result.push_back(*grid[root].begin());
                    }
                }
            }
        }

        return result;
    }
};
