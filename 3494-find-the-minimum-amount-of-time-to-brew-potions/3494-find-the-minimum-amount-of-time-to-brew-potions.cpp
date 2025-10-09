class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        vector<int> temp(skill.size(), 0);
        for (int i = 0; i < mana.size(); i++) {
            for (int j = 0; j < skill.size(); j++) {
                int MaxTemp;
                if (i == 0 && j == 0) {
                    temp[j] = skill[j] * mana[i];
                    continue;
                } else if (j == 0) {
                    MaxTemp = temp[j];
                } else {
                    MaxTemp = max(temp[j], temp[j - 1]);
                }
                temp[j] = MaxTemp + (skill[j] * mana[i]);
            }
            int CurrentMax = temp[temp.size() - 1];

            for (int j = skill.size() - 2; j >= 0; j--) {
                temp[j] = CurrentMax - mana[i] * skill[j + 1];
                CurrentMax = temp[j];
            }
        }
        return temp[temp.size() - 1];
    }
};