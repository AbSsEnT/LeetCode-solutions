class Solution {
    int n;
    int L, R;
    int middle;
    
public:
    int findPeakElement(vector<int>& nums) {
        L = 0;
        R = n = nums.size() - 1;
        
        if (nums.size() == 2)
            return nums[0] > nums[1] ? 0 : 1;
        
        while(L < R) {
            middle = (L + R) / 2;
            
            if (nums[middle] > nums[middle - 1] && nums[middle] < nums[middle + 1])
                L = middle + 1;
            else
                R = middle;                                   
        }
        
        return L;
    }
};
