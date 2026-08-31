class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int left = 0;
        int right = height.size() - 1;
        while (left < right) {
            int area = (right - left)*min(height[left], height[right]);
            if (area > maxArea) {
                maxArea = area;
            }
            if (height[right] >= height[left]) {
                //this is max area from left, no point in lowering right
                left++;
            } else {
                right--;
            }
        }
        return maxArea;
    }
};
