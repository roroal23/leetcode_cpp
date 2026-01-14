#include <iostream>

/*
    Problem 508: Fibonnaci numbers
    Difficulty: Easy
    Time complexity: O(n), where n is the number
    Space complexity: O(1)

    Approach:
    We use the look-up Fibonacci table, and compress it since we only need the last 2 entries of the table in every iteration
    f(5) =  f(3)+
            f(4)=   f(2)+
                    f(3)=   f(1)+
                            f(2)=   f(0)+
                                    f(1)

*/

class Solution {
public:
    int fib(int n) {

        int last2 = 0;//f(0) = 0
        int last1 = 1;//f(1) = 1
        int aux;
        for(int i = 0; i < n; ++i){
            aux = last1;
            last1 = last2 + last1;//Save next iteration f(n-1): current f(n) = f(n-1) + f(n-2)
            last2 = last1;//Save next iteration f(n-2): current f(n-1)
        }
        return last1;
    }
};

/*Test*/
int main()
{
    Solution sol;
    std::cout << sol.fib(10);
}
