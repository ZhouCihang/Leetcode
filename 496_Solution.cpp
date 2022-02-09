#include <iostream>
using namespace std;
#include <stack>
#include <vector>
#include <map>

void printVector(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        map<int, int> m1;
        stack<int> st;
        vector<int> res;

        for (int i = 0; i < nums2.size(); i++){
            while(!st.empty() && st.top() < nums2[i]){
                m1[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        while(!st.empty()){
            m1[st.top()] = -1;
            st.pop();
        }

        for(int i = 0; i < nums1.size(); i++){
            res.push_back(m1[nums1[i]]);
        }
        return res;
    }
};

void test()
{
    Solution solution;
    vector<int> num1{4, 1, 2};
    vector<int> num2{1, 3, 4, 2};
    vector<int> res;

    res = solution.nextGreaterElement(num1, num2);
    printVector(res);
}

int main()
{
    test();
    return 0;
}