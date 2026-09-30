#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector <int> vec = {2,7,11,15};
    int target = 18;
    int st = 0;
    int end = vec.size() -1;
    int arrSum = 0;

     while (st < end)
     {
         arrSum = vec[st] + vec[end];

         if(arrSum == target){
            
            cout << vec[st] << " " << vec[end] << endl;
            return 0;
         }

         if(arrSum < target){
            st++;
         };

         if(arrSum > target){
            end--;
         }

     }
     


    // berout force approach
    // for (int i = 0; i < vec.size(); i++)
    // {
    //       for(int j = i +1 ; j < vec.size(); j++){
    //           int  sum = vec[i] + vec[j];
    //             if(sum == target){
    //                 cout << vec[i]<< " " << vec[j];
    //             }
    //       }
    // }
    
    cout << endl;
    return 0;
}


