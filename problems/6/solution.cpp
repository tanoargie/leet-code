class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        string res;
        for (int i = 0; i < numRows; i++) {
            int increment = 2 * (numRows - 1);
            for (int j = i; j < s.size(); j += increment) {
                res += s[j];
                int middle = j + increment - (i * 2);
                if (i > 0 && i < numRows - 1 && middle < s.size()) {
                    res += s[middle];
                }
            }
        }
        
        return res;
    }
};
