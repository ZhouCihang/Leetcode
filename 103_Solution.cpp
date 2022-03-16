#include <iostream>
using namespace std;
#include <vector>
#include <deque>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        
        queue<TreeNode *> qu;
        qu.push(root);
        bool flag = true;
        
        while(!qu.empty()){
            int curSize = qu.size();
            deque<int> dq;
            
            while(curSize>0){
                TreeNode * node = qu.front();
                qu.pop();
                
                if(flag) dq.push_back(node->val);
                else dq.push_front(node->val);
                    
                if(node->left) qu.push(node->left);
                if(node->right) qu.push(node->right);
                curSize--;
            }
            res.emplace_back(vector<int>{dq.begin(), dq.end()});
            flag = !flag;
        }
        return res;

    }
};

int main(){
    return 0;
}