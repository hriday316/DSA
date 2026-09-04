#include<iostream>
using namespace std;

//reverse array without extra Space
void printArr(int *arr, int n){
    int start = 0;
    int end = n-1;

    while(start < end){
        
       int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start ++;
        end --;
    }

    for(int i=0; i<n; i++){
        cout<< arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[6]={0,1,2,3,4,5};
    int n = sizeof(arr)/sizeof(int);

    printArr(arr,n);

    return 0;
}

//run command 
//clang++ reverse_array.cpp -o ./exe/reverse_array.exe && ./exe/reverse_array.exe