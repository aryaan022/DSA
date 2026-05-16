class Node{
public:
    unordered_map<char,Node*>children;
    bool EndOfWord;
    Node(){
        EndOfWord =false;
    }
};

class trie{
public:
    Node* root;
    trie(){
        root=new Node();
    }
    void insert(string word) {
        Node* temp=root;
        for(int i =0;i<word.size();i++){
            if(temp->children[word[i]]==0){
                temp->children[word[i]]=new Node;
            }
            temp=temp->children[word[i]];
        }
        temp->EndOfWord=true;
    }
    string Search(string word){
        Node* temp=root;
        string  t="";
        for(int i=0;i<word.size();i++){
            if(temp->children.count(word[i])){
                t=t+word[i];
                temp=temp->children[word[i]];
                if(temp->EndOfWord==true){
                    break;
                }
            }
            else{
                    return "";
            }
        }
        if(temp->EndOfWord){
            return t;
        }
        return t="";
    }
};


class Solution {
public:
    trie t;
    string replaceWords(vector<string>& dictionary, string sentence) {
        string ans="";
        //step 1 dict[] trie build

        for(auto it:dictionary){
            t.insert(it);
        }

        //step 2 extract each word form the sentence and check weathe rexist in trie if yes then replace the word with ans with thte dict word;

            string tempword="";
        for(int i=0;i<sentence.size();i++){
            if(sentence[i]!=' '){
                tempword=tempword+sentence[i];
            }
            else{
                string wo=t.Search(tempword);
                
                if(wo==""){
                    ans=ans+tempword;
                }
                else{
                    ans=ans+wo;
                }
                ans=ans+' ';
                tempword="";
            }
        }
        //last word
        string wo =t.Search(tempword);
        if(wo=="") {
            ans=ans+tempword;
        }
        else {
            ans=ans+wo;
        }
        return ans;
    }
};