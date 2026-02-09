class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string temp ="";

        for(int i=0;i<=path.size();i++){
            if(i==path.size()||path[i]=='/'){
                if(temp=="" || temp=="."){
                //do nothing
            }
            else if(temp==".."){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(temp);
            }
            temp="";
            }
            
            else{
             temp =temp+path[i];
            }
        }

        vector<string> dir;
        while(!st.empty()){
            dir.push_back(st.top());
            st.pop();
        }
        reverse(dir.begin(),dir.end());
        string res="/";

        for(int i=0; i<dir.size();i++){
            res=res+dir[i];
            if(i!=dir.size()-1){
                res=res+"/";
            }
        }
        return res;
    }
};