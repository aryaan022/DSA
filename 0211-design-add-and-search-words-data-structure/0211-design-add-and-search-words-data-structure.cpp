class Node{
    public:
    unordered_map<char,Node*>children;
    bool EndOfWord;
    Node(){
        EndOfWord=false;
    }

};

class WordDictionary {
    Node* root;
public:
    WordDictionary() {
        root=new Node();
    }
    
    void addWord(string word) {
        Node* temp =root;
        for(int i=0;i<word.size();i++){
            if(temp->children[word[i]]==0){
                temp->children[word[i]]=new Node;
            }
            temp=temp->children[word[i]];
        }
        temp->EndOfWord=true;
    }
    bool helper(string word,int index,Node* temp){
        if(index==word.size()){
            return temp->EndOfWord;
        }
        char ch=word[index];
        if(ch!='.'){
            if(temp->children.count(ch)==0){
                return false;
            }
            return helper(word,index+1,temp->children[ch]);
        }

        for(auto it:temp->children){
            if(helper(word,index+1,it.second)){
                return true;
            }
        }
        return false;
    }
    bool search(string word) {
        return helper(word,0,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */