// Single Number
// Question Link - https://leetcode.com/problems/single-number/description/


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        /* using map
        unordered_map<int, int> mpp;
        for(int i : nums){
            mpp[i]++;
        }
        for(auto i : mpp){
            if(i.second == 1){
                return i.first;
            }
        }
        return -1;
        */
        
        
        /* using sorting 
        sort(nums.begin(), nums.end());
        for(int i=1; i<nums.size(); i+=2){
            if(nums[i] != nums[i-1]){
                return nums[i-1];
            }
        }
        return nums[nums.size()-1];
        */
        
        
        /* using set and sum
        set<int> st(nums.begin(), nums.end());
        int sum1 = 0, sum2 = 0;
        for(int i : st){
            sum1 += i;
        }
        for(int i : nums){
            sum2 += i;
        }
        return(sum1*2 - sum2);
        */
        
        
        /* using xor */
        int ans = 0;
        for(int i : nums){
            ans ^= i;
        }
        return ans;
        
        
    }
};
