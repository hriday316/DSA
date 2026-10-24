#include<iostream>
#include<vector>
using namespace std;

bool compare(pair<double,int> p1, pair<double,int> p2){
   return p1.first > p2.first; // > means descending order sorting ;
}

int fractionalKnapsack(vector<int> val, vector<int> wt, int w){
   int size = val.size();
   // create pair of ration and index
   vector<pair<double,int>> ratio(size, make_pair(0.0,0)); //pair (ratio, idx) -> (double,idx)

   // calculate ratio and make pair ration and index
   for(int i = 0; i<size; i++){
      double r = val[i] / (double) wt[i];
      ratio[i] = make_pair(r,i);
   }

   // sort the ratio descending order
   sort(ratio.begin(), ratio.end(), compare);

   int ans = 0;

   for(int i=0; i<size; i++){
      int idx = ratio[i].second; 
      if(wt[idx] <= w){
         ans += val[idx];
         w -= wt[idx];
      }else{
         ans += (ratio[i].first * w);
         w = 0;
         break;
      }
   }

   cout << "max value " << ans << endl;
   return ans;



 }


int main(){
    vector<int>  val = {60,100,120};
    vector<int>  wt = {10,20,30};
    int w = 50;

    fractionalKnapsack(val, wt, w);


    return 0;
}

// clang++ code.cpp -o a.out && ./a.out
