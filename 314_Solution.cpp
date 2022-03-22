#include <iostream>
using namespace std;
#include <vector>
#include <map>
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

/*
这里可以把根节点给个序号0，然后开始层序遍历，凡是左子节点则序号减1，右子节点序号加1，
这样可以通过序号来把相同列的节点值放到一起，用一个 TreeMap 来建立序号和其对应的节点值的映射，
用 TreeMap 的另一个好处是其自动排序功能可以让列从左到右，由于层序遍历需要用到 queue，
此时 queue 里不能只存节点，而是要存序号和节点组成的 pair 对儿，这样每次取出就可以操作序号，而且排入队中的节点也赋上其正确的序号
*/

class Solution
{
public:
    vector<vector<int> > verticalOrder(TreeNode* root)
    {
        vector<vector<int>> result;
        if(!root) return result;
        map<int, vector<int>> m;
        queue<pair<int, TreeNode*>> q;
        q.push({0, root});
        while(!q.empty()){
            auto a = q.front();
            q.pop();
            m[a.first].push_back(a.second->val);
            if(a.second->left)
                q.push({a.first - 1, a.second->left});
            if(a.second->right)
                q.push({a.first + 1, a.second->right});
        }
        for(auto &a:m){
            result.push_back(a.second);
        }
        return result;
    }
};

int main(){
    return 0;
}