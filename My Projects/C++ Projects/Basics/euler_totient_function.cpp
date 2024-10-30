#include <iostream>
using namespace std;

int totient_func(int n){
    int c = 1;

    for (int i = 2; i < n; i++) {
        if (n%i != 0) {c += 1;}
    }

    return c;
}

int main(){
    int n = 5;
    // cout << "n : ";
    // cin >> n;
 
    int phi = totient_func(n);
    cout << "Totient value of " << n << " is " << phi << "\n";

    return 0;
}