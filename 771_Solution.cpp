#include <iostream>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count = 0;
        for (int i = 0; i< stones.length(); i++){
            for(int j = 0; j<jewels.length(); j++){
                if(stones[i] == jewels[j]){
                    count++;
                }
            }
        }
        return count;
    }
};

void test(){
    Solution sol;
    int res = sol.numJewelsInStones("aA", "aAAbbbb");
    cout<<res<<endl;
}

int main(){
    test();
    return 0;
}