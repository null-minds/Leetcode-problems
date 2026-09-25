class Solution {
public:
    int maxDiff(int num) {
        string a = to_string(num);
        string b = a;

        // maximize a : to maximize the diff take one char which is not 9 and replace all its occur to 9
        for(char c : a){
            if(c != '9'){
                char target = c;
                for(char &d : a){
                    if(d == target){
                        d = '9';
                    }
                }
                break;
            }
        }

        // minimize b: if the 1st digit is >1, replace all its occur with 1
        if(b[0] != '1'){
            char target = b[0];
            for(char &c:b){
                if(c == target){
                    c = '1';
                }
            }
        }
        else{
            for(int i=1; i<b.size(); i++){
                if(b[i] != '0' && b[i] != '1'){
                    char target = b[i];
                    for(char &c : b){
                        if(c == target){
                            c = '0';
                        }
                    }
                    break;
                }
            }
        }

        return (stoi(a) - stoi(b));
    }
};