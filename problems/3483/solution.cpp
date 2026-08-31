class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int res = 0;
        vector<int> appearances(10, 0);
        for (int i = 0; i < digits.size(); i++) {
            appearances[digits[i]]++;
        }
        for (int i = 100; i < 1000; i++) {
            if (i % 2 == 0) {
                int test = i;
                int lastDigit = test % 10;
                test = test / 10;
                int middleDigit = test % 10;
                test = test / 10;
                int firstDigit = test % 10;
                if (appearances[firstDigit] > 0) {
                    appearances[firstDigit]--;
                    if (appearances[middleDigit] > 0) {
                        appearances[middleDigit]--;
                        if (appearances[lastDigit] > 0) {
                            res++;
                        }
                        appearances[middleDigit]++;
                    }
                    appearances[firstDigit]++;
                }   
            }
        }
        return res;
    }
};
