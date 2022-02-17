#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm> 

class Solution
{
public:
    static bool sortByVal(const pair<int, int> &a, const pair<int, int> &b)
    {
        return (a.second <= b.second);
    }
    vector<int> kWeakestRows(vector<vector<int> > &mat, int k)
    {
        int row = mat.size();
        int col = mat[0].size();
        vector<int> result;
        unordered_map<int, int> maps;

        int count = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (mat[i][j] == 1)
                {
                    count++;
                }
            }
            maps[i] = count;
            cout << count << " " << endl;
            count = 0;
        }

        vector<pair<int, int> > vec;

        unordered_map<int, int>::iterator it2;
        for (it2 = maps.begin(); it2 != maps.end(); it2++)
        {
            vec.push_back(make_pair(it2->first, it2->second));
        }

        sort(vec.begin(), vec.end(), sortByVal);

        for(int i = 0; i < k; i++){
            result.push_back(vec[i].first);
        }
        // for(int i = 0; i < vec.size(); i++){
        //     cout<< vec[i].first << " " << vec[i].second << endl;
        // }

        return result;
    }
};

void test()
{
    vector<vector<int> > mat{{1, 1, 0, 0, 0},
                             {1, 1, 1, 1, 0},
                             {1, 0, 0, 0, 0},
                             {1, 1, 0, 0, 0},
                             {1, 1, 1, 1, 1}};
    vector<int> result;
    Solution solution;
    result = solution.kWeakestRows(mat, 3);
    for(int i = 0; i < result.size(); i++){
        cout<< result[i] << " ";
    }
    cout << endl;
}

int main()
{
    test();
    return 0;
}