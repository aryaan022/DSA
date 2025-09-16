#include<iostream>
#include<algorithm>
using namespace std;

void print(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[8]={6,3,9,5,2,8,7,4};
    sort(arr,arr+8);

    print(arr,8);
    return 0;
}