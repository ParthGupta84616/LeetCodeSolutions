class Solution {
public:
    bool judgeCircle(string moves) {
        int resH = 0;
        int resV = 0;
        for (int i = 0; i < moves.size(); i++) {
            if (moves[i] == 'U')
                resH++;
            else if (moves[i] == 'D')
                resH--;
            else if (moves[i] == 'L')
                resV++;
            else
                resV--; 
        }
        return (resH == 0 && resV == 0) ? true : false;
    }
};