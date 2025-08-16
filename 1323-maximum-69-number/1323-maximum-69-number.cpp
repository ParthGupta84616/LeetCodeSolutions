class Solution {
public:
    int maximum69Number(int num) {
        string newSum = to_string(num); 
        for (int i = 0; i < newSum.size(); i++) {
            if (newSum[i] == '6') {
                newSum[i] = '9'; 
                break; 
            }
        }
        return stoi(newSum);
    }
};
