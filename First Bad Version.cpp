// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
    int F, L;
    int middle;
    
public:
    int firstBadVersion(int n) {
        F = 1;
        L = n;
        
        if (n == 1)
            return 1;
        
        while(F < L) {
            middle = F + (L - F) / 2;
            
            if (!isBadVersion(middle))
                F = middle + 1;
            else
                L = middle;
        }

        return L;
    }
};
