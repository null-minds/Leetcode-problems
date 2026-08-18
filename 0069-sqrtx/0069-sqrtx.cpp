class Solution {
public:
    int mySqrt(int n) {
        int ans = 0;
        for (int i=1; i<=n; i++){
            long long val = 1LL*i*i;
            if(val <= (long long)n){
                ans = i;
            }
            else break;
        } 
        return ans;
    }
};