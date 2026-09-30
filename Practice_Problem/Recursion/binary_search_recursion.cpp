#include <iostream>
using namespace std;

//normal search
int search(int i, int n,  int arr[],int key){
   if (i == n-1){
      return -1;
   };
   if(arr[i] == key){
      return i;
   }else{
    return  search(i+1,n,arr,key);
   }
}

// solved using binary search
int binarySearch(int st, int end, int *arr, int key){

   if(st > end){
      return -1;
   }

   int mid = (st + end)/2;
   if(arr[mid] == key){
      return mid;
   }else if(arr[mid]> key){
      end = mid;
      return binarySearch(st,end,arr,key);
   }else{
      st= mid;
      return binarySearch(st,end,arr,key);
   }
}

int main()
{
   int arr[] = {1,2,3,4,5,6,7};
   int n = sizeof(arr)/sizeof(int);
    
     
   cout <<  search(0,n,arr,5)<<endl;
   cout << binarySearch(0,n-1,arr,5) <<endl;

    return 0;
}