#include <iostream>
using namespace std;
#include <string>

class Solution
{
public:
    int countSubstrings(string s)
    {
        if (s.length() < 2)
            return 1;

        int count = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            string oddstr = centerExpand(s, i, i);
            cout << "oddstr: "<< oddstr << endl;
            string evenstr = centerExpand(s, i, i + 1);
            cout<<"evenstr: "<<evenstr << endl;
            //count += oddstr.length() > evenstr.length() ? (oddstr.length()+1)/2 : evenstr.length()/2;
            count = count + (oddstr.length()+1)/2 + evenstr.length()/2;
            cout<<"count: "<<count << endl;
        }
        return count;
    }

    string centerExpand(string s, int left, int right)
    {
        while (left >= 0 && right < s.length())
        {
            if (s[left] != s[right])
                break;
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }
};

int main()
{
    Solution s;
    cout << s.countSubstrings("aba") << endl;
    return 0;
}