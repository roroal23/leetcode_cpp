#include <iostream>

/*
    Problem 1137: N-th Tribonacci number
    Difficulty: Easy
    Time complexity: O(n), where n is the given number
    Space complexity: O(n)

    Approach:
    Just like in Fibonacci, we store past results in an array so we don't have to calculate them again.

*/

class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) {return 0;}
        if(n == 1) {return 1;}
        if(n == 2) {return 1;}

        int sequence[n+1];
        sequence[0] = 0;
        sequence[1] = 1;
        sequence[2] = 1;
        for(int i = 3; i <= n; ++i){
                sequence[i] = sequence[i-1] + sequence[i-2] + sequence[i-3];
        }
        return sequence[n];
    }
};

/*Test*/
int main()
{
    Solution sol;
    std::cout << sol.tribonacci(25);
}
