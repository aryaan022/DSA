class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n=operations.size();
        stack<int>s;
        for(int i=0;i<n;i++){
            // if(operations[i]!="+" && operations[i]!="D" && operations[i]!= "C"){
            //     s.push(stoi(operations[i]));
            // }
            if(operations[i]=="+"){
                int a=s.top();
                s.pop();
                int b= s.top();
                s.pop();
                int res= a+b;
                s.push(b);
                s.push(a);
                s.push(res);               
            }
            else if(operations[i]=="D"){
                int d=s.top();
                d=d*2;
                s.push(d);
            }
            else if(operations[i]=="C"){
                s.pop();
            }
            else{
                s.push(stoi(operations[i]));
            }
        }
        int sum=0;
        while(!s.empty()){
            sum =sum+s.top();
            s.pop();
        }
        return sum;
        
    }
};