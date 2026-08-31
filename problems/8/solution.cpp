class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
        int i = 0;

        while (i < s.size() && s[i] == ' ') {
            i++;
        }
        if (i < s.size() && (s[i] == '-' || s[i] == '+')) {
            if (s[i] == '-') {
                sign = -1;
            }
            i++;
        }
        while (i < s.size() && s[i] == '0') {
            i++;
        }

        bool digit = true;
        long res = 0;

        while (i < s.size() && digit) {
            if (isdigit(s[i])) {
                res = res * 10 + (s[i] - '0');
                if (res > INT_MAX) {
                    if (sign < 0) {
                        return INT_MIN;
                    } else {
                        return INT_MAX;
                    }
                }
            } else {
                digit = false;
            }
            i++;
        }
        
        return sign * res;
    }
};
