#include<iostream>
using namespace std;


void SortedMatrix(int mat[][4],int n,int m,int key=65){
    for(int i=0;i<n;i++){
        int low=0;
        int high=m-1;
        while(low<=high){
            int mid= low+(high-low)/2;
            if(key == mat[i][mid]){
                cout<<"Key found at position [" <<i<<"]["<<mid<<"]"<<endl;
                return;
            }
            else if(key>mat[i][mid]){
                low =mid+1;
            }
            else if(key<mat[i][mid]){
                high =mid-1;
            }
            
        }
    }
        cout<<"KEy not found";
    
}

int main(){
    int matri[4][4]={{10,20,30,40},{15,25,35,45},{27,29,37,48},{32,33,39,50}};
    SortedMatrix(matri,4,4);
    
    return 0;
}