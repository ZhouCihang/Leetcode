#include <iostream>
using namespace std;
#include <vector>
#include <queue>

//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty() || lists.size() == 0)
            return nullptr;

        auto cmp = [&](ListNode *a, ListNode *b)
        {
            return a->val > b->val;
        };

        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> q(cmp);

        for (int i = 0; i < lists.size(); i++)
        {
            if (lists[i])
            {
                q.push(lists[i]);
            }
        }

        ListNode dummyHead(0);
        ListNode *tail = &dummyHead;

        while (!q.empty())
        {
            auto temp = q.top();
            q.pop();
            tail->next = temp;
            tail = tail->next;

            if (temp->next)
            {
                q.push(temp->next);
            }
        }

        tail->next = NULL;
        return dummyHead->next;
    }

    ListNode *mergeKListsRedo(vector<ListNode *> &lists){
        if(lists.empty() || lists.size() == 0) return nullptr;
        
        auto cmp = [&](ListNode *list1, ListNode *list2){
            return list1->val > list2->val;
        };
        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> q(cmp);
        for(int i = 0; i < lists.size(); ++i){
            if(lists[i]){
                q.push(lists[i]);
            }
        }

        ListNode *dummyHead = new ListNode(0);
        ListNode *tail = dummyHead;
        while(!q.empty()){
            auto temp = q.top();
            q.pop();
            tail->next = temp;
            tail = tail->next;
            if(tail->next){
                q.push(temp->next);
            }
        }
        tail->next = nullptr;
        return dummyHead->next;

    }

};

int main()
{
    return 0;
}