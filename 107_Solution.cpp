#include <iostream>
using namespace std;
#include <vector>
#include <queue>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        
        queue<TreeNode *> qu;
        qu.push(root);
        
        while(!qu.empty()){
            int curSize = qu.size();
            res.push_back(vector<int>());
            
            while(curSize>0){
                TreeNode * node = qu.front();
                qu.pop();
                
                res.back().push_back(node->val);
                if(node->left) qu.push(node->left);
                if(node->right) qu.push(node->right);
                curSize--;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(){
    return 0;
}