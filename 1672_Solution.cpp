#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int maximumWealth(vector<vector<int> > &accounts)
    {
        int res = 0;
        int sum = 0;
        for (int i = 0; i < accounts.size(); i++){
            for (int j = 0; j < accounts[i].size(); j++){
                sum+=accounts[i][j];
                res = max(sum, res);
            }
            sum =0;
        }
        return res;
    }
};

void test()
{
    Solution s;
    vector<vector<int> > accounts{{1, 5},
                                  {7, 3},
                                  {3, 5}};

    cout << s.maximumWealth(accounts) << endl;
}

int main()
{
    test();
    return 0;
}