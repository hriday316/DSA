#include <iostream>
using namespace std;

//question

/*
Question 2 : For a given integer array of size N. You have to find all the occurrences
(indices) of a given element (Key) and print them.
Use a recursive function to solve this problem.

Sample Input : arr[ ] = {3, 2, 4, 5, 6, 2, 7, 2, 2}, key = 2
Sample Output : 1 5 7 8

*/ 


void allOccurences(int i, int n, int *arr, int key)
{
   if (i == n)
   {
      return;
   }

   if (arr[i] == key)
   {
      cout << i << " ";
      allOccurences(i + 1, n, arr, key);
   }
   allOccurences(i + 1, n, arr, key);
}

int main()
{
   int arr[] = {3, 2, 4, 5, 6, 2, 7, 2, 2};
   int n = sizeof(arr) / sizeof(int);
   int key = 2;
   allOccurences(0, n, arr, key);
   return 0;
}