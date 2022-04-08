#include <iostream>
using namespace std;
#include <vector>
#include <string>

class Solution
{
public:
    vector<vector<string> > searchSuggestion(vector<string> &repository, string customerQuery)
    {
        vector<vector<string> > returnValue;
        sort(repository.begin(), repository.end());
        for(int i = 2; i <= customerQuery.length(); ++i){
            string tempQuery = customerQuery.substr(0, i);
            vector<string> singlePassResult;
            for(auto& word:repository){
                if(word.find(tempQuery)!= word.npos && singlePassResult.size()<3){
                    singlePassResult.push_back(word);
                }
            }
            returnValue.push_back(singlePassResult);
        }
        return returnValue;
    }
};

int main()
{
    Solution solution;
    vector<string> repository{"mobile", "mouse", "moneypot", "monitor", "mousepad"};
    vector<vector<string> > result;
    result = solution.searchSuggestion(repository, "mouse");

    for(int i = 0; i < result.size(); ++i){
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}