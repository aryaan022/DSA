#include <iostream>
using namespace std;

int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(int);
    int copyArr[n];
    for(int i=0; i<n; i++){
        int j =n-i-1;
        copyArr[j] = arr[i];    
    }
    for(int i=0; i<n; i++){
        arr[i] = copyArr[i];
    }
    
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

}