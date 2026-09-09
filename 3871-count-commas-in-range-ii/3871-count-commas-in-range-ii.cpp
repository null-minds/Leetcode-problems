class Solution {
public:
    long long countCommas(long long n) {
        long long comma = 0;
        // Every number >= 1,000 gets at least one comma.
        // Every number >= 1,000,000 gets a second comma.
        // Every number >= 1,000,000,000 gets a third comma.
        // after every iteration base will be changed in the form of base=10^3n : n>=1;
        for(long long base=1000; base<=n; base*=1000){
            comma+= (n - base + 1);
        }
        return comma;
    }
};