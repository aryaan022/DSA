#include<iostream>
using namespace std;

void fastExpo(int x,int n){
    int ans=1;
    while(n>0){
        int lastdig = n&1;
        if(lastdig == 1){
            ans = ans*x;
        }
        x = x*x;
        n = n>>1;
    }
    cout<<"Answer is :"<<ans<<endl;
}

int main(){
    int x=3;
    int n=5;
    fastExpo(x,n);
    return 0;
}
// Time complexity is O(log n)
// Space complexity is O(1)
//and time complexity of normal expo is O(n) which is more than this. so this is better. 