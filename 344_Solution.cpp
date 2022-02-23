#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int left = 0, right = s.size() - 1;
        while (left <= right){
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};

void test()
{
    Solution s;

    string str = "HelloWorld!";
 
    vector<char> v(str.begin(), str.end());
    //vector<char> s{'h', 'e', 'l', 'l', 'o'};
    s.reverseString(v);
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    test();
    return 0;
}