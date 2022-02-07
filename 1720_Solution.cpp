#include <iostream>
using namespace std;
#include <vector>

void printVector(vector<int> &nums){
    for (int i = 0; i< nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

class Solution
{
public:
    vector<int> decode(vector<int> &encoded, int first)
    {
        vector<int> result;
        result.push_back(first);

        for(int i = 0; i < encoded.size(); i++){
            result.push_back(encoded[i] ^ result[i]);
        }
        return result;
    }
};

void test(){
    Solution solution;
    vector<int> encoded{1,2,3};
    int first = 1;
    vector<int> result;

    result = solution.decode(encoded, first);
    printVector(result);

}

int main()
{
    test();
    return 0;
}