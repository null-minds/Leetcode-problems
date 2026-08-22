class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();
        int i=0, j=0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while(i < n && j < m){
            if(s[j] >= g[i]){
                i++;
                j++;
            }
            else j++;
        }
        return i;
    }
};