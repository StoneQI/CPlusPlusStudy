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
            
            std::deque<TreeNode*> treeDeque;
            std::vector<std::vector<int> > result;
            if(pRoot == nullptr)return result;
            treeDeque.push_back(pRoot);
            while(treeDeque.size()> 0){
                int size = treeDeque.size();
                std::vector<int> lineTreeNode;
                for (int i = 0; i < size; i++)
                {   

                    TreeNode *item = treeDeque.front();
                   
                    lineTreeNode.push_back(item->val);
                    if (item->left != nullptr)
                    {
                        treeDeque.push_back(item->left );
                    }
                    if (item->right != nullptr)
                    {
                        treeDeque.push_back(item->right );
                    }
                    
                    treeDeque.pop_front();
                }
                result.push_back(lineTreeNode);
            }

            return result;

        }
    
};