#include <iostream>
#include <string>
#include <vector>

/*
    Problem XXX: Description
    Difficulty: Easy
    Time complexity: O(n), where n is
    Space complexity: O(1)

    Approach:







    INCOMPLETO
*/

class Solution {
public:
    int maxRepeating(const std::string sequence, const std::string word) {
        int n = sequence.size();
        int m = word.size();
        std::vector<int> repeated_words(n, 0);
        std::vector<int> letter_to_match(n + 1, 0);

        for(int i = 0; i < n; ++i){
            if(sequence[i] == word[letter_to_match[i]]){
                letter_to_match[i +1] = letter_to_match[i] +1;
            }
            else {//Letters dont match, we dont continue with this subsequence
                if(sequence[i] == word[0]){letter_to_match[i+1] = 1;}
                else {letter_to_match[i+1] = 0;}//That letter is the begginning of a new word
            }

            //If we finished a full word
            if(letter_to_match[i +1] == m){
                int previous_idx = i - m;
                if(previous_idx >= 0) {repeated_words[i] = repeated_words[previous_idx] +1;}
                else {repeated_words[i] = 1;}

                letter_to_match[i+1] = 0;
            }
        }

        int max = 0;
        for(int i = 0; i < n; ++i){
            if(repeated_words[i] > max) {
                max = repeated_words[i];
            }   
        }
        return max;
    }
};

struct TestCase {
    std::string sequence;
    std::string word;
    int correct_answer;
};

/*Test*/
int main()
{
    Solution sol;
    std::vector<TestCase> tests = {
        {"ababc", "ab", 2},
        {"ababc", "ba", 1},
        {"ababc", "ac", 0},
        {"abcaabcababcabca", "abc", 2}
    };
    for(TestCase test: tests){
        int my_answer = sol.maxRepeating(test.sequence, test.word);
        std::cout << "Sequence: " << test.sequence << " Word: " << test.word << " Correct answer: " << test.correct_answer 
        << " My answer: " << my_answer << "\n";
    }
}