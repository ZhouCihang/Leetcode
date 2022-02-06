#include <iostream>
using namespace std;
#include <vector>
#include <string>

class Solution
{
public:
    int countMatches(vector<vector<string> > &items, string ruleKey, string ruleValue)
    {
        int result = 0;
        int index = -1;
        if(ruleKey == "type"){
            index = 0;
        }else if(ruleKey == "color"){
            index = 1;
        }else{
            index = 2;
        }

        for (int i = 0; i < items.size(); i++){
            if(items[i][index] == ruleValue){
                result += 1;
            }
        }

        return result;
    }
};

void test()
{
    Solution sol;
    vector<vector<string> > items{{"phone", "blue", "pixel"},
                                  {"computer", "silver", "lenovo"},
                                  {"phone", "gold", "iphone"}};

    cout << sol.countMatches(items, "color", "silver") << endl;
}

int main()
{
    test();
    return 0;
}