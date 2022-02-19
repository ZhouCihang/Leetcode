#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    void printVector(vector<int> &v)
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }

    int kthSmallestBruteForce(vector<vector<int> > &mat, int k)
    {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<int> res(mat[0]);
        printVector(res);

        for (int i = 1; i < rows; i++)
        {
            vector<int> curr;
            for (int a : res)
            {
                for (int b : mat[i])
                {
                    cout << "a: " << a << " b: " << b << endl;
                    curr.push_back(a + b);
                }
                cout << endl;
            }

            sort(curr.begin(), curr.end());
            printVector(curr);
            cout << "resting" << endl;

            int offset = min(k, int(curr.size()));
            cout << "offset : " << offset << endl;

            res.assign(curr.begin(), curr.begin() + offset);
            printVector(res);
        }

        return res.back();
    }

    vector<vector<int> > temp;
    int m, n;

    int kthSmallestBinarySearch(vector<vector<int> > &mat, int k)
    {
        temp = mat;
        m = mat.size(), n = mat[0].size();
        int left = 0, right = 0;
        for (int i = 0; i < m; i++){
            left += mat[i][0];
            right += mat[i].back();
            cout << "left: "<< left <<endl;
            cout << "right: "<< right <<endl;
        }

        int init = left;
        while (left < right)
        {
            int mid = (left + right) >> 1;
            int num = 1;
            dfs(mid, 0, init, num, k);
            if (num >= k)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
    void dfs(int mid, int index, int sum, int &num, int k)
    {
        if (sum > mid || index == m || num > k)
            return;
        dfs(mid, index + 1, sum, num, k);
        for (int i = 1; i < n; i++)
        {
            if (sum + temp[index][i] - temp[index][0] <= mid)
            {
                num++;
                dfs(mid, index + 1, sum + temp[index][i] - temp[index][0], num, k);
            }
            else
            {
                break;
            }
        }
    }
};

void test()
{
    Solution solution;
    vector<vector<int> > mat{{1, 10, 10}, {1, 4, 5}, {2, 3, 6}};
    cout << solution.kthSmallestBinarySearch(mat, 7) << endl;
}

int main()
{
    test();
    return 0;
}