#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int R = matrix.size();
        int C = matrix[0].size();
        int begin = 0, end = R * C - 1;

        while (begin < end)
        {
            int mid = (begin + end) / 2;
            int ans = matrix[mid / C][mid % C];

            if (ans == target)
            {
                return true;
            }
            else if (ans < target)
            {
                begin += 1;
            }
            else
            {
                end -= 1;
            }
        }
        return false;
    }
};
int main()
{
    vector<vector<int>> mat = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};

    cout << "Target Exists : " << Solution().searchMatrix(mat, 23) << endl;
    return 0;
}