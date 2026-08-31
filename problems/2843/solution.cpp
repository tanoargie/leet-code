class Solution {
    public:
        int countSymmetricIntegers(int low, int high) {
            int res = 0;
            for (int i = low; i <= high; i++) {
                if (i >= 10 && i < 100 && i % 11 == 0) {
                    res++;
                } else if (i >= 1000) {
                    int front = (i / 1000) + (i % 1000) / 100;
                    int back = (i % 100) / 10 + (i % 10);
                    if (back == front) res++;
                }
            }
            return res;
        }
    };