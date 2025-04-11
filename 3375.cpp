class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            vector<int> occurrences(101, 0);
            for (int i = 0; i < nums.size(); i++) {
                occurrences[nums[i]]++;
            }
            int res = 0;
            for (int i = 0; i < occurrences.size(); i++) {
                if (occurrences[i] > 0 && k > i) {
                    return -1;
                } else if (occurrences[i] > 0 && k < i) {
                    res++;
                }
            }
    
            return res;
        }
    };