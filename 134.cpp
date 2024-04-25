class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> diff(gas.size(), 0);
        for (int i = 0; i < gas.size(); i++) {
            diff[i] = gas[i] - cost[i];
        }

        int sum = 0;
        for (int i = 0; i < diff.size(); i++) {
            sum += diff[i];
        }
        // do kadane's algorithm in diff to find maximum sum in circular array
        int max_so_far = INT_MIN;
        int curr_max = 0;
        int curr_min = 0;
        int min_so_far = INT_MAX;
        int start_max = 0;
        int end_min = 0;
        int s_max = 0;
        for (int i = 0; i < diff.size(); i++) {
            curr_max += diff[i];
            curr_min += diff[i];
            if (max_so_far < curr_max) {
                max_so_far = curr_max;
                start_max = s_max;
            }
            if (min_so_far > curr_min) {
                min_so_far = curr_min;
                end_min = (i + 1) % diff.size();
            }
            if (curr_max < 0) {
                curr_max = 0;
                s_max = (i + 1) % diff.size();
            }
            if (curr_min > 0) {
                curr_min = 0;
            }
        }
        int max = std::max(max_so_far, (sum - min_so_far));
        //if max == max_so_far means does not go circular, else it does
        int start;
        if (max == max_so_far) {
            start = start_max;
        } else {
            start = end_min;
        }
        // if there is a solution it will be starting from start index
        sum = diff[start];
        int i = start + 1;
        while (i != start) {
            sum += diff[i % diff.size()];
            i++;
            i = i % diff.size();
        }

        if (sum >= 0) {
            return start;
        } else {
            return -1;
        }
    }
};
