#include <iostream>
#include <vector>
using namespace std;

vector<int> pairSum(vector<int> nums, int target)
{
    vector<int> ans;
    int n = nums.size();

    // approach 01
    // for(int i = 0; i<n; i++){
    //     for(int j= i+1; j<n; j++){
    //         if(nums[i]+nums[j] == target){
    //             ans.push_back(i);
    //             ans.push_back(j);
    //             return ans;
    //         }
    //     }
    // }

    // approach 02 better one

    int i = 0, j = n - 1;
    while (i < j)
    {
        int pairSum = nums[i] + nums[j];
        if (pairSum < target)
        {
            i++;
        }
        else if (pairSum > target)
        {
            j--;
        }
        else
        {
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 26;
    vector<int> ans = pairSum(nums, target);

    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}