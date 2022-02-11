#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int minMovesToSeat(vector<int> &seats, vector<int> &students)
    {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        int steps = 0;
        for (int i = 0; i < students.size();i++){
            steps += abs(students[i] - seats[i]);
        }
        return steps;
    }
};

void test()
{
    Solution solution;
    vector<int> students{4, 1, 5, 9};
    vector<int> seats{1, 3, 2, 6};

    cout << solution.minMovesToSeat(seats, students) << endl;
}

int main()
{
    test();
    return 0;
}