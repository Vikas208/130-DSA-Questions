#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int sum = 0;
        int maximum = nums[0];

        for (int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            if (maximum < sum)
            {
                maximum = sum;
            }
            if (sum < 0)
            {
                sum = 0;
            }
        }
        return maximum;
    }

    int maxSubArray(vector<int> &nums, int size)
    {

        if (size == 1)
        {
            return nums[0];
        }

        int m = size / 2;

        int left_max = maxSubArray(nums, m);
        int right_max = maxSubArray(nums, size - m);

        int left_sum = INT_MIN, right_sum = INT_MIN, sum = 0;

        for (int i = m - 1; i >= 0; --i)
        {
            sum += nums[i];
            left_sum = max(left_sum, sum);
        }
        sum = 0;
        for (int i = m; i < size; ++i)
        {
            sum += nums[i];
            right_sum = max(right_sum, sum);
        }

        int cross_max = left_sum + right_sum;
        return max(cross_max, max(left_max, right_max));
    }
};

int main()
{
    // vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

    vector<vector<int>> nums = {
        {-2, 1, -3, 4, -1, 2, 1, -5, 4},
        {1},
        {5, 4, -1, 7, 8}};

    for (int i = 0; i < nums.size(); ++i)
    {

        cout << "Divide And Conquer : " << Solution().maxSubArray(nums[i], nums[i].size())<<endl;
        cout << "Kanade's :" << Solution().maxSubArray(nums[i]) << endl;
    }
}