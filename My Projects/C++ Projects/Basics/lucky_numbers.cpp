#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> nums{};
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        nums.push_back(i);
    }

    int s = 1;

    while (s <= nums.size()) {
        for (int i = s; i < nums.size(); i+= s) {
            nums.erase(nums.begin()+i);
        }
        s++;
    }

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }

    return 0;
}