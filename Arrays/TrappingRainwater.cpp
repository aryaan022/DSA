#include<iostream>
using namespace std;


int TrappedWater(int *bars,int n){
    int leftmax[20000],rightmax[20000];
    leftmax[0] = bars[0];
    rightmax[n-1] =bars[n-1];
    for(int i =1; i <n;i++){
        leftmax[i]= max(leftmax[i-1],bars[i-1]);
    }
     for(int i =n-2; i >=0;i--){
        rightmax[i]= max(rightmax[i+1],bars[i+1]);
    }
    int waterTrapped =0;
    for(int i =0; i<n;i++){
        int currentWater = min(leftmax[i],rightmax[i])-bars[i];
        if(currentWater>0){
            waterTrapped += currentWater;
        }

    }
    cout<<"Water Trapped = "<<waterTrapped <<endl;
    return waterTrapped;

}



int main(){
    int bars[] ={4,2,0,6,3,2,5};
    int n = sizeof(bars)/ sizeof(int);
    TrappedWater(bars,n);
    return 0;
 }