#include <iostream>
using namespace std;
#include <vector>

void printVector(vector<vector<int> > &vect)
{
    for (int i = 0; i < vect.size(); i++)
    {
        for (int j = 0; j < vect[i].size(); j++)
        {
            cout << vect[i][j] << " ";
        }   
        cout << endl;
    }
}

class Solution
{
public:
    int maxWidthOfVerticalArea(vector<vector<int> > &points)
    {
        int ans = 0;
        sort(points.begin(), points.end());
        //printVector(points);

        for (int i = 1; i < points.size(); i++) 
        {
            ans = max(ans, points[i][0] - points[i - 1][0]);
        }
        return ans;
    }
};

void test()
{
    Solution solution;
    vector<vector<int> > point{{3, 1}, {9, 0}, {1, 0}, {1, 4}, {5, 3}, {8, 8}};

    cout << solution.maxWidthOfVerticalArea(point) << endl;
}

int main()
{
    test();
    return 0;
}