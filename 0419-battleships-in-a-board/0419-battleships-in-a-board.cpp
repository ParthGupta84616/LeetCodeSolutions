#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        set<pair<int, int>> seenIdx;
        vector<long long> islandSum;

        function<long long(int, int)> findIsland = [&](int i, int j) -> long long {
            if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() ||
                board[i][j] == '.' || seenIdx.find({i, j}) != seenIdx.end()) {
                return 0;
            }

            seenIdx.insert({i, j});
            long long sum = board[i][j] - 'Y';

            sum += findIsland(i - 1, j);
            sum += findIsland(i + 1, j);
            sum += findIsland(i, j - 1);
            sum += findIsland(i, j + 1);

            return sum;
        };

        long long count = 0;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] != '.' && seenIdx.find({i, j}) == seenIdx.end()) {
                    islandSum.push_back(findIsland(i, j));
                    count++;
                }
            }
        }

        return count;
    }
};
