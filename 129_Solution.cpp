#include <iostream>
using namespace std;
#include <vector>
#include <queue>

//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int sumNumbers(TreeNode *root)
    {
        int sum = 0;
        queue<pair<TreeNode *, int>> qNode;
        qNode.push({root,0});

        while (qNode.size() != 0)
        {
            pair<TreeNode *, int> newPair = qNode.front();
            qNode.pop();
            TreeNode * currNode = newPair.first;
            int curSum = newPair.second;

            if(currNode != NULL){
                curSum = curSum * 10 + currNode->val;
                if(currNode->left == NULL && currNode->right == NULL){
                    sum += curSum;
                }
                else{
                    if(currNode->left) qNode.push({currNode->left,curSum});
                    if(currNode->right) qNode.push({currNode->right,curSum}); 
                }
            }
        }
        return sum;
    }
};

int main()
{
    return 0;
}