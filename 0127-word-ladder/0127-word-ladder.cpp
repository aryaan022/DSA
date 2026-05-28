class Solution {
public:
    int bfs(string src,string end,vector<string>& wordList){
        queue<string>q;
        unordered_set<string>vis;
        q.push(src);
        vis.insert(src);
        int count = 1;
        
        while(!q.empty()){
            int s= q.size();
            for(int st=0;st<s;st++){
                string curr=q.front();
                q.pop();
                if(curr==end){
                    return count;
                }   
                for(string w:wordList){
                    int diff = 0;
                    for(int i=0;i<curr.size();i++){
                        if(curr[i] != w[i]){
                            diff++;
                        }
                    }
                    if(diff==1 && vis.find(w)==vis.end()){
                        q.push(w);
                        vis.insert(w);
                    }
                }
            }
            count++;
        }
        return 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool found =false;
        for(string w:wordList){
            if(w==endWord){
                found =true;
            }
        }
        if(found==false){
            return 0;
        }
        int ans =bfs(beginWord,endWord,wordList);
        return ans;
    }
};