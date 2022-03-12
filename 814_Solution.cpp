#include <iostream>
using namespace std;
#include <vector>

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
    int preorder(TreeNode* &root){
        if(!root) return 0;
        int left = 1;
        int right = 1;
        //根
        if(root->val==0){ //如果发现这个结点是0，看看它的子树
            if(root->left==NULL&&root->right==NULL){ //左右都空
                root = NULL;
                return 0;
            }
            else if(root->left!=NULL&&root->right!=NULL&&root->left->val==0&&root->right->val==0){ //如果左右不空，且都是0
                left = preorder(root->left);
                right = preorder(root->right); //检查到底有没有1
                if(left==0&&right==0){ //左右都没找到
                    root = NULL;
                    return 0;
                }
            }
            else if(root->left!=NULL&&root->right==NULL&&root->left->val==0){//左边不空，右边空，且只有0
                left = preorder(root->left);
                right = 0;
                if(left==0&&right==0){ //左右都没找到
                    root = NULL;
                    return 0;
                }
            }
            else if(root->left==NULL&&root->right!=NULL&&root->right->val==0){//右边不空，左边空，且只有0
                left = 0;
                right = preorder(root->right); //检查到底有没有1
                if(left==0&&right==0){ //左右都没找到
                    root = NULL;
                    return 0;
                }
            }
            //如果有1，不执行后面的删除。
            else{}    
        }
        preorder(root->left); //左
        preorder(root->right); //右
        return 1;
    }
    TreeNode* pruneTree(TreeNode* root) {
        preorder(root);
        return root;
    }
};

int main()
{
    return 0;
}