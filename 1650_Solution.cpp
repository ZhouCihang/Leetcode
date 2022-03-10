#include <iostream>
using namespace std;
#include <vector>

// Definition for a Node.
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *parent;
};

class Solution
{
public:
    Node *lowestCommonAncestor(Node *p, Node *q)
    {
        Node *a = p, *b = q;

        while(a->val != b->val){
            if(a != NULL){
                a = a->parent;
            }else{
                a = q;
            }

            if(b != NULL){
                b = b->parent;
            }else{
                b = p;
            }
        }
        return a;
        
    }
};

int main()
{
    return 0;
}