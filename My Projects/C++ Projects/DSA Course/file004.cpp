#include <iostream>
#include <vector>
using namespace std;

// vector<int> ifTwoSuminSortedArray(vector<int>& nums, int k)
// {
//     int n = nums.size();
//     int first = 0;
//     int last = n-1;
//     vector<int> ans;

//     while (first < last)
//     {
//         if (nums[first] + nums[last] == k)
//         {
//             ans.push_back(first);
//             ans.push_back(last);
//             return ans;
//         }

//         else if (nums[first] + nums[last] > k)
//         {
//             last--;
//         }

//         else
//         {
//             first++;
//         }
//     }
// }

int majorityElement(vector<int>& nums)
{
    int n = nums.size();
    int freq = 0;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (freq == 0)
        {
            ans = nums[i];
        }

        if (ans == nums[i])
        {
            freq++;
        }

        else
        {
            freq--;
        }
    }

    return ans;
}

int main()
{
    // vector<int> nums = {1, 2, 3, 4, 5, 6};
    // int k = 7;

    // vector<int> ans = ifTwoSuminSortedArray(nums, k);
    // cout << ans[0] << "," << ans[1];

    vector<int> nums = {1, 2, 1, 2, 1, 5, 1};
    cout << majorityElement(nums);

    return 0;
}