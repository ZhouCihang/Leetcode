#include <iostream>
using namespace std;
#include <unordered_map>


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return {};
        
        Node* chead = head;
        Node* preNode = new Node(head->val);
        Node* rHead = preNode;
        unordered_map<Node*, Node*> originalCopy({{nullptr, nullptr},{head, preNode}});
        
        while(head->next){
            Node* nextNode = new Node(head->next->val);
            preNode->next = nextNode;
            head = head->next;
            preNode = nextNode;
            originalCopy[head] = preNode;
        }
        
        while(chead){
            originalCopy[chead]->random = originalCopy[chead->random];
            chead = chead->next;
        }
        return rHead;
    }
};

int main(){
    return 0;
}