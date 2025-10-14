#include<iostream>
#include<string>

using namespace std;

bool areAnagrams(string str1, string str2) {
    if(str1.length() != str2.length()) {
        return false;
    }
    int count[26]={0};
    for(int i=0; i<str1.length(); i++) {
        int idx = str1[i] - 'a';
        count[idx]++;
    }
    for(int i=0; i<str2.length(); i++) {
        int idx = str2[i] - 'a';
        count[idx]--;
        if(count[idx] < 0) {
            return false;
        }
    }
    return true;
}



int main(){
    string str1 = "anagram";
    string str2 = "margana";
    
    if(areAnagrams(str1, str2)){
        cout << "The strings are anagrams." << endl;
    } else {
        cout << "The strings are not anagrams." << endl;
    }
    return 0;
}
