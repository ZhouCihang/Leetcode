#include <iostream>
using namespace std;
#include <numeric>

int main(){
    int num;
    cout << "Sum number from 1 to num"<<endl;
    cin >> num;

    int sum = 0;
    for(int i = 1; i <= num; i++){
        sum += i; 
    }
    cout << sum << endl;


    int sum2 = 0;
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    cout<<accumulate(a, a+10, sum2) << endl;
    return 0;
}