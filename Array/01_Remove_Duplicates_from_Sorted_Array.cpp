// Remove Duplicates from Sorted Array
// Question Link - https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 1, k = 1;
        
        while(j < nums.size()){
            
            if(nums[i] == nums[j]){
                j++;
            }
            else{
                k++;
                i++;
                nums[i] = nums[j];
                j++;
            }
        }
        
        return k;
    }
};
