#include <iostream>
using namespace std;
#include <deque>

class Solution
{
public:
    int findTheWinner(int n, int k)
    {
        return f(n,k) + 1;
    }
    int f(int n, int k){
        if(n == 1) return 0;
        return (f(n-1, k) + k) % n;
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