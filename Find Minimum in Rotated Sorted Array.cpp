class Solution {
    int min;
    int L, R;
    int middle;
    
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        
        L = 0;
        R = nums.size() - 1;
        min = nums[0];
        
        while(L <= R) {
            middle = (L + R) / 2;
            
            if (nums[middle] < nums[middle - 1] && nums[middle] < nums[middle + 1])
                return nums[middle];
            
            if (nums[middle] < nums[L]) {
                R = middle;
            }
            else {
                if (nums[L] < min) min = nums[L];
                L = middle + 1;
            }
        }    
        
        return min;
    }
};
