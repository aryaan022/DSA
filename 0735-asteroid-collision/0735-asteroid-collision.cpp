class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        stack<int> s;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!s.empty()){
                if(asteroids[i]>0 &&s.top()>0){
                    s.push(asteroids[i]);
                }
                else if(asteroids[i]<0){
                    while(!s.empty()&&s.top()>0 && abs(asteroids[i])>abs(s.top())){
                            s.pop();
                    }
                    if(!s.empty() && s.top() > 0 && abs(asteroids[i]) == abs(s.top())){
                        s.pop();
                    }else if(s.empty() || s.top() < 0) {
                        s.push(asteroids[i]);
                    }
                }
                else{
                    s.push(asteroids[i]);
                }
            }else{
                s.push(asteroids[i]);
            }
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};