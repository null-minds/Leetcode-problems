class Solution {
    vector<string> ans;
    vector<string> combos = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void func(int index, string &digits, string &s){
        if(index == digits.size()){
            ans.push_back(s);
            return;
        }

        // for getting digits digit = digits[i] - '0', it converts that into a number( ASCII - ASCII = number)
        // int num = digits[index] - '0';
        // for(int i=0; i<combos[num].size(); i++){
        //     func(index+1, digits, combos, ans, s + combos[num][i]);
        // }

        string letters = combos[digits[index] - '0'];

        for (char ch : letters) {
            s.push_back(ch);
            func(index + 1, digits, s);
            s.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        string s="";

        func(0, digits, s);
        return ans;
    }
};