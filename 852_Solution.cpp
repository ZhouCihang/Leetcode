#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int low = 0, high = arr.size()-1;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            
            if(arr[mid] > arr[mid+1] && arr[mid] > arr[mid - 1]) return mid;
            
            if (arr[mid] < arr[mid+1])
                low = mid+1;
            else
                high = mid-1;
        }
        return low;
    }
};

void test()
{
    Solution solution;
    vector<int> arr{0, 5,7,10, 5, 0};
    cout << solution.peakIndexInMountainArray(arr) << endl;
}

int main()
{
    test();
    return 0;
}