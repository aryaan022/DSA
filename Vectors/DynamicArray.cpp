#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int size;
    cin >> size;
    int* arr = new int[size]; // Dynamic array allocation
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    delete[] arr; // Free the dynamically allocated memory
    return 0;
}