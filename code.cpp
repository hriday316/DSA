#include <iostream>
using namespace std;

void marge(int *arr, int st, int mid, int end){
   vector<int> temp;
   int i = st;
   int j = mid +1;

   while(i <= mid && j<=end){
      if(arr[i]<= arr[j]){
         temp.push_back(arr[i]);
         i++;
      }else{
         temp.push_back(arr[j]);
         j++;
      }
   }

   while(i<=mid){
      temp.push_back(arr[i]);
      i++;
   }

   while(j<=end){
      temp.push_back(arr[j]);
      j++;
   }

   for(int idx= st,  x = 0; idx<=end; idx++){
      arr[idx] = temp[x];
      x++;
   }
}

void margeSort(int *arr, int st, int end){
   if(st >= end){
      return;
   }
   int mid = st + (end - st)/2;

   margeSort(arr, st, mid);
   margeSort(arr, mid+1, end);

   marge(arr, st , mid, end);


}

void print(int *arr, int n){
   for(int i= 0; i<n; i++ ){
      cout << arr[i] << " ";
   }
   cout << endl;
}
 
int main()
{
   int arr[] = {6,3,7,5,2,4};
   int n = sizeof(arr)/sizeof(int);

   margeSort(arr, 0, n-1);
   print(arr,n);
    
   
   return 0;
}

// clang++ code.cpp -o a.out && ./a.out
