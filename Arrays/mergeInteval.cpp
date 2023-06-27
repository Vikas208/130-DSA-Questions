#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> mergeInterval(vector<vector<int>> &nums)
    {
        sort(nums.begin(), nums.end());

        vector<vector<int>> mergeArray;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (mergeArray.empty() || mergeArray.back()[1] < nums[i][0])
            {
                mergeArray.push_back(nums[i]);
            }
            else
            {
                mergeArray.back()[1] = max(mergeArray.back()[1], nums[i][1]);
            }
        }
        return mergeArray;
    }
};

int main()
{
    vector<vector<int>> array = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> ans = Solution().mergeInterval(array);
    cout << "[";
    for (auto arr : ans)
    {
        cout << "[";
        for (auto _k : arr)
        {
            cout << _k << ",";
        }
        cout << "]"
             << ",";
    }
    cout << "]";
    return 0;
}