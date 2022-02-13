#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

class Solution
{
public:
    int uniqueMorseRepresentations(vector<string> &words)
    {
        unordered_map<char, string> maps;
        vector<string> code { ".-", "-...", "-.-.", "-..",
                              ".", "..-.", "--.", "....", "..", ".---", "-.-",
                              ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
                              "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };

        for(char i = 'a'; i <= 'z'; i++){
            maps[i] = code[i-'a'];
        }

        vector<string> res;
        for(string word : words){
            string temp = "";
            for(char c: word){
                temp+=maps[c];
            }
            cout <<temp << endl;
            res.push_back(temp);
        }


        unordered_map<string, int> finalMaps;
        int result = res.size();
        for(string re : res){
            finalMaps[re] = 1;
        }

        return finalMaps.size();
    }
};

void test()
{
    Solution solution;
    vector<string> words{"rwjje","aittjje","auyyn","lqtktn","lmjwn"};
    cout << solution.uniqueMorseRepresentations(words) << endl;
}

int main()
{
    test();
    return 0;
}