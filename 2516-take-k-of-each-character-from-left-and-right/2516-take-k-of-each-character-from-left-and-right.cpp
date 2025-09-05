class Solution {
public:
    int takeCharacters(string s, int k) {
        int aCount = 0, bCount = 0, cCount = 0;
        for (char ch : s) {
            if (ch == 'a') aCount++;
            else if (ch == 'b') bCount++;
            else cCount++;
        }
        if (aCount < k || bCount < k || cCount < k)
            return -1;

        int minute = s.size();
        int start = 0;
        int aCountTemp = 0, bCountTemp = 0, cCountTemp = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a') aCountTemp++;
            else if (s[i] == 'b') bCountTemp++;
            else cCountTemp++;

            while (aCount - aCountTemp < k || bCount - bCountTemp < k || cCount - cCountTemp < k) {
                if (s[start] == 'a') aCountTemp--;
                else if (s[start] == 'b') bCountTemp--;
                else cCountTemp--;
                start++;
            }

            minute = min(minute, (int)s.size() - (i - start + 1));
        }
        return minute;
    }
};
