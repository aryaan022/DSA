#include<bits/stdc++.h>
using namespace std;

void checkPalindrome(char arr[],int n){
    int start=0;
    int end =n-1;
    while(start<end){
        if(arr[start]!=arr[end]){
            cout<<"not a pallindrome";
            return;
        }
        start++;
        end--;
    }
    cout<<"pallindrome";
}

int main(){
    char arr[]=" ";
    checkPalindrome(arr,strlen(arr));
    return 0;
}