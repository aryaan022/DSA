#include<iostream>
#include<vector>
using namespace std;

int searh(int arr[],int si,int ei,int tar){
    if(si>ei){
        return -1;
    }
    int mid = si+(ei-si)/2;

    if(arr[mid]==tar){
        return mid;
    }

    if(arr[si]<=arr[mid]){//line 1 case
        if(arr[si]<=tar && tar<=arr[mid]){
            //left
            return searh(arr,si,mid-1,tar);
        }
        else{
            return searh(arr,mid+1,ei,tar);
        }
    }else{
        if(arr[mid]<= tar && tar<=arr[ei]){
            return searh(arr,si,mid-1,tar);
        }
        else{
            return searh(arr,mid+1,ei,tar);
        }
    }

}
int main(){
    int arr[7] = {4,5,6,7,0,1,2};
    int n =7;
    cout<<"idx: "<<searh(arr,0,n-1,0);
    return 0;
}