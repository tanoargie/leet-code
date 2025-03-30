class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res;
        vector<int> lastPos(26, 0);
        for (int i = 0; i < s.size(); i++) {
            lastPos[s[i] - 'a'] = i;
        }
        int maxCurrent = 0;
        int lastCut = 0;
        for (int i = 0; i < s.size(); i++) {
            if (lastPos[s[i] - 'a'] > maxCurrent) {
                maxCurrent = lastPos[s[i] - 'a'];
            }
            if (i == maxCurrent) {
                res.push_back(maxCurrent - lastCut + 1);
                lastCut = maxCurrent + 1;
            }
        }

        return res;
    }
};
