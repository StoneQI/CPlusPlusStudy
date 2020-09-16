#include "headers.h"

using namespace std;


class Solution {
public:
    vector<vector<int> > result;
    void dfs(int a, int sum, int k, int n, vector<int> &temp){
        if(sum > n){
            return;
        }
        if(temp.size() == k ){
            if( sum == n )
                result.emplace_back(temp);
            return ;
        }
        for (int i = a; i < 10; i++)
        {   
            sum += i;
            temp.emplace_back(i);
            dfs(i+1, sum, k,n,temp);
            temp.pop_back();
            sum -= i;
        }
        
    } 
    vector<vector<int>> combinationSum3(int k, int n) {
        if( k> 9){
            return result;
        }
        vector<int> temp;
        dfs(1,0,k,n,temp);

        return result;
    }
};

int main(int argc, const char** argv) {
    Solution sol;

    sol.combinationSum3(3,9);
    return 0;
}
