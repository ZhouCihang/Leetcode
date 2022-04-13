#include <iostream>
using namespace std;
#include <vector>
#include <string>

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
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> result;
        string path = "";
        
        dfs(root, result, path);
        return result;
    }
    void dfs(TreeNode *root, vector<string> &result, string path){
        if(root == NULL){
            return;
        }
        path.append(to_string(root->val));
        path.append("->");

        if(root->left == NULL && root->right == NULL){
            path.erase(path.length()-2,2);
            result.push_back(path);
        }
        dfs(root->left, result, path);
        dfs(root->right, result, path);
    }
};

int main()
{
    Solution solution;
    TreeNode root(1);
    TreeNode lroot(2);
    TreeNode rroot(3);
    TreeNode rrroot(5);
    
    root.left = &lroot;
    root.right = &rroot;

    lroot.right = &rrroot;
    
    vector<string> result;
    result = solution.binaryTreePaths(&root);

    for (int i = 0; i<result.size(); i++){
        cout<< result[i] << " ";
    }
    return 0;
}