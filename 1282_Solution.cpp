#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

class Solution
{
public:
    vector<vector<int> > groupThePeople(vector<int> &groupSizes)
    {
        unordered_map<int, vector<int> > mp;
        unordered_map<int, vector<int> >::iterator it;

        vector<vector<int> > res;
        vector<int> temp;

        for (int i = 0; i < groupSizes.size(); i++)
        {
            it = mp.find(groupSizes[i]);
            if (it != mp.end())
            {
                (it->second).push_back(i);
            }
            else
            {
                mp[groupSizes[i]].push_back(i);
            }
        }

        int pos = 0, cnt = 0;
        for (it = mp.begin(); it != mp.end(); it++)
        {
            for (int i = 0; i < (it->second).size(); i++)
            {
                int tnum = (it->second)[i];
                temp.push_back(tnum);

                if (temp.size() == (it->first))
                {
                    res.push_back(temp);
                    temp.clear();
                }
            }
        }
        return res;
    }
};

void test()
{
    Solution solution;
    vector<vector<int> > result;
    vector<int> groups{3, 3, 3, 3, 3, 1, 3};
    result = solution.groupThePeople(groups);

    for (int i = 0; i < result.size(); i++)
    {
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j]<< " ";
        }
        cout << endl;
    }
}

int main()
{
    test();
    return 0;
}