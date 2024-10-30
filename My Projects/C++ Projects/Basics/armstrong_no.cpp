#include <iostream>
#include <math.h>
using namespace std;

// To find whether a number is an armstrong number or not

int main(){
    int n;
    cout << "Number : ";
    cin >> n;
    int m = n;
    int s = 0;

    while (m>0) {
        int r = m%10;
        s += pow(r,3);
        m /= 10;
    }

    if (n == s) {
        cout << n << " is an Armstrong number.\n\n";
    }

    else {
        cout << n << " is not an Armstrong number.\n\n";
    }
    
    return 0;
}