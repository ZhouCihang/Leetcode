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

        //method 1
        // while (q1.size() != 1)
        // {  
        //     for(int i = 0; i< k-1; i++){
        //         int x = q1.front();
        //         q1.pop_front();
        //         q1.push_back(x);
        //     }
        //     q1.pop_front();
        // }
        // return q1.front();

        //method 2
        int idx = 0;
        while(q1.size() > 1){
            int pos =( idx + k -1 ) % q1.size(); 
            q1.erase(q1.begin() + pos);
            idx = pos;
            if(idx >= q1.size()){
                idx -= q1.size();
            }
        }
        return q1[0];
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