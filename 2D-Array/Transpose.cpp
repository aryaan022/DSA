#include<iostream>
using namespace std;
void Print(int mat[][2], int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void Transpose(int mat1[][3],int n ,int m){
    int mat2[m][n];
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            mat2[j][i]=mat1[i][j];
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << mat2[i][j] << " ";
        }
        cout << endl;
    }
    
}


int main(){
    int matrix1[2][3]={{1,2,3},{4,5,6}};
    Transpose(matrix1,2,3);
    return 0;
}