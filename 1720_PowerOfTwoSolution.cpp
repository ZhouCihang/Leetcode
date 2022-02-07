#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    void isPowerOfTwo(int n)
    {
        if (n > 0)
        {
            while (n % 2 == 0)
            {
                n /= 2;
            }
            if (n == 1)
            {
                cout << "Number is power of 2." << endl;
            }
            if (n == 0 || n != 1)
            {
                cout << "Number is not power of 2." << endl;
            }
        }
    }

    void isPowerOfTwoMethod2(int n)
    {
        if (n != 0 && (n & (n - 1)) == 0)
        {
            cout << "Number is power of 2." << endl;
        }
        else
        {
            cout << "Number is not power of 2." << endl;
        }
    }
};

int main()
{
    //int a = 5, b = 9;
    // cout << "a = " << a << " b = " << b << endl;
    // cout << "a & b =" << (a & b) << endl;
    // cout << "a | b =" << (a | b) << endl;
    // cout << "a ^ b =" << (a ^ b) << endl;
    // cout << "~(" << a << ") = " << (~a) << endl;
    // cout << "b << 1"
    //      << " = " << (b << 1) << endl;
    // cout << "b >> 1 "
    //      << "= " << (b >> 1) << endl;

    int n;
    cout << "Enter a number :";
    cin >> n;

    Solution solution;
    //solution.isPowerOfTwo(n);
    solution.isPowerOfTwoMethod2(n);

    return 0;
}