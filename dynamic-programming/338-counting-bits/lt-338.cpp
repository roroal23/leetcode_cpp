#include <iostream>
#include <vector>

/*
    Problem 338: Counting bits
    Difficulty: Easy
    Time complexity: O(n), where n is the given number
    Space complexity: O(n)

    Approach:
    Everytime we need a new bit to represent the numbers, that new bit is set to 1 and the rest of the bits
    follow the pattern of the previous numbers.
    --1 bit--
    0 -> 0  ] __    ]           ]
    0 -> 1  ]   |   ]           ]
    --2 bits--  |+1 ] ___       ]
    2 -> 1   <--|   ]    |      ]
    3 -> 2          ]    |+1    ] __
    --3 bits--           |      ]   |
    4 -> 1   <-----------|      ]   |
    5 -> 2                      ]   |
    6 -> 2                      ]   |+1
    7 -> 3                      ]   |
    --4 bits--                      |
     ...    <-----------------------|

    
*/

class Solution {
public:
    std::vector<int> countBits(int n) {
        std::vector<int> bits(n + 1);
        bits[0] = 0;
        if(n == 0) {return bits;}
        bits[1] = 1;
        if(n == 1) {return bits;}

        int iters_to_reset = 2;//Set to 2^x and then decreases up to 0
        int table_idx = 0;
        for(int num = 2; num <= n; ++num){
            if(iters_to_reset == 0){
                table_idx = 0;
                iters_to_reset = num;
            }
            bits[num] = bits[table_idx] + 1;
            ++table_idx;
            --iters_to_reset;
        }
        return bits;
    }
};

/*Test*/
int main()
{
    Solution sol;
    std::vector<int> bits;
    bits = sol.countBits(15);
    for(int bit: bits){
        std::cout << bit << " ";
    }
    
}
