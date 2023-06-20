#include<bits/stdc++.h>

using namespace std;

class Solution{
    vector<vector<int>> ThreeSum(vector<vector<int>> nums){
        if(nums.size() < 3){
            return vector<vector<int>> {{-1,-1,-1}};
        }

        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size()-3;++i){

            if(i>0&&nums[i]==nums[i-1]){
                continue;
            }

            int lo = i+1;
            int hi = nums.size()-1;

            while(lo < hi){
                int sum = nums[i]+nums[lo]+nums[hi];
                if(sum == 0){
                    lo++;
                    while(lo<hi&&nums[lo]==nums[lo-1]){
                        lo++;
                    }
                }
                else if(sum < 0){
                    lo++;
                } else{
                    hi--;
                }
            }
        }

    }
}