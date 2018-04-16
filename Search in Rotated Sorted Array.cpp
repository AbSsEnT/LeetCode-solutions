class Solution {
    int L;
    int R;
    int mid;
    
public:
    int search(vector<int>& nums, int target) {
        L = 0;
        R = nums.size() - 1;
    
        while(L <= R) {
            mid = (L + R) >> 1;
        
            if (nums[mid] == target)
                return mid;
        
            if (nums[mid] > nums[R]) {
                if (target < nums[mid] && target >= nums[L])
                    R = mid - 1;
                else
                    L = mid + 1;
            }
            else if (nums[mid] < nums[L])
                if (target > nums[mid] && target <= nums[R])
                    L = mid + 1;
                else
                    R = mid - 1;
            else {
                if (target < nums[mid])
                    R = mid - 1;
                else
                    L = mid + 1;
            }
        }
        
    return -1; 
    }
};
