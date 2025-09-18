#include<iostream>
using namespace std;

bool search(int mat[][4],int n,int m,int key=32){
    int i=0,j=m-1;
    while(i<n && j>=0){
        if(mat[i][j]==key){
            cout<<"found at cell ("<<i<<","<<j<<")\n";
            return true;
        }else if(mat[i][j]>key){
            //down
            j--;
        }
        else{
            //left
            i++;
        }
    }
    cout<<"Key not found";
    return false;

}

int main(){
    int matrix[4][4] = {{10,20,30,40},{15,25,35,45},{27,29,37,48},{32,33,39,50}};
    search(matrix,4,4);
    return 0;
}