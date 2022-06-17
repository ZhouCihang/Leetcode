#include <iostream>
using namespace std;
#include <vector>
#include <stack>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        traverse(root, result);
        return result;
    }
    void traverse(TreeNode *cur, vector<int> &vec)
    {
        if (cur == NULL)
            return;
        traverse(cur->left, vec);
        vec.push_back(cur->val);
        traverse(cur->right, vec);
    }

    vector<int> inorderTraversalIter(TreeNode *root)
    {
        stack<TreeNode *> st;
        vector<int> result;

        TreeNode *cur = root;
        while(cur != NULL || !st.empty()){
            if(cur != NULL){
                st.push(cur);
                cur = cur->left;
            }
            else{
                cur = st.top();
                st.pop();
                result.push_back(cur->val);
                cur = cur->right;
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}