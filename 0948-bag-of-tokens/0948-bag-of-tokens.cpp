class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int start = 0;
        int end = tokens.size() - 1;
        int res = 0;
        int maxRes = 0;
        while(start <= end){
            if(power - tokens[start] >= 0){
                power -= tokens[start];
                res ++;
                maxRes = max(maxRes , res);
                start++;
            }else if(power - tokens[start] < 0 && res){
                power += tokens[end];
                end--;
                res--;
            }else{
                break;
            }
        }
        return maxRes;
    }
};