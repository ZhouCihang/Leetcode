#include <iostream>
using namespace std;
#include <vector>
#include <stack>

class StockSpanner
{

    vector<int> span;
    //vector<int> span = prices;
    stack<int> s;
    int i = 0;

public:
    StockSpanner()
    {
    }

    int next(int price)
    {
        span.push_back(price);

        int res;
        while(!s.empty() && price > span[s.top()]){
            res = i - s.top();
            s.pop();
        }

        if(s.empty()){
            res = i + 1;
        }else{
            res = i - s.top();
        }

        s.push(i++);
        return res;
    }
};

int main()
{
    StockSpanner stockSpanner = StockSpanner();
    cout << stockSpanner.next(100) << endl; // return 1
    cout << stockSpanner.next(80) << endl;  // return 1
    cout << stockSpanner.next(60) << endl;  // return 1
    cout << stockSpanner.next(70) << endl;  // return 1
    cout << stockSpanner.next(60) << endl;  // return 1
    cout << stockSpanner.next(75) << endl;  // return 1
    cout << stockSpanner.next(85) << endl;  // return 1

    return 0;
}