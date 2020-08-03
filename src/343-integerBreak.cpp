#include "headers.h"

class Solution {
public:
    
    // std::vector<int> dp{std::vector<int>(59,0);
    
    int integerBreak1(int n) {
        
        if (n<=4)
        {
            return n;
        }
        if( dp[n] !=0) return dp[n];
        int max = 0;
        for(int i = 1; i<n;i++){
            max = std::max(max,i*integerBreak(n-i));
        }
        dp[n] = max;
        return max;
    }

    std::vector<int> dp{std::vector<int>(59,0)};
    int integerBreak(int n) {
        if(n==2) return 1;
        if(n ==3) return 2;
        return search(n);

    }
    int search(int n){
        if (n<=4)
        {
            return n;
        }
        if( dp[n] !=0) return dp[n];
        int max = 0;
        for(int i = 1; i<n;i++){
            max = std::max(max,i*search(n-i));
        }
        dp[n] = max;
        return max;
    }
};

int main(int argc, const char** argv) {
    Solution sol;
    std::cout << sol.integerBreak(5) << std::endl;
    return 0;
}