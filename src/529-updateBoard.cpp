#include "headers.h"

using std::vector;
using std::queue;

class Solution {
public:
 Solution(const Solution&) =delete;
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        queue<std::pair<int,int> > temp;
        
        int rows = board.size();
        int cols = board[0].size();
        board[click[0][click[1]] = 'C';
        int step_x[8] = {-1,-1,-1, 0,0, 1, 1, 1};
        int step_y[8] = {-1,0,1,1,-1,-1, 0, 1 }; 
        temp.push({click[0],click[1]});

        while (!temp.empty())
        {   
            std::pair<int, int> item = temp.front();
            temp.pop();
            switch (board[item.first][item.second])
            {
            case 'M':
                board[item.first][item.second] = 'X';
                break;
            case 'C':
                int count = 0;
                queue<std::pair<int,int> > tempNegi;
                for (size_t i = 0; i < 8; i++)
                {
                    int col = item.first+step_x[i];
                    int row = item.second+step_y[i];
                    if(col>=0 && col < cols && row >=0 && row < rows){
                        if(board[row][col] == 'E') {
                            board[row][col] = 'C';
                            tempNegi.push({col,row});
                        }

                        if(board[row][col] == 'X') count++;  
                    }
                }
                if(count){ board[item.first][item.second] = count;}
                else {
                    board[item.first][item.second] = 'B';
                    while(!tempNegi.empty()){temp.emplace(tempNegi.front());tempNegi.pop();}
                }
                break;
            default:
                break;
            }
        }

        return board;
        
        

    }
};