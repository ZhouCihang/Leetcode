#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int size = nums1.size();
        for(int i = 0; i < nums2.size(); i++){
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(), nums1.end());
        for(int i = 0; i < nums1.size(); i++){
            cout<<nums1[i]<< " ";
        }
        cout<<endl;
        size = nums1.size();
        cout<<size<<endl;

        if(size % 2 == 0){
            cout<<nums1[(size-1)/2] << " "<<nums1[size/2]<<endl;
            return (double)(nums1[(size-1)/2] + nums1[size/2]) / 2.0;
        }else{
            return double(nums1[size/2]);
        }
    }
};

int main(){
    vector<int> nums1{1,2,3};
    vector<int> nums2{3};
    Solution solution;
    cout << solution.findMedianSortedArrays(nums1, nums2);
    
    return 0;
}