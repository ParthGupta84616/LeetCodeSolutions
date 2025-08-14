class Solution {
public:
    string largestGoodInteger(string num) {
        string maxStr = "";
        for(int i = 2 ; i < num.size() ; i ++){
            if(num[i-2]==num[i-1] && num[i-1]==num[i]){
                string newStr = "";
                newStr.push_back(num[i]);
                newStr.push_back(num[i]);
                newStr.push_back(num[i]);
                if(maxStr < newStr){
                    maxStr = newStr;
                };
                newStr = "";
            }
        }
        return maxStr;
    }
};