#include <iostream>
using namespace std;
#include <deque>

class Solution
{
public:
    int findTheWinner(int n, int k)
    {
        deque<int> q1;
        for (int i = 1; i <= n; i++)
        {
            q1.push_back(i);
        }

        while (q1.size() != 1)
        {  
            for(int i = 0; i< k-1; i++){
                int x = q1.front();
                q1.pop_front();
                q1.push_back(x);
            }
            q1.pop_front();
        }
        return q1.front();
    }
};

void test()
{
    Solution solution;
    cout << solution.findTheWinner(5, 2);
}

int main()
{
    test();
    return 0;
}