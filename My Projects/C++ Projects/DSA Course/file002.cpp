#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums)
{
    int t = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        t ^= nums[i];
    }

    return t;
}

int main()
{
    // vector<int> vec1; // vec1 = []
    // vector<int> vec2 = {1, 2, 3}; // vec2 = [1, 2, 3]
    // vector<int> vec3(3,0); // vec3 = [0, 0, 0]

    // cout << vec3[2];

    // vector<char> alphabets = {'a', 'b', 'c'};

    // alphabets.push_back('d');
    // for (char i : alphabets) {cout << i << "\n";}

    // alphabets.pop_back();
    // for (char i : alphabets) {cout << i << "\n";}

    // cout << alphabets.front() << "\n" << alphabets.back() << "\n" << alphabets.at(1);

    // vec1.push_back(0);
    // vec1.push_back(1);
    // vec1.push_back(2);

    // cout << vec1.size() << " " << vec1.capacity();

    vector<int> vec = {1, 5, 1, 3, 5};
    cout << singleNumber(vec);

    return 0;
}