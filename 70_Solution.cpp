#include <iostream>
using namespace std;

class Solution
{
public:
    int res = 0;
    int climbStairs(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        return climbStairs(n - 1) + climbStairs(n - 2);
    }

    int climbStairs2(int n)
    {
        if (n <= 2)
            return n;
        int prev = 2, prev2 = 1, res;
        for (int i = 3; i <= n; i++)
        {
            res = prev + prev2;
            prev2 = prev;
            prev = res;
        }
        return res;
    }

    int memo[46] = {0};
    int climbStairsDP(int n) {
        if(n <= 2)
            return n;
        if(memo[n])
            return memo[n];
        return memo[n] = climbStairs(n - 1) + climbStairs(n - 2);
    }
};

int main()
{
    Solution solution;
    cout << solution.climbStairs2(15) << endl;
    return 0;
}