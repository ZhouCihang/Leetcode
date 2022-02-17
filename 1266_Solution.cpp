#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:

    int countStep(vector<int>&ptA, vector<int>&ptB){
        int vert = abs(ptB[0] - ptA[0]);
        int hori = abs(ptB[1] - ptA[1]);

        int extra = abs(vert - hori);

        return extra + min(vert, hori);
    }

    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        vector<int> pointA, pointB;
        int result = 0;

        for(int i = 0; i < points.size()-1;i++){
            result += countStep(points[i], points[i+1]);
        }
        return result;
        
    }
};

void test(){
    Solution s;
    vector<vector<int> > points{{1,1},{3,4},{-1,0}};
    cout << s.minTimeToVisitAllPoints(points)<<endl;
}

int main(){
    test();
    return 0;
}