#include <iostream>
#include <vector>
#include <string>

/*
    Problem 944: Delete Columns to Make Sorted
    Difficulty: Easy
    Time complexity: O(n*k), where n is number of string and k is the fixed length for each string
    Space complexity: O(1)
*/

class Solution {
public:
    int minDeletionSize(std::vector<std::string>& strs) {
        int deletedColumns = 0;
        const int strCount = strs.size();
        const int strLength = strs[0].size();
        for(int col = 0; col < strLength; ++col){ //Iterate through each column
            for(int row = 1; row < strCount; ++row){ //Verify that every string is ordered for that column
                if(strs[row - 1][col] > strs[row][col]){//If it is not ordered, this column must be deleted
                    ++deletedColumns;
                    break;
                }

            }
        }
        return deletedColumns;
    }
};