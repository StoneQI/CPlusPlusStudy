#include "headers.h"

class Solution {
public:
    std::string LeftRotateString(std::string str, int n) {
        int length = str.size();
        char newString[length+1];
        newString[length] ='\0';

        for (int i = 0; i < length; i++)
        {
            int newPosition = (i-n+length)%length;
            newString[newPosition] = str[i];
        }

        return newString;
    }
};

int main(int argc, const char** argv) {

    Solution solution;
    std::cout << solution.LeftRotateString("abcXYZdef",3) << std::endl;
    return 0;
}