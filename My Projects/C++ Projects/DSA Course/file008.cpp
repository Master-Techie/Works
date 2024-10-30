#include <iostream>
using namespace std;


void change_a(int* ptr)
{
    *ptr = 20;
}


void change_a_again(int &b)
{
    b = 30;
}


int main()
{
    // int a = 10;
    // cout << &a << " ";

    // int* ptr = &a;
    // cout << ptr << " ";
    // cout << &ptr << " ";

    // int** ptr2 = &ptr;
    // cout << ptr2 << " ";
    // cout << &ptr << " ";

    // int* ptrNULL = NULL;

    // int a = 10;
    // change_a(&a);
    // cout << a << " ";
    // change_a_again(a);
    // cout << a << " ";

    // int arr[] = {1, 2, 3, 4, 5};
    // cout << arr;

    return 0;
}