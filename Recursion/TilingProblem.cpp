#include<iostream>
using namespace std;

int tp(int n){ //2*n
    if(n==0 || n==1 ){
        return 1;
    }
    //vertical
    int ans1 =tp(n-1); //2*n-1;
    //horizontal
    int ans2=tp(n-2); // 2xn-2;

    return ans1+ans2; //total number of ways
}

int main(){
    int n=3;
    cout<<tp(3);
    cout<<endl;
    return 0;
}