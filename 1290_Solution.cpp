#include <iostream>
using namespace std;

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
    int getDecimalValue(ListNode *head)
    {
        string num;
        
        while (head != NULL)
        {
            cout <<head->val <<endl;
            num += to_string(head->val);
            cout <<"testing" << num << endl;
            head = head->next;
        }
        cout <<"testing1"<<endl;
        int res = 0, pv = 1;
        for (int i = num.size() - 1; i >= 0; i--)
        {
            res += pv * (stoi(num.substr(i, 1)));
            pv *= 2;
        }
        return res;
    }
};

int main()
{
    Solution s;
        /* Start with the empty list */
    //struct ListNode *head = NULL;
    struct ListNode head = ListNode(1);
    head = ListNode(0, head.next);
    head = ListNode(1, head.next);


    
    cout <<s.getDecimalValue(&head)<< endl;

    return 0;
}