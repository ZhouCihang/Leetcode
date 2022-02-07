#include <iostream>
using namespace std;
#include <vector>

void printVector(vector<vector<int> > &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums[i].size(); j++)
        {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
}

class SubrectangleQueries
{

    vector<vector<int> > rec;
    vector<vector<int> > updates;
    vector<int> v;

public:
    SubrectangleQueries(vector<vector<int> > &rectangle)
    {
        printVector(rectangle);
        vals = &rectangle;
    }

    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue)
    {
        for(int i = row1; i <= row2; ++i) {
            for(int j = col1; j <= col2; ++j) {
                (*vals)[i][j] = newValue;
            }
        }
    }

    int getValue(int row, int col)
    {
        cout<<"get value: "<<(*vals)[row][col]<<endl;
        return (*vals)[row][col];
    }

private:
    vector<vector<int> > *vals;
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */

int main()
{
    vector<vector<int> > rectangle{{1, 2, 1}, {4, 3, 4}, {3, 2, 1}, {1, 1, 1}};
    // SubrectangleQueries obj = SubrectangleQueries(rectangle);

    SubrectangleQueries subrectangleQueries = SubrectangleQueries(rectangle);
    subrectangleQueries.getValue(0, 2);
    subrectangleQueries.updateSubrectangle(0, 0, 3, 2, 5);
    printVector(rectangle);
    subrectangleQueries.getValue(0, 2);
    subrectangleQueries.getValue(3, 1);
    subrectangleQueries.updateSubrectangle(3, 0, 3, 2, 10);
    printVector(rectangle);
    subrectangleQueries.getValue(3, 1); // return 10
    subrectangleQueries.getValue(0, 2); // return 5
    return 0;
}