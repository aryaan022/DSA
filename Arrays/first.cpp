#include <iostream>
using namespace std;


void printArr(int nums[] , int n){
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    cout<<n<<endl; // it will print 5 because n is passed as argument.
}


int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(int);
    cout<<sizeof(arr)/sizeof(int)<<endl; // it will print 5 because arr is array.
    printArr(arr, n); // n is passed as argument.becuase array decay into pointer when passed as argument.
    return 0;
}


