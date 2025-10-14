#include<iostream>
using namespace std;

void UpdateBit(int n,int i, int value){
    n = n& ~(1<<i);//clear ith bit

    n= n | (value<<i);//set ith bit to value
    cout << "Result: " << n << endl;
}



int main(){
    cout << "Updating bit in number 5..." << endl;
    UpdateBit(5,1,1);
    
    // Add a pause so you can see the output
    cout << "\nPress Enter to exit...";
    cin.get();
    return 0;
}