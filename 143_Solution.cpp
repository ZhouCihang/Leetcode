#include <iostream>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == nullptr) return;
        
        ListNode* mid = middleNode(head);
        ListNode* l1 = head;
        ListNode* l2 = mid->next;
        mid->next = nullptr;
        
        l2 = reverseList(l2);
    
        //merge linked list
        ListNode* l1_tmp; 
        ListNode* l2_tmp;
        while(l1 != nullptr && l2 != nullptr){
            l1_tmp = l1->next;
            l2_tmp = l2->next;
            
            l1->next = l2;
            l1 = l1_tmp;
            
            l2->next = l1;
            l2 = l2_tmp;
        }
    }
    ListNode* middleNode(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* reverseList(ListNode* head){
        ListNode* prev = nullptr;
        while(head){
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};

int main(){
    return 0;
}