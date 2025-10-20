class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int res = 0;
        for(auto op : operations){
            if(op[op.size() - 1] == '+' || op[0] == '+'){
                res++;
            }else{
                res--;
            }
        }
        return res;
    }
};