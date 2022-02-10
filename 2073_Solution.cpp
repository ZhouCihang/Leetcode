#include <iostream>
using namespace std;
#include <vector>
#include <deque>

class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        int count = 0;

        // while (true)
        // {
        //     for (int i = 0; i < tickets.size(); i++)
        //     {
        //         if(tickets[i] == 0)
        //             continue;
                
        //         tickets[i] = tickets[i] - 1;
        //         count++;

        //         if(tickets[k] == 0)
        //             return count;
        //     }
        // }

        while(tickets[k] != 0){
            for (int i = 0; i < tickets.size(); i++){
                if(tickets[i] == 0)
                    continue;
                
                tickets[i] = tickets[i] - 1;
                count++;
            }
        }
        return count;
    }
};

void test()
{
    Solution s;
    vector<int> tickets{2, 3, 2};

    cout << s.timeRequiredToBuy(tickets, 2) << endl;
}

int main()
{
    test();
    return 0;
}