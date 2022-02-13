#include <iostream>
using namespace std;
#include <unordered_map>
#include <vector>

class Solution {
public:
    int countPoints(string rings) {
        int n = rings.length();
        vector<int> vp(10,0);

        for(int i = 0; i < n; i+=2){
            char col = rings[i];
            int index= rings[i+1] -'0';
            if(col == 'R'){
                vp[index] |= 1;
            }
            if(col == 'G'){
                vp[index] |= 2;
            }
            if(col == 'B'){
                vp[index] |= 4;
            }
        }

        int count = 0;
        for(int i = 0; i < 10; i++){
            if(vp[i] == 7)
                count++;
        }
        return count;
    }
};

void test(){
    Solution solution;
    cout << solution.countPoints("B0B6G0R6R0R6G9") << endl;
}

int main(){
    test();
    return 0;
}