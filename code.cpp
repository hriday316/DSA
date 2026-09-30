#include <iostream>
using namespace std;

 

void print(int *arr, int n){
   for(int i= 0; i<n; i++ ){
      cout << arr[i] << " ";
   }
   cout << endl;
}

int partition(int *arr, int st, int end){
   int i = st -1;
   int pivot = arr[end];

   for(int j = st; j < end; j++){
      if(arr[j] <= pivot){
         i++;
         swap(arr[i], arr[j]);
      }
   }

   i++;
   swap(arr[i],arr[end]);

   return i;


}

void quickSort(int *arr, int st, int end){

   if(st >= end) return;

   int pivotIdx = partition(arr,st,end);

   quickSort(arr,st, pivotIdx-1); //left half
   quickSort(arr, pivotIdx+1, end); //right half
}
 
int main()
{
   int arr[] = {6,3,7,5,2,4};
   int n = sizeof(arr)/sizeof(int);
   int st = 0;
   int end = n ;

   quickSort(arr,st,end);
   print(arr,n);
  
   return 0;
}

// clang++ code.cpp -o a.out && ./a.out
