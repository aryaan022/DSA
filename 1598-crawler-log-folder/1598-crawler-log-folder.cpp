class Solution {
public:
    int minOperations(vector<string>& logs) {
        int n = logs.size();
        int c=0;
        stack<string>s;
        for(int i=0;i<n;i++){
            if(logs[i]=="../"){
                if(!s.empty()){
                    s.pop();
                    c--;
                }
            }
            else if(logs[i]!="./"){
                s.push(logs[i]);
                c++;
            }
        }
        return c;
        
    }
};