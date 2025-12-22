#include <vector>

/*
    Problem 26: Remove duplicates from sorted array
    Difficulty: Easy
    Time complexity: O(n), since we only iterate once through the array
    Space complexity: O(1), because we make an in-place ordering
    Categories: Two pointers

    Approach:
    We have 2 pointers. 'uniquePos' works as a pointer (and counter) for unique elements on the array, everytime we find a new element we save it and increase 'uniquePos'.
    Then we iterate with 'i' until a new element appears.
    In other words everytime we find a new elements, we save it and ignore every other appeareance
*/

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int element;
        int uniquePos = 0;
        int i = 0;
        while(i < nums.size()){
            element = nums[i];
            nums[uniquePos] = element;//Save the unique element
            ++uniquePos;
            while(i < nums.size() && element == nums[i]){++i;}//We go forward until a new number appears
        }
        return uniquePos;
    }
};