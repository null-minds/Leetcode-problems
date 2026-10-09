class Solution {
public:
    int minInsertions(string s) {
        int res = 0, t = 0;
        for(char c: s) {
            if(c == '(') {
                if(t % 2) res++,t++;
                else t+= 2;
            }
            else if(t == 0) res++, t = 1;
            else t--;
        }
        return res + t;
    }
};