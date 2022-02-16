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
    bool isPalindrome(ListNode *head)
    {
        if (head == NULL)
            return true;

        ListNode *firstHalfEnd = endOfFirstHalf(head);
        ListNode *secondhalfStart = reverseList(firstHalfEnd->next);

        ListNode *p1 = head;
        ListNode *p2 = secondhalfStart;

        bool result = true;
        while (result && p2 != NULL)
        {
            if (p1->val != p2->val)
            {
                result = false;
            }

            p1 = p1->next;
            p2 = p2->next;
        }
        return result;
    }

    //reverse linkedlist
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = NULL;
        while (head)
        {
            ListNode *nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }
        return prev;
    }

    //check half of the list
    ListNode *endOfFirstHalf(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast->next != NULL && (fast->next)->next != NULL)
        {
            fast = (fast->next)->next;
            slow = slow->next;
        }
        return slow;
    }
};

int main(){
    return 0;
}