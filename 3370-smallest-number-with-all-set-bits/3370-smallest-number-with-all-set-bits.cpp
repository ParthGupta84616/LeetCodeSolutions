class Solution {
public:
    int smallestNumber(int n) {
        vector<int> res = {1,3,7,15,31,63,127,255,511,1023};
        for(int i = 0 ; i < res.size() ; i++){
            if(n <= res[i]){
                return res[i];
            }
        }
        return -1;
    }
};