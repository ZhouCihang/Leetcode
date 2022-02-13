#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

class Solution
{
public:
    int countKDifference(vector<int> &nums, int k)
    {
        unordered_map<int, int> map;
        int count = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            cout<<"testing"<<i<<endl;
            if (map[nums[i] + k])
            {
                count += map[nums[i] + k];
                cout<<" + : "<<map[nums[i] + k]<< endl;
            }
            if(map[nums[i] - k]){
                count += map[nums[i] - k];
                cout<<" - : "<<map[nums[i] - k]<< endl;
            }
            cout <<"before map ++ : "<<map[nums[i]]<< endl;
            map[nums[i]]++;
            cout <<"map ++ : "<<map[nums[i]]<< endl;
        }
        return count;
    }
};

void test()
{
    Solution solution;
    vector<int> nums{3,2,1,5,4};
    cout << solution.countKDifference(nums, 2) << endl;
}

int main()
{
    test();
    return 0;
}