
#include "headers.h"

class Solution {
public:
    int count = 0;
    int InversePairs(std::vector<int> data) {
        Sort(data,0,data.size()-1);

        // for (auto &&i : data)
        // {
        //     std::cout << i << " " << std::endl;
        // }
        return count;
    }

    void Sort(std::vector<int> &data,int l, int r){
        if(l>=r) return;
        int mid = l+((r-l) >> 1);
        Sort(data,l, mid);
        Sort(data,mid+1, r);
        merge(data,l,mid,r);
    }

    void merge(std::vector<int> &data,int l, int mid, int r){
        int tempNumber[r-l+1];
        int i = l, j=mid+1, k=0;
        while (i <= mid && j <= r)
        {
            if(data[i] <= data[j]){
                tempNumber[k++] =data[i++];
            }else
            {
                count = mid-i+1;
                tempNumber[k++] =data[j++];
            }
        }

        while (i <= mid)
        {
            tempNumber[k++] = data[i++];
        }
        while (j <= r)
        {
            tempNumber[k++] = data[j++];
        }

        k=0;
        while ( l <=  r)
        {
            data[l++] = tempNumber[k++];
        }
        
    }
};

int main(int argc, const char** argv) {
    Solution solution;
    solution.InversePairs({2,1,0,6,2,3,8,9});
    return 0;
}