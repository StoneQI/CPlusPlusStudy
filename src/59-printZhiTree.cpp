#include "headers.h"

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(nullptr), right(nullptr) {
    }
};

class Solution {
public:
        std::vector<std::vector<int> > Print(TreeNode* pRoot) {
           
            std::vector<std::vector<int> > result;
            if(pRoot == nullptr)return result;

            int lineNumber = 0;
            std::deque<TreeNode*> treeDeque;
            treeDeque.push_back(pRoot);
            while(treeDeque.size()> 0){
                int size = treeDeque.size();
                std::vector<int> lineTreeNode;
               
                    for (int i = 0; i < size; i++)
                    {   
                        TreeNode *item = treeDeque.front();
                        lineTreeNode.push_back(item->val);
                        treeDeque.pop_front();

                        if (item->left != nullptr)
                        {
                            treeDeque.push_back(item->left );
                        }
                        if (item->right != nullptr)
                        {
                            treeDeque.push_back(item->right );
                        }

                    }
                 ++lineNumber;
                if (!(lineNumber&1)){
                        std::reverse(lineTreeNode.begin(),lineTreeNode.end());
                    
                }
                result.push_back(lineTreeNode);
            }
            return result;

        }
    
};