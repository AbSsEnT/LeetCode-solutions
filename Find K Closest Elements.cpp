class Solution {

    int L, R;
    int middle;
    
    int f, l;
    int q = 0;
    int diff;
    
    vector<int> res;
    
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        if (x < arr[0]) {
            f = 0;
            l = k - 1;
        }
        else if (x > arr[arr.size() - 1]) {
            f = arr.size() - k;
            l = arr.size() - 1;
        }
        else {
            L = 0;
            R = arr.size() - 1;
        
            while(L <= R) {
                middle = (L + R) >> 1;
                
                if (arr[middle] < x)
                    L = middle + 1;
                else
                    R = middle - 1;
            }
            
            if (arr[L] == x) 
                R = L + 1;
            else {
                L = abs(arr[L - 1] - x) < abs(arr[L] - x) ? L - 1 : L;
                R = L + 1;
            }
            
            while(q < k) {
                if (abs(arr[L] - x) <= abs(arr[R] - x)) {
                    f = L;
                    L--;
                }
                else {
                    l = R;
                    R++;
                }
                
                q++;
            }

            if (f < 0) {
                diff = 0 - f;
                f = 0;
                l += diff;
            }
            else if (l > arr.size() - 1) {
                diff = l - (arr.size() - 1);
                f -= diff;
                l = arr.size() - 1;
            }
        }
        
        if (!l) l = f + k - 1;
        
        for (int i = f; i <= l; i++)
            res.push_back(arr[i]);
        
        return res;
    }
};
