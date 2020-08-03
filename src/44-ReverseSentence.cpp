#include "headers.h"

class Solution {
public:

    std::string ReverseSentence(std::string str) {
        if( str.size()==0) return str;
        int length = str.size();
        std::string result;
        int end =length;
        for (int i = length-1; i >= 0; i--)
        {
            if(str[i]== ' '){
                result.append(str.substr(i+1,end-i-1));
                result.append(" ");
                end = i;
            }
        }
        result.append(str.substr(0,end));
        return result;
    }
};

int main(int argc, const char** argv) {

    Solution solution;
    std::cout << solution.ReverseSentence("12345") << std::endl;
    return 0;
}