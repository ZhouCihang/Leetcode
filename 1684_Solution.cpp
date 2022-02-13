#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int res = words.size();
        // bool alpha[26] = {};
        // for (int i = 0; i <allowed.length(); ++i) {
        //     alpha[allowed.at(i) - 'a'] = true;
        // }

        // for(string word : words) {
        //     for(char c : word){
        //         if(!alpha[c - 'a']){
        //             res--;
        //             break;
        //         }
        //     }
        // }
        // return res;

        unordered_map<char, bool> maps;
        for (char c : allowed){
            maps[c] = true;
        }

        for(string word : words){
            for(char c : word){
                if(maps.find(c) == maps.end()){
                    res--;
                    break;
                }
            }
        }
        return res;
    }
};

void test(){
    Solution solution;
    vector<string> words{"ad","bd","aaab","baa","badab"};
    cout<<solution.countConsistentStrings("ab", words)<<endl;
}

int main(){
    test();
    return 0;
}