#include <vector>
#include <iostream>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxArea = 0;

        while(left < right) {
            maxArea = std::max(maxArea, (right - left)* std::min(height[left], height[right]));
            if(height[left] > height[right]) right--;
            else left++;
        }
        return maxArea;
    }
};