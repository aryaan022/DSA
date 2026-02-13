class Solution {
public:
    int calculate(string s) {
        long long sum=0;
        int sign=1;
        stack<long> stk;
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                long long num=0;
                while(i<s.size()&&isdigit(s[i])){
                    num= num*10+s[i]-'0';
                    i++;
                }
                i--;
                sum =sum+sign*num;
                sign=1;
            }
            else if(s[i]=='-'){
                sign=-1;
            }
            else if(s[i]=='('){
                stk.push(sum);
                stk.push(sign);
                sum=0;
                sign=1;
            }
            else if(s[i]==')'){
                int ps=stk.top();
                stk.pop();
                int pans=stk.top();
                stk.pop();
                sum=ps*sum+pans;
            }
        }   
        return (int)sum;     
    }
};