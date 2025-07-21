class Solution {
public:
    string makeFancyString(string s) {
        string res = "";
        int eksath = 0;
        res.push_back(s[0]);
        for (int i = 1; i < s.length(); i++) {
            if(s[i] == s[i-1]){
                eksath++;
            }else{
                eksath = 0;
            }
            if(eksath <= 1){
                res += s[i];
            }
        }
        return res;
    }
};