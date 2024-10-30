#include <iostream>
#include <vector>
using namespace std;


int binarySearchIterative(vector<int> x, int c)
{
    int start = 0;
    int end = x.size() - 1;
    int mid;

    while (start <= end)
    {
        mid = start + ((end - start) / 2);

        if (x[mid] == c)
        {
            return mid;
        }

        else if (x[mid] > c)
        {
            end = mid - 1;
        }

        else if (x[mid] < c)
        {
            start = mid + 1;
        }
    }

    return -1;
}


int binarySearchRecursive(vector<int> x, int c, int start, int end)
{
    if (start <= end)
    {
        int mid = start + ((end - start) / 2);

        if (x[mid] < c)
        {
            return binarySearchRecursive(x, c, mid+1, end);
        }

        else if (x[mid] > c)
        {
            return binarySearchRecursive(x, c, start, mid-1);
        }

        else
        {
            return mid;
        }
    }

    return -1;
}


int main()
{
    vector<int> nums = {1, 5, 7, 11, 24, 57};
    cout << binarySearchIterative(nums, 24);
    cout << binarySearchRecursive(nums, 11, 0, nums.size()-1);

    return 0;
}