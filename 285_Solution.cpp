#include <iostream>
using namespace std;
#include <vector>
#include <queue>

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
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p)
    {
        queue<TreeNode *> qu;
        TreeNode *curr = root;
        bool found = false;

        while(qu.size()!= 0 || curr != NULL){
            while(curr != NULL){
                qu.push(root);
                curr = curr->left;
            }
            curr = qu.front();
            qu.pop();
            if(found) return curr;
            if(curr == p) found = true;
            curr = curr->right;
        }
        return NULL;
    }
};

int main()
{
    return 0;
}