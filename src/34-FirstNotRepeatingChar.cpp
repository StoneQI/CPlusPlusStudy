#include "headers.h"

class Solution {
public:
    int FirstNotRepeatingChar(std::string str) {
        std::unordered_map<char,int> repeatingChar;
        std::vector<char> orderSet;
        for (size_t i = 0; i < str.size(); i++)
        {   
            

            if(repeatingChar.count(str[i]) == 0){
                repeatingChar[str[i]] = i;
            }else
            {
                 repeatingChar[str[i]] = -1;
            }
            
        }
        int min = str.size()+1;
        for (auto &&i : repeatingChar)
        {
            if(i.second != -1){
                if(i.second < min){
                    min =i.second;
                }
            }
        }
        if (min == str.size()+1)
        {
            return -1;
        }
        
        return min;
        
    }
};

int main(int argc, const char** argv) {
    Solution solution;
    std::cout << solution.FirstNotRepeatingChar("google") << std::endl; 

    return 0;
}