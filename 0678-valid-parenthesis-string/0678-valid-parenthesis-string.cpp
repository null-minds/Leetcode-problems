class Solution {
public:
    bool checkValidString(string s) {
        // both is used to keep the track[of ranges] of opening (, if * found the minOpen is treated as closing and maxOpen is as opening 
        int minOpen = 0, maxOpen = 0;
        for(auto c : s){
            if(c == '('){
                minOpen++;
                maxOpen++;
            }
            else if(c == ')'){
                minOpen--;
                maxOpen--;
            }
            else{
                minOpen--;
                maxOpen++;
            }
            // if maxOpen<0 means closing barckets are more than opening 
            if(maxOpen < 0) return false;
            // if minOpen==-1 then minOpen=0;  ex: '*('
            if(minOpen < 0) minOpen=0;
        }
        return minOpen == 0;
    }
};