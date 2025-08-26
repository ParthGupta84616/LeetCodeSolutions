class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiagonal = 0;
        int Area = 0;
        for (auto d : dimensions) {
            if (abs(d[0] * d[0] + d[1] * d[1]) > maxDiagonal  || (abs(d[0] * d[0] + d[1] * d[1]) == maxDiagonal && Area <= d[0]*d[1])) {
                maxDiagonal = abs(d[0] * d[0] + d[1] * d[1]);
                Area = d[0]*d[1];
            }
        }
        return Area;
    }
};