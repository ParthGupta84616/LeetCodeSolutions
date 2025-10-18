class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int minCost = 0;
        int lastCost = neededTime[0];
        int lastColor = colors[0];
        for(int i = 1 ; i < colors.size() ; i++){
            if(lastColor == colors[i]){
                if(lastCost < neededTime[i]){
                    minCost += lastCost;
                    lastCost = neededTime[i];
                }else{
                    minCost += neededTime[i];
                }
                continue;
            }
            lastColor = colors[i];
            lastCost = neededTime[i];
        }
        return minCost;
    }
};