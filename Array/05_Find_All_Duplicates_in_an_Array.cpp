// Find All Duplicates in an Array
// Question Link - https://leetcode.com/problems/find-all-duplicates-in-an-array/description/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {

      /* using sorting
        vector<int> ans;
        sort(nums.begin(), nums.end());
        for(int i=1; i<nums.size(); i++){
            if(nums[i] == nums[i-1]){
                ans.push_back(nums[i]);
            }
        }
        return ans;

        Time - O(nlogn)
        Space - O(1) {as we are excluding the space taken by output array}
      */

        /* Map Approch, Time - O(n) */
        unordered_map<int,int> mpp;

        for(int i : nums){
            mpp[i]++;
        }

        vector<int> vc;

        for(auto i : mpp){
            if(i.second == 2){
                vc.push_back(i.first);
            }
        }

        return vc;
    }
};
