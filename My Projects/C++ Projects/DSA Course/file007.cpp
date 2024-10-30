#include <iostream>
#include <vector>
using namespace std;


vector<int> productOfArrayExceptSelf(vector<int> x)
{
    vector<int> y;
    int n = x.size();

    // int product = 1;

    // for (int i = 0; i < n; i++)
    // {
    //     product = 1;
        
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (j != i)
    //         {
    //             product *= x[j];
    //         }
    //     }

    //     y.push_back(product);
    // }


    // int prefix = 1;
    // int suffix = x[n-1];

    // for (int i = 0; i < n; i++)
    // {
    //     y.push_back(prefix);
    //     prefix *= x[i];
    // }

    // for (int i = n-2; i >= 0; i--)
    // {
    //     y[i] *= suffix;
    //     suffix *= x[i];
    // }

    return y;
}


int main()
{
    vector<int> x = {3, 2, 1, 6, 2};
    vector<int> y = productOfArrayExceptSelf(x);

    for (int i = 0; i < y.size(); i++)
    {
        cout << y[i] << " ";
    }

    return 0;
}