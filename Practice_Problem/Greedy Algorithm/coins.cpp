#include<iostream>
#include<vector>
using namespace std;

int  getMinChange(vector<int> coins, int  val){
        sort(coins.begin(),coins.end());
        int ans = 0;
        int size = coins.size() ;


        for(  int i = size-1; i>=0 && val > 0 ; i--){
            if(coins[i]<=val){
                ans += val/coins[i];
                val = val%coins[i];
            }
        }

        cout << "ans " << ans <<endl;
        return ans;

}
 

int main(){
    vector<int>  coins = {1,2,5,2000,50,10,500,100,20};
    int val = 599;
     getMinChange(coins,val);

    return 0;
}