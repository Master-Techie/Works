#include <iostream>
using namespace std;

void reverseArray(int arr[], int size)
{
    for (int i = 0; i < (size+1)/2; i++)
    {
        swap(arr[i], arr[size-1-i]);
    }
}

int main()
{
    int marks[5] = {1, 2, 3, 4, 5};
    int nums[6] = {1, 2, 3, 4, 5, 6};

    reverseArray(marks, 5);
    reverseArray(nums, 6);

    for (int i = 0; i < 5; i++) {cout << marks[i] << " ";}
    cout << "\n";
    for (int i = 0; i < 6; i++) {cout << nums[i] << " ";}

    return 0;
}
