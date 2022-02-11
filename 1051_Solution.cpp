#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> temp = heights;
        sort(temp.begin(), temp.end());

        int count = 0;
        for(int i = 0; i < temp.size(); i++){
            if(heights[i] != temp[i]){
                count++;
            }
        }
        return count;
    }
};

void test(){
    Solution solution;
    vector<int> heights{1,1,4,2,1,3};

    cout<<solution.heightChecker(heights)<<endl;
}

int main(){
    test();
    return 0;
}