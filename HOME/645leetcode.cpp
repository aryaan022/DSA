#include<iostream>
using namespace std;


void Leet(int arr[],int n){
    int dup;
    int replace;
    int count =1;
    for(int i =0;i<n;i++){
        if(arr[i]==count){
            count++;
        }
        else{
            dup=arr[i];
            replace=count;
            count++;
        }
    }
    cout<<"["<<dup<<","<<replace<<"]";
}
int main()
{
    int arr[4]={1,2,2,4};
    int n =sizeof(arr)/sizeof(int);
    Leet(arr,4);
    return 0;
}