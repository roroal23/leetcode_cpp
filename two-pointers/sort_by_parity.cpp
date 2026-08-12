#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> sortArrayByParity(std::vector<int>& nums) {
        int odd = 0;
        int even = nums.size() - 1;
        while(odd < even){
            if(nums[odd] % 2 != 0 && nums[even] % 2 == 0){
                int aux = nums[odd];
                nums[odd] = nums[even];
                nums[even] = aux;
            }

            if(nums[odd] % 2 == 0) ++odd;
            if(nums[even] % 2 != 0) --even;
        }
        return nums;
    }
};