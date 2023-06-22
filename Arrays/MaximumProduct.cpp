#include <bits/stdc++.h>

using namespace std;

class Solution
{

public:
    int maxProduct(vector<int> &nums)
    {
        int left_product = 1;
        int right_product = 1;
        int maximum = nums[0];

        for (int i = 0; i < nums.size(); ++i)
        {
            left_product *= nums[i];
            right_product *= nums[i];

            if (left_product == 0)
                left_product = 1;
            if (right_product == 0)
                right_product = 1;

            maximum = max(maximum, max(left_product, right_product));
        }
        return maximum;
    }
};

int main()
{
    vector<int> nums{2, 4, -1, 4};
    cout << Solution().maxProduct(nums);
    return 0;
}