#include<iostream>
using namespace std;

int main(){
    int arr[5] ={1,2,3,4,5};
    int n = sizeof(arr) / sizeof(int);
   
     
    for(int i=0; i<n; i++){ //
        for(int j = i  ;  j <n ; j++){
            for(int z = i ; z<= j ; z++){
            cout << arr[z] << ",";
            }
            cout << "  " ;
        }
        cout << endl;
    }

    return 0;
}