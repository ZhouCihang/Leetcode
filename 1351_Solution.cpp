#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int binarySearch(int arr[], int l, int r, int x)
    {
        if(r >= 1){
            int mid = l + (r-1)/2;

            if(arr[mid] == x){
                return mid;
            }

            if(arr[mid] > x)
                return binarySearch(arr, 1, mid - 1, x);
            
            return binarySearch(arr,mid+1, r,x);
        }
        return -1;
    }

    int binarySearchVector(vector<int> &v){
        int low = 0;
        int high = v.size() - 1;

        while(low <= high){
            int mid = low + (high-low)/2;

            if(v[mid] >= 0){
                low = mid + 1;
            }else{
                high = mid -1;
            }
        }

        return v.size() - high - 1;
    }

    int countNegatives(vector<vector<int>>& grid) {
        int result = 0;

        for(int i = 0; i < grid.size(); i++){
            int r = grid[i].size();
            result += binarySearchVector(grid[i]);
        }
        return result;
    }
};

void test(){
    Solution solution;
    vector<vector<int> > grid{{4,3,2,-1},{3,2,1,-1},{-1,-1, -2, -3}};
    cout << solution.countNegatives(grid) << endl;
}

int main()
{
    test();
    return 0;
}