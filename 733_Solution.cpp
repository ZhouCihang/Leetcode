#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    vector<vector<int> > floodFill(vector<vector<int> > &image, int sr, int sc, int newColor)
    {

        //step1 数据合法检查
        int rows = image.size();
        if (0 == rows)
        {
            return image;
        }
        int cols = image[0].size();

        if (sr >= rows || sc >= cols)
        {
            return image;
        }
        int oldColor = image[sr][sc];
        //step2 递归回溯
        if (oldColor != newColor)
        {
            dfs(image, sr, sc, oldColor, newColor);
        }

        return image;
    }

    void dfs(vector<vector<int> > &image, int i, int j, int oldColor, int newColor)
    {
        //合法性
        if (i < 0 || j < 0 || i >= image.size() || j >= image[0].size())
        {
            return;
        }
        //寻找oldColor相同的颜色
        if (image[i][j] != oldColor)
        {
            return; //
        }

        image[i][j] = newColor; //防止死循环，标记已被访问过。

        dfs(image, i + 1, j, oldColor, newColor);
        dfs(image, i - 1, j, oldColor, newColor);
        dfs(image, i, j + 1, oldColor, newColor);
        dfs(image, i, j - 1, oldColor, newColor);
    }
};

void test()
{
    Solution solution;
    vector<vector<int> > image{{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    vector<vector<int> > result;
    result = solution.floodFill(image, 1, 1, 2);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    test();
    return 0;
}