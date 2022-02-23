#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    vector<int> flipHori(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right){
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
        return nums;
    }
    vector<int> invert(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == 0){
                nums[i] = 1;
            }else{
                nums[i] = 0;
            }
        }
        return nums;
    }

    vector<vector<int> > flipAndInvertImage(vector<vector<int> > &image)
    {  
        vector<vector<int> > result;
        vector<int> temp;
        for(int i = 0; i < image.size(); i++){
            temp = flipHori(image[i]);
            temp = invert(temp);
            result.push_back(temp);
            temp.clear();
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int> > image{{1, 1, 0}, {1, 0, 1}, {0, 0, 0}};
    vector<vector<int> > result;
    result = solution.flipAndInvertImage(image);

    for(int i = 0; i<result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}