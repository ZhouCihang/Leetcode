#include <iostream>
using namespace std;
#include <vector>
#include <cmath>

float calculateDist(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.0);
}

void printVector(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

class Solution
{
public:
    vector<int> countPoints(vector<vector<int> > &points, vector<vector<int> > &queries)
    {
        vector<int> result;
        for (int i = 0; i < queries.size(); i++)
        {
            int count = 0;
            for (int j = 0; j < points.size(); j++)
            {
                float dist = calculateDist(queries[i][0], queries[i][1], points[j][0], points[j][1]);
                if(dist <= queries[i][2]){
                    count++;
                }
            }
            result.push_back(count);
        }
        return result;
    }
};



void test()
{
    Solution sol;
    vector<vector<int> > points{{1, 3}, {3, 3}, {5, 3}, {2, 2}};
    vector<vector<int> > queries{{2, 3, 1}, {4, 3, 1}, {1, 1, 2}};

    vector<int> result;
    result = sol.countPoints(points, queries);
    printVector(result);
}

int main()
{
    test();
    return 0;
}