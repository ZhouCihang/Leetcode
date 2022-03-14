#include <iostream>
using namespace std;
#include <vector>

class ArrayReader;

class Solution
{
public:
    int search(const ArrayReader &reader, int target){
        int left = 0, right = 20010, mid;

        while(left < right){
            mid = left + (right - left) / 2;
            int val = reader.get(mid);
            if(val < target){
                left = mid + 1;
            }else if (val == target){
                return mid;
            }else{
                right = mid;
            }
        }
        return -1;
    }
};

int main(){
    return 0;
}