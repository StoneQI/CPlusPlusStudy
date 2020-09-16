#include "headers.h"

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>&& heights) {
        stack<int> dp;
        int max_val =0;
        if(heights.size()== 0) return 0;

        dp.emplace(0);

        for (int i = 1; i < heights.size(); i++)
        {
            while(!dp.empty()){
                if(heights[dp.top()] > heights[i]){
                    int length = heights[dp.top()];
                    dp.pop();
                    int weight = i;

                    if(!dp.empty()){
                        weight = i-dp.top()-1;
                    }

                    max_val =  max(max_val, length*weight);
                }else
                {
                    break;
                }
                
            }
            dp.push(i);
        }
        int end = dp.top();
        while (!dp.empty())
        {   
            int length = heights[dp.top()];
            dp.pop();
            int weight = heights.size();

            if(!dp.empty()){
                weight = heights.size()-dp.top()-1;
            }

            max_val =  max(max_val, length*weight);
            
        }
        return max_val;
    }
};


int main(int argc, const char** argv) {
    Solution sol;
    cout << sol.largestRectangleArea({1,1});
    return 0;
}