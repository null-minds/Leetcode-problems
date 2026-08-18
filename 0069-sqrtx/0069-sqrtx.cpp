class Solution {
public:
    int mySqrt(int n) {
        int ans = 0;
        int low = 1, high = n;
        while(low<=high){
            int mid = low + (high - low)/2;
            long long val = 1LL * mid * mid;
            if(val <= (long long)n){
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;;
        }
        return ans;
    }
};