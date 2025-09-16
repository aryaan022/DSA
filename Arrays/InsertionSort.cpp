#include<iostream>
using namespace std;
void print(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void insertionSort(int arr[],int n){
    int current;
    for(int i =1;i<n;i++){
        current = arr[i];
        int previous = i-1;
        while(previous>=0 && arr[previous]>current){
            swap(arr[previous],arr[previous+1]);
            previous--;
        }
    }
    print(arr,n);
}



int main(){
    int arr[5] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr,n);
    return 0;
}