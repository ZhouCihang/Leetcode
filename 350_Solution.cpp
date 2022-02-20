#include <iostream>
using namespace std;
#include <vector>
#include <map>

class Solution {// Using Map & without sort
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>freq;
        vector<int>ans;

        for(int i = 0;i<nums1.size();i++){
            freq[nums1[i]]++;
        }
        for(int i = 0;i<nums2.size();i++){
            if (freq[nums2[i]] > 0){
                freq[nums2[i]]--; 
                ans.push_back(nums2[i]);
            }
        }
        return ans;
    }
};

int main(){
    Solution solution;
    vector<int> nums1{1,2,2,1}, nums2{2,2};
    vector<int> res;

    res = solution.intersect(nums1, nums2);

    for(int i=0;i<res.size();i++){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}