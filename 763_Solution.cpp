#include <iostream>
using namespace std;
#include <string>
#include <vector>

class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        int last[26];
        int length = s.size();
        vector<int> partition;

        for(int i = 0; i < length; i++){
            last[s[i] - 'a'] = i;
        }

        int start = 0, end = 0;
        for(int i = 0; i < length; i++){
            end = max(end, last[s[i] - 'a']);
            cout << "end: " << end <<endl;
            if(i == end){
                partition.push_back(end - start+1);
                start = end + 1;
            }
        }

        return partition;
    }
};

void test()
{
    Solution solution;
    vector<int> labels;
    labels = solution.partitionLabels("ababcbacadefegdehijhklij");
}

int main()
{
    test();
    return 0;
}