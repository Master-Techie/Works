#include <iostream>
using namespace std;

// To calculate the value of C(n,r)

int C(int n,int r){
    int c = 1;

    if (r > (n/2)) {
        r = (n-r);
    }

    for (int i = 1; i <= r; i++) {
        c *= (n+1-i);
        c /= i;
    }

    return c;
}

int main(){
    int n;
    int r;
    cout << "n : ";
    cin >> n;
    cout << "r : ";
    cin >> r;

    int c = C(n,r);

    cout << "\nC(" << n << "," << r << ") = " << c << "\n\n";

    return 0;
}