#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int ptA = 0, ptB = arr.size() - 1;
        int res = -1;

        while (ptA <= ptB) {
            if(arr[ptA + 1] > arr[ptA] && arr[ptB - 1] > arr[ptB]){
                ptA++; //
                ptB--;
            }else{
                if(arr[ptA + 1] < arr[ptA]){
                    res = ptA;
                    return res;
                }
                if(arr[ptB - 1] < arr[ptB]){
                    res = ptB;
                    return res;
                }
            }
        }
        return res;
    }
};

void test(){
    Solution solution;
    vector<int> arr{0,5, 10, 5, 2};
    cout<<solution.peakIndexInMountainArray(arr)<<endl;
}

int main(){
    test();
    return 0;
}