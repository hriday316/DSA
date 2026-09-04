 #include "iostream"
 #include "vector"
 using namespace std;

// problem no 169. solved it using Boyer-Moore Majority Voting Algorithm

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int freq = 0 , ans= 0;
        int n = nums.size();

        for(int i = 0; i<n; i++){
            if(freq==0){
                ans = nums[i];
            }

            if(ans == nums[i]){
                freq++;
            }else{
                freq--;
            }
        }
        return ans;
    } 
    
};
 