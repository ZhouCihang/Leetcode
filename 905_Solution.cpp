#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        int p2 = nums.size() - 1, i = 0;

        //[0, p2)
        //(p2, len-1]

        while(i <= p2){
            cout << nums[i] << endl;
            if((nums[i] % 2 )== 0){
                i++;
            }else{
                swap(nums[i], nums[p2]);
                p2--;
            }
        }
        for(int i = 0; i < nums.size(); i++){
            cout << nums[i] << " ";
        }
        cout << endl;
        return nums;
    }
};

int main()
{
    Solution s;
    vector<int> nums{3, 1, 2, 4, 5};
    vector<int> result;
    result = s.sortArrayByParity(nums);
    return 0;
}