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
    ListNode *swapNodesMethod2(ListNode *head, int k)
    {
        ListNode *A = head, *B = head, *nodeK;
        for (int i = 1; i < k; i++)
            A = A->next;

        nodeK = A;
        A = A->next;

        while (A)
        {
            A = A->next;
            B = B->next;
        }

        int temp = nodeK->val;
        nodeK->val = B->val;
        B->val = temp;

        return head;
    }
    ListNode *swapNodes(ListNode *head, int k)
    {
        ListNode *temp = head;
        ListNode *tempRev = head;

        int count = 1, count2 = 1;

        while (temp->next != NULL)
        {
            if (count == k)
                break;

            temp = temp->next;
            count++;
        }

        ListNode *rev = reverseList(tempRev);
        while (rev->next != NULL)
        {
            if (count2 == k)
                break;

            rev = rev->next;
            count2++;
        }

        swap(temp->val, rev->val);

        return head;
    }

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

    void swapping(ListNode **headPtr, int a, int b)
    {
        if (a == b || !headPtr || !(*headPtr))
            return;

        ListNode *curr = *headPtr;
        ListNode *prev = NULL;
        ListNode *nodeA = NULL;
        ListNode *nodeB = NULL;
        ListNode *prevA = NULL;
        ListNode *prevB = NULL;

        while (curr)
        {
            if (curr->val == a)
            {
                nodeA = curr;
                prevA = prev;
            }
            else if (curr->val == b)
            {
                nodeB = curr;
                prevB = prev;
            }
            prev = curr;
            curr = curr->next;
        }

        if (!nodeA || !nodeB)
            return;

        if (prevA)
        {
            prevA->next = nodeB;
        }
        else
        {
            *headPtr = nodeB;
        }

        if (prevB)
        {
            prevB->next = nodeA;
        }
        else
        {
            *headPtr = nodeA;
        }

        ListNode *tmp = nodeA->next;
        nodeA->next = nodeB->next;
        nodeB->next = tmp;
    }
};