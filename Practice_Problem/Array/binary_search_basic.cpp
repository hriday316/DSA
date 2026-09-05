#include<iostream>
using namespace std;

int binarySearch(int *arr, int n, int key){
    int st = 0;
    int end = n-1;
    int mid;
    while(st <= end){
        mid = (end + st) /2;
        cout << mid <<" " << arr[mid] << endl;

        if (arr[mid] == key){
            cout << '\n' << "key " << mid<<endl;
            return 1; 
        }
        if(arr[mid] <key){
            st = mid++;
            cout << "++" << endl;
        }
        if(arr[mid] > key){
            end = mid--;
            cout << "--" << endl;
        } 
    }
    return -1;

}

int main(){
    int arr[13] = {25,28,30,45,76,80,82,83,87,88,90,91,98};
    int n = sizeof(arr)/sizeof(int);
    int key = 83;
  cout <<  binarySearch(arr, n,key)<< endl;


    return 0;
}