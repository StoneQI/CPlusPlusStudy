#include "headers.h"

class Solution {
public:
    std::vector<int> multiply(const std::vector<int>& A) {
        
        const unsigned lenght = A.size();
        if (lenght<2)
        {
            return A;
        }
        std::vector<int>  B(lenght,0);

        int head[lenght];
        int end[lenght];
        head[0] =A[0];
        end[lenght-1] = A[lenght-1];
        for (size_t i = 1; i < lenght; i++)
        {
            head[i] = head[i-1]*A[i]; 
            end[lenght-1-i] = end[lenght-i]*A[lenght-i-1];
        }
        
        for (size_t i = 1; i < B.size()-1; i++)
        {
            B[i] = head[i-1]*end[i+1];
        }
        B[0]= end[1];
        B[lenght-1] =head[lenght-2];

        return B;

    }
};

int main(int argc, const char** argv) {
    Solution solution;
    for(auto var : solution.multiply({1,2,3,4,5}))
    {
        std::cout << var <<std::endl;
    }
    return 0;
}