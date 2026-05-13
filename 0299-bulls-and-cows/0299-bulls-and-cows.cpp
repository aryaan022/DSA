class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls=0;
        int cows=0;
        unordered_map<char,int>m;
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]){
                bulls++;
            }
            else{
                m[secret[i]]++; // sttoring frequence <numbber, freq>
            }
        }

        for(int i=0;i<guess.size();i++){
            if(secret[i]!=guess[i] && m[guess[i]]>0){
                cows++;
                m[guess[i]]--;
            }
        }

        return to_string(bulls)+"A"+to_string(cows)+"B";
        
    }
};