// Contains Duplicate
// Question Link - https://leetcode.com/problems/contains-duplicate/description/


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

      /* Approch 1 - Brute Force comparing each elemt to check duplicate
          for(let i = 0; i < nums.length; i++) {
              for(let j = i+1; j < nums.length; j++) {
                  if(nums[i] === nums[j]) return true;
              }
          }
          return false;

      Time - O(n^2)
      Space - O(1)
      */

      /* Approch 2 - Sorting
        sort(nums.begin(), nums.end());
        for(int i=1; i<nums.size(); i++){
            if(nums[i] == nums[i-1]){
                return true;
            }
        }
        return false;

        Time - O(nlogn)
        Space - O(1)
      */

      /* Approch 3 - using set
        int n = nums.size();
        set<int> st(nums.begin(), nums.end()); 
        if(n==st.size()){
          return false;
        }
        return true;

        Time - O(n)
        Space - O(n)
      */

      /* using map
      Time - O(n)
      Space - O(n)
      */
        unordered_map<int,int> mpp;
        for( auto i : nums){
            if(mpp[i]++){
                return true;
            }
        }

        return false;
    }
};
