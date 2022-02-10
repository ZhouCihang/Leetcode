#include <iostream>
using namespace std;
#include <vector>
#include <deque>

void printVector(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        vector<int> newDeck = deck;
        sort(newDeck.begin(), newDeck.end());

        if(newDeck.size()<= 2){
            return newDeck;
        }
        deque<int> ans;
        ans.push_front(newDeck.back());
        newDeck.pop_back();

        while(!newDeck.empty()){
            int temp = ans.back();
            ans.pop_back();
            ans.push_front(temp);
            ans.push_front(newDeck.back());
            newDeck.pop_back();
        }

        return vector<int>(ans.begin(), ans.end());
    }
};

void test(){
    Solution solution;
    vector<int> deck{17,13,11,2,3,5,7};
    vector<int> res;

    res = solution.deckRevealedIncreasing(deck);
    printVector(res);
}

int main(){
    test();
    return 0;
}