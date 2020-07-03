#include <vector>
#include <stack>
#include <iostream>
class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {       
        if (rows<=0 || cols <=0 || str ==nullptr){
            return false;
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i*cols+j] == str[0])
                {
                     std::vector<bool> isFlag(rows*cols+1,false);
                     if(isPath(matrix,rows,cols,str,i,j,0,isFlag)){
                         return true;
                     }
                }
            }
        }
        return false;
           
    }

private:
    bool isPath(char* matrix, int rows, int cols, char* str,int i,int j,int next,std::vector<bool> &isFlag){

        if(str[next]=='\0'){
                return true;
        }
        if(i<0 || j<0 || i>=rows ||j >= cols){
            return false;
        } 


        if (isFlag[i*cols+j] ==true)
        {
            return false;
        }
        bool isSubPtah = false;

        if (matrix[i*cols+j] == str[next])
        {   

            ++next;
            
            isFlag[i*cols+j] =true;
            isSubPtah = isPath(matrix,rows,cols,str,i-1,j,next,isFlag);
            if (isSubPtah)
            {
                return true;
            }
            isSubPtah = isPath(matrix,rows,cols,str,i+1,j,next,isFlag);
            if (isSubPtah)
            {
                return true;
            }
            isSubPtah = isPath(matrix,rows,cols,str,i,j-1,next,isFlag);
                        if (isSubPtah)
            {
                return true;
            }
            isSubPtah = isPath(matrix,rows,cols,str,i,j+1,next,isFlag);
                        if (isSubPtah)
            {
                return true;
            }
        }
        isFlag[i*cols+j]=true;
        return false;
    }
};

int main(int argc, const char** argv) {
    char matrix[9] ={'a','b','c','d','e','f','g','h','j'};
    char str[3]={'a','d','\0'};

    Solution solution;
    std::cout<< solution.hasPath(matrix,3,3,str)<<std::endl;
    return 0;
}