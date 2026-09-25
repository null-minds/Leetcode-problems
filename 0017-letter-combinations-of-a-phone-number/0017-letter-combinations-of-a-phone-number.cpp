class Solution {
private:
    void func(int index, string digits, string combos[],   vector<string> &ans, string s){
        if(index == digits.size()){
            ans.push_back(s);
            return;
        }

        // for getting digits digit = digits[i] - '0', it converts that into a number( ASCII - ASCII = number)
        int num = digits[index] - '0';
        for(int i=0; i<combos[num].size(); i++){
            func(index+1, digits, combos, ans, s + combos[num][i]);
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string s="";
        string combos[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        func(0, digits, combos, ans, s);
        return ans;
    }
};