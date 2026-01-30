class Solution {
public:
    bool isValid(string s) {
        stack<char>str;

        for(int i =0;i<s.size();i++){
            char ch = s[i];
            if(ch=='(' || ch=='[' || ch=='{'){
                str.push(ch);
            }
            else{
                if(str.empty()){
                    return false;
                }
                int top =str.top();
                if(ch==')' && top=='('){
                    str.pop();
                }
                else if(ch=='}' && top=='{'){
                    str.pop();
                }
                else if(ch==']' && top=='['){
                    str.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(str.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};