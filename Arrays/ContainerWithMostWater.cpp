#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    /**
     * tow pointer
     * lower pointer with swifted
     * on every stage we gonna store the maximum value
     */
    int maxArea(vector<int> &height)
    {
        int start = 0;
        int end = height.size() - 1;
        int maximum = 0;
        while (start < end)
        {
            int mul = height[height[start] < height[end] ? start : end] * ((end + 1) - start - 1);
            maximum = max(mul, maximum);
            if (height[start] < height[end])
            {
                start++;
            }
            else if (height[start] > height[end])
            {
                end--;
            }
            else
            {

                start++;
                end--;
            }
        }
        return maximum;
    }
};

int main()
{   
    vector<int> heights = {1,2,3,4,5,6,7,8,0,10};
    cout<<Solution().maxArea(heights);
    return 0;
}