#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

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
    vector<int> findFrequentTreeSum(TreeNode *root)
    {
        vector<int> res;
        unordered_map<int, int> m;
        int max_count = 0;

        findFeqSum(root, m, max_count);
        for(auto &it:m){
            if(it.second == max_count){
                res.push_back(it.first);
            }
        }
        return res;
    }
    int findFeqSum(TreeNode *root, unordered_map<int, int> &m, int &max_count)
    {
        if(root == NULL) return 0;
        int left = findFeqSum(root->left, m, max_count);
        int right = findFeqSum(root->right, m, max_count);
        
        m[root->val + left + right]++;
        max_count = max(max_count, m[root->val + left+ right]);
        return left+right+root->val;
    }
};

int main()
{
    return 0;
}