class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, vector<int>> pointsGroupedByY;
        for (const auto& point : points) {
            int x = point[0];
            int y = point[1];
            pointsGroupedByY[y].push_back(x);
        }

        long long MOD = 1'000'000'007;

        long long totalHorizontalSegments = 0;
        long long sumOfSquaredSegments = 0;

        for (const auto& [y_level, x_coords] : pointsGroupedByY) {
            long long pointsOnThisLine = x_coords.size();

            if (pointsOnThisLine < 2) {
                continue;
            }

            long long segmentsOnThisLine =
                pointsOnThisLine * (pointsOnThisLine - 1) / 2;

            totalHorizontalSegments =
                (totalHorizontalSegments + segmentsOnThisLine) % MOD;

            long long squared =
                (segmentsOnThisLine % MOD * segmentsOnThisLine % MOD) % MOD;
            sumOfSquaredSegments = (sumOfSquaredSegments + squared) % MOD;
        }

        long long squareOfTotal =
            (totalHorizontalSegments * totalHorizontalSegments) % MOD;

        long long numerator =
            (squareOfTotal - sumOfSquaredSegments + MOD) % MOD;

        long long half = 500000004;
        long long finalCount = (numerator * half) % MOD;

        return static_cast<int>(finalCount);
    }
};