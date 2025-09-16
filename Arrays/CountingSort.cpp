#include<iostream>
#include<climits>
using namespace std;

void print(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void countingSort(int arr[], int n) {
    // Find max value in the array
    int max = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    
    // Create count array
    int count[max+1] = {0};
    
    // Count occurrences
    for(int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    
    // Fill original array with sorted elements
    int index = 0;
    for(int i = 0; i <= max; i++) {
        while(count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }
}

int main(){ 
    int arr[] = {1,4,1,3,2,4,3,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout << "Original array: ";
    print(arr, n);
    
    countingSort(arr, n);
    
    cout << "Sorted array: ";
    print(arr, n);

    return 0;
}