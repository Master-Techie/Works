#include <iostream>
#include <vector>
using namespace std;

int peakIndexInMountainArray(vector<int> x)
{
    // Method 1 [Linear Search]
    // for (int i = 1; i < x.size()-1; i++)
    // {
    //     if ((x[i] > x[i-1]) && (x[i] > x[i+1]))
    //     {
    //         return i;
    //     }
    // }

    //Method 2 [Binary Search]
    int start = 1;
    int n = x.size();
    int end = n-2;

    while (start <= end)
    {
        int mid = start + (end-start)/2;

        if (x[mid] > x[mid-1] && x[mid] > x[mid+1])
        {
            return mid;
        }

        else if (x[mid] < x[mid-1] && x[mid] > x[mid+1])
        {
            end = mid - 1;
        }

        else if (x[mid] > x[mid-1] && x[mid] < x[mid+1])
        {
            start = mid + 1;
        }
    }
}


int main()
{
    vector<int> arr = {0, 3, 8, 9, 5, 2};
    int a = peakIndexInMountainArray(arr);

    cout << a;

    return 0;
}