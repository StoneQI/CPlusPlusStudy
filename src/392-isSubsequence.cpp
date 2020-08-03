#include "headers.h"
class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        std::vector<int>  dp(t.size()+1,0);
        int last = 0;
        for (size_t i = 1; i <= s.size(); i++)
        {
            for (size_t j = 1; j <= t.size(); j++)
            {   
                int temp = dp[j];
                if(s[i-1] == t[j-1]){
                    dp[j] = last+1;
                }else
                {
                    dp[j] = std::max(dp[j],dp[j-1]);
                }
                last = temp;
                
            }
        }

        return dp[t.size()] == s.size();
    }
};

int main(int argc, char const *argv[])
{
    Solution  sol;
    std::cout << sol.isSubsequence("aaaaaa","bbaaaa");
    return 0;
}
