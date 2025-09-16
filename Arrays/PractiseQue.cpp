#include<bits/stdc++.h>
using namespace std;

void print(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


void Bublesort(int arr[],int n)
{
    for(int i= 0; i<n-1;i++)
    {
        for(int j =0;j<n-i-1;j++){
            if(arr[j]<arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    print(arr,n);
}

void SelectionSort(int arr[],int n){
    for(int i =0; i<n-1;i++)
    {
        int min_idx= i;
        for(int j =i+1;j<n;j++){
            if(arr[min_idx]>arr[j]){
                min_idx=j;
            }
        }
        swap(arr[i],arr[min_idx]);
    }
    print(arr ,n);
}

void InsertionSort(int arr[],int n){
    for(int i =1;i<n;i++){
        int key =arr[i];
        int prev = i-1;
        while(prev>0 && arr[prev]>key){
            swap(arr[prev],arr[prev+1]);
            prev--;
        }
    }
}




int main(){
    int arr[10]= {3, 6, 2, 1, 8, 7, 4, 5, 3, 1};
    int n = sizeof(arr)/sizeof(int);
    Bublesort(arr,n);
    SelectionSort(arr,n);
    InsertionSort(arr,n);
    return 0;
}