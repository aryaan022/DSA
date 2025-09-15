#include<iostream>
using namespace std;
//BRUTE FORCE APPROACH
//TIME COMPLEXITY : O(N^3)
void maxSubarraySum1(int *arr , int n){
    int maxSum = INT32_MIN;
    for(int start =0 ; start<n; start++){
        for(int end =start; end<n; end++){
            int currSum =0;
            for(int i =start; i<=end;i++)
            {
                currSum += arr[i];
            }
            cout<<currSum<<", ";
            maxSum = max(maxSum , currSum);
        }
        cout<<endl;
    }
    cout<<"maxSum is : "<<maxSum<<endl;

}

//TIME COMPLEXITY : O(N^2)
void maxSubarraySum2(int *arr , int n){
    int maxSum = INT32_MIN;
    for(int start =0 ; start<n; start++){
        int currSum =0;
        for(int end =start; end<n; end++){
            currSum = currSum + arr[end];
            maxSum = max(maxSum , currSum);
        }
    }
    cout<<"maxSumArray is : "<<maxSum<<endl;

}

//TIME COMPLEXITY : O(N)
void maxSubarraySum3(int *arr , int n){
    int maxSum = INT32_MIN;
    int currSum =0;
    for(int i =0; i<n;i++){
        currSum += arr[i];
        maxSum =max(currSum , maxSum);
        if(currSum<0){
            currSum =0;
        }
    }
    cout<<"maximum subarray sum = "<<maxSum<<endl;

}

int main(){
    int arr[6] = {2 , -3, 6 ,-5, 4 ,2};
    int n = sizeof(arr)/sizeof(int);
    maxSubarraySum1(arr , n);
    return 0;
}