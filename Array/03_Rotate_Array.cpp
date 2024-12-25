// Rotate Array
// Question Link - https://leetcode.com/problems/rotate-array/description/


class Solution {
public:
    
    void reverse(int i, int j, vector<int>& nums){
        while(i < j){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j--;
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        k = k % n;
        int m = n-k;
        
        reverse(0, m-1, nums);
        reverse(m, n-1, nums);
        reverse(0, n-1, nums);
        
    }
};
