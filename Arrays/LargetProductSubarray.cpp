#include <iostream>
using namespace std;
int findMaxProductSubarray(int *arr , int n){
    int maxProduct = 0;
    for(int start =0 ; start<n; start++){
        for(int end =start; end<n; end++){
            int currProduct =1;
            for(int i =start; i<=end;i++)
            {
                currProduct = currProduct * arr[i];
            }
            maxProduct = max(maxProduct , currProduct);
        }
    }
    return maxProduct;
}
int main(){
    int arr[] = {-2,0,-1};
    int n=3;
    cout<<"maximum product subarray = "<<findMaxProductSubarray(arr,n)<<endl;
    return 0;
}//time complexity for this is n^3;