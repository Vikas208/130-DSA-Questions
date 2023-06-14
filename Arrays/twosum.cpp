#include<vector>
#include<unordered_map>

using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if(nums.size() == 0) {
            return vector<int> {-1,-1};
        }
        vector<int> positions;
        unordered_map<int,int> hashMap;
        
        for(int i=0;i<nums.size();i++){
            if(hashMap.find(target - nums[i]) != hashMap.end()){
                positions.push_back(hashMap[target-nums[i]]);
                positions.push_back(i);
                return positions;
            }  
            hashMap[nums[i]] = i;
        }

        return vector<int> {-1,-1};
    }
};