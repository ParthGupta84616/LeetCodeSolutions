class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> pyass;
        int basta = 0;
        for(int i = 0 ; i < rocks.size() ; i++){
            pyass.push_back(capacity[i] - rocks[i]);
        }
        sort(pyass.begin() , pyass.end());
        int i = 0;
        while(i < rocks.size()){
            additionalRocks -= pyass[i];
            if(additionalRocks >= 0){
                basta++;
                i++;
            }else{
                break;
            }
        }
        return basta;
    }
};