#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    int n = nums.size();

    int currSum = 0;
    int max_sum = INT32_MIN;

    // for (int i = 0; i < n; i++) {
    //     int curr_sum = 0;
    //     for (int j = i; j < n; j++) {
    //         curr_sum += nums[j];
    //         max_sum = max(curr_sum, max_sum);
    //     }
    // }

    // cout << max_sum;

    for (int i = 0; i < n; i++) {
        currSum += nums[i];
        max_sum = max(max_sum, currSum);

        if (currSum < 0) {
            currSum = 0;
        }
    }

    return 0;
}