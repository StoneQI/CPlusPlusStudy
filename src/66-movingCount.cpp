#include <iostream>

class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {   
        if (threshold<0||rows <=0 || cols <=0)
        {
            return 0;
        }
        if(threshold ==0){
            return 1;
        }
        // int count[rows][cols] ={0};
        int counts =0;
        int isMoving[rows*cols+1] = {0};
        check(threshold,rows,cols,0,0,counts,isMoving);
        // for (int i = 0; i < rows; i++) 
        // {
        //     for (int j = 0; j < cols; j++) 
        //     {
        //         if ((sumNum(i)+sumNum(j)) <= threshold){
        //             counts++;
        //         }
        //     }
        // }
        std::cout<<counts;
        return counts;
    }

private:

    void check(int threshold, int rows, int cols,int i,int j, int &counts,int isMoving[]){
        if(i<0 || j<0 || i>=rows ||j >= cols){
            return ;
        }
        if (isMoving[i*cols+j]==1){
            return ;
        }
        if((sumNum(i)+sumNum(j)) <= threshold){
            counts++;
            isMoving[i*cols+j]=1;
            check(threshold,rows,cols,i-1,j,counts,isMoving);
            check(threshold,rows,cols,i+1,j,counts,isMoving);
            check(threshold,rows,cols,i,j-1,counts,isMoving);
            check(threshold,rows,cols,i,j+1,counts,isMoving);
        }
        isMoving[i*cols+j]=1;

    }


    void check2(int threshold, int rows, int cols,int i,int j, int &counts,int isMoving[]){
        if(i<0 || j<0 || i>=rows ||j >= cols){
            return ;
        }
        if (isMoving[i*cols+j]==1){
            return ;
        }
        if((sumNum(i)+sumNum(j)) <= threshold){
            counts++;
            isMoving[i*cols+j]=1;
            check(threshold,rows,cols,i-1,j,counts,isMoving);
            check(threshold,rows,cols,i+1,j,counts,isMoving);
            check(threshold,rows,cols,i,j-1,counts,isMoving);
            check(threshold,rows,cols,i,j+1,counts,isMoving);
        }
        isMoving[i*cols+j]=1;

    }

    int sumNum(int i ){
        int sum =0 ;
        while((i) != 0){
            sum += i%10;
            i= i/10;
            std::cout<<sum;
        }
        return sum;
    }
};

int main(int argc, const char** argv) {
    Solution solution;
    std::cout<< solution.movingCount(2,2,2);

    return 0;
}