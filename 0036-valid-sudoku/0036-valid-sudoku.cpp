class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            map<char, int> Hmp;
            map<char, int> Vmp;
            for (int j = 0; j < board.size(); j++) {
                if (board[i][j] != '.') {
                    if (Hmp[board[i][j]] == 1) {
                        return false;
                    } else {
                        Hmp[board[i][j]]++;
                    }
                }
                if (board[j][i] != '.') {
                    if (Vmp[board[j][i]] == 1) {
                        return false;
                    } else {
                        Vmp[board[j][i]]++;
                    }
                }
            }
        }
        for (int boxRow = 0; boxRow < 9; boxRow += 3) {
            for (int boxCol = 0; boxCol < 9; boxCol += 3) {
                map<char, int> box_map;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        char val = board[boxRow + i][boxCol + j];
                        if (val != '.') {
                            if (box_map[val] == 1)
                                return false;
                            box_map[val]++;
                        }
                    }
                }
            }
        }
        return true;
    }
};