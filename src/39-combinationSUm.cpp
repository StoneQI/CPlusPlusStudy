#include "headers.h"

using namespace std;

class Solution {
public:
    set<vector<int>> result;

    void dfs(int sum,vector<int> &temp, vector<int>& candidates, int target){

        for (int i = 0; i < candidates.size(); i++)
        {   
            if( (sum+candidates[i]) > target) return;
            if( (sum+candidates[i]) == target){
                temp.emplace_back(candidates[i]);
                result.insert(temp);
                temp.pop_back();
                continue;
            }
            temp.emplace_back(candidates[i]);
            dfs(sum+candidates[i],temp,candidates,target);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        dfs(0,temp,candidates,target);
        return vector<vector<int>>(result.begin(),result.end());
    }
};