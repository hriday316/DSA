 #include<iostream>
#include<vector>
using namespace std;

bool compare (pair<int, int> A, pair<int, int> B){
   return A.second < B.second;
}

int lengthChain(vector<int> A, vector<int>B){
   int size = A.size();
   vector<pair<int,int>> pairs (size, make_pair(0,0));

   for (int i = 0; i < size; i++)
   {
      pairs[i] = make_pair(A[i],B[i]);
   }

   sort(pairs.begin(),pairs.end(), compare);

   int count = 1; 
   int end = pairs[0].second;

   for(int i=1; i<size;i++){
      cout << pairs[i].first << " " << pairs[i].second << endl;
      if(pairs[i].first > end){
         count ++;
         end = pairs[i].second;
      }
   }

   cout << "max length chain of pairs = " << count << endl;
   return count;
   
};
 

int main(){
    vector<int>  A = {5,39,5,27,50};
    vector<int>  B = {24,60,28,40,90};
 
    
   lengthChain(A,B);

    return 0;
}

// clang++ code.cpp -o a.out && ./a.out