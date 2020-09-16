#include "headers.h"

using std::vector;
using std::max;
class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int len_A = A.size();
        int len_B = B.size();
        auto  dp =vector(len_A+1,vector(len_B+1,0));
        int ans = 0;
        for(int i =1;i <len_A;i++){
            for(int j = 1; j <len_B ;j++){
                if(A[i]==B[j]) dp[i][j] = dp[i-1][j-1] +1;
                else dp[i][j] = max(dp[i-1][j,dp[i][j-1]]);

                ans = max(ans,dp[i][j]);
            }
        }

        return ans;
        
    }
};