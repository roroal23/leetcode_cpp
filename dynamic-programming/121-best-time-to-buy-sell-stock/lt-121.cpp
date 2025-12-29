#include <vector>
#include <limits.h>
#include <iostream>

/*
    Problem 121: Best time to buy sell stock
    Difficulty: Easy
    Time complexity: O(n), where n is the array length
    Space complexity: O(1)

    Approach:
    For each price we consider buying and selling. For buying, we check if the current price is better than the best one so far (the local minimum).
    For selling, we check if selling at this price (having bought at the best price so far) gives us a bigger profit than the best one so far (the local maximum).

                7   1   5   3   6   4
    min price   7   1   1   1   1   1
    max profit  -   -6  4   4   5   5

    We evaluate the selling operation first to use the previous best buying price (if the current buying price is better) since we can't buy and sell at the same day

*/

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int min_price = prices[0];
        int max_profit = INT_MIN;
        
        for(int i = 1; i < prices.size(); ++i){
            if(prices[i] - min_price > max_profit) {max_profit = prices[i] - min_price;}
            if(prices[i] < min_price) {min_price = prices[i];}
        }
        if(max_profit > 0) {return max_profit;}
        else {return 0;}
    }
};

/*Mini test*/
int main(int argc, char const *argv[])
{
    Solution sol;
    std::vector<int> vec{7,1,5,3,6,4};
    std::vector<int> vec2{7,6,4,3,1};
    std::cout << sol.maxProfit(vec);//Expected: 5
    std::cout << sol.maxProfit(vec2);//Expected: 0
}
